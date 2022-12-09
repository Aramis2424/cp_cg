#include "scene.hpp"

namespace FP { namespace scene {

bool Scene::scene_intersect(const Vector* orig, const Vector dir,
                            const Sphere* sphere, Vector &hit,
                            Vector &N, Material &material)
{
    double spheres_dist = std::numeric_limits<double>::max();
    double dist_i;
    if (sphere->ray_intersect(*orig, dir, dist_i) && dist_i < spheres_dist)
    {
        spheres_dist = dist_i;
        hit = *orig + dir*dist_i;

        double x, y, z;
        sphere->get_center(x, y, z);
        Vector tmp(x, y, z);

        N = (hit - tmp).normalize();

        material = *sphere->get_material();
    }

    double checkerboard_dist = std::numeric_limits<double>::max();
    double origX, origY, origZ; orig->get_vec(origX, origY, origZ);
    double dirX, dirY, dirZ; dir.get_vec(dirX, dirY, dirZ);

    material = *sphere->get_material();
    Color diffuse_color = material.get_diffuse();
    Vector albedo = material.get_albedo();
    double spec = material.get_spec_exp();

    if (fabs(dirY)>1e-5)
    {
        float d = -(origY+4)/dirY; // координата y плоскости: y = -4
        Vector pt = *orig + dir*d;
        double ptX, ptY, ptZ; pt.get_vec(ptX, ptY, ptZ);
        if (d > 0 && fabs(ptX) < 10 && ptZ < -10 && ptZ > -30 && d < spheres_dist)
        {
            checkerboard_dist = d;
            hit = pt;
            N = Vector(0,1,0);
            diffuse_color = (int(0.5*ptX+1000) + int(0.5*ptZ)) & 1 ?
                        Color(0.3, 0.3, 0.3) : Color(0.3, 0.21, 0.9);
                        //Color(0.4, 0.47, 0.2) : Color(0.3, 0.21, 0.9);  // зел
                        //Color(0, 0, 0) : Color(1, 1, 1);  //   ч\б
            material = Material(diffuse_color, albedo, spec);
        }
    }
    return std::min(spheres_dist, checkerboard_dist)<1000;
}

bool Scene::ray_tracing(const Vector* orig, const Vector dir,
                        const Sphere* sphere, Color* const col,
                        const std::vector<Light> lights, size_t depth = 0,
                        const int type = 0)
{
    Vector point, N;

    Material material;
    Color difCol;
    Vector albedo;
    double spectrum, lAlb, cAlb, rAlb;

    if (depth > DEPTH_REFLECT ||
            !scene_intersect(orig, dir, sphere, point, N, material))
        return false;

    material.get_material(difCol, albedo, spectrum);
    albedo.get_vec(lAlb, cAlb, rAlb);

    Vector reflect_dir = sceneReflect(dir, N).normalize();
    Color reflect_color;
    // небольшой сдвиг для корректной работы
    Vector reflect_orig = reflect_dir.scalar(N) < 0 ?
                point - N*1e-3 : point + N*1e-3;
    bool isObject = ray_tracing(&reflect_orig, reflect_dir,
                                   sphere, &reflect_color, lights, depth + 1);
    if (!isObject)
    {
        rAlb = 0.45;
        reflect_color = BACKGROUND_COLOR;
    }

    double diffuse_light_intensity = 0, specular_light_intensity = 0;
    for (size_t i = 0; i < lights.size(); i++)
    {
        Vector light_dir = (lights[i] - point).normalize();

        // Тень
        float light_distance = (lights[i] - point).len();
        // если точка лежит в тени источника lights[i]
        Vector shadow_orig = light_dir.scalar(N) < 0 ?
                    point - N * 1e-3 : point + N * 1e-3;
        Vector shadow_pt, shadow_N;
        Material tmpmaterial;
        if (scene_intersect(&shadow_orig, light_dir, sphere,                                                // тут можно заменить на 111
                            shadow_pt, shadow_N, tmpmaterial) &&
                (shadow_pt-shadow_orig).len() < light_distance)
            continue;

        diffuse_light_intensity  += (lights[i].get_intensity() *
                std::max(0.01, light_dir.scalar(N)));

        specular_light_intensity +=
                powf(std::max(0.01, sceneReflect(light_dir, N).scalar(dir)),
                     spectrum) * lights[i].get_intensity();
    }

    Vector tmp = difCol * diffuse_light_intensity * lAlb +
            Vector(1.0, 1.0, 1.0) * specular_light_intensity * cAlb +
            reflect_color * rAlb;

    double x, y, z;
    tmp.get_vec(x, y, z);
    col->set(x, y, z);

    if (type == 1)
    {
        double sphere_dist = std::numeric_limits<double>::max();
        if (!sphere->ray_intersect(*orig, dir, sphere_dist) && depth == 0)
            return false;
    }

    return true;
}

void Scene::render()
{   
    Vector dir;
    Color color = BACKGROUND_COLOR;
    sphere->moving(time_simulation);
    time_simulation += 0.15;

    this->draw_background();
    this->draw_pendulum_thread();

    // Плоскость
    #pragma omp parallel for num_threads(8) private(dir, color)
    for (int j = _height / 2; j < _height - 100; j++)
        for (int i = 2; i < _width - 2; i++)
        {
            double x = xSceneCoords(i);
            double y = ySceneCoords(j);

            dir.set_vec(x, y, -1);
            dir.normalize();

            if (!ray_tracing(camera, dir, sphere, &color, lights))
                continue;

            draw_pix(i, j, color);
        }

    this->add_trajectory();
    if (isTrajectory)
        this->draw_trajectory();

    // Сфера
    double centerX, centerY, centerZ;
    sphere->get_center(centerX, centerY, centerZ);
    int j_end = yWorldCoords((centerY - 3*sphere->get_radius()) * -1/centerZ);
    int j_start = yWorldCoords((centerY + 3*sphere->get_radius()) * -1/centerZ);
    int i_start = xWorldCoords((centerX - 3*sphere->get_radius()) * -1/centerZ);
    int i_end = xWorldCoords((centerX + 3*sphere->get_radius()) * -1/centerZ);
    #pragma omp parallel for num_threads(8) private(dir, color)
    for (int j = j_start; j < j_end; j++)
        for (int i = i_start; i < i_end; i++)
        {
            double x = xSceneCoords(i);
            double y = ySceneCoords(j);

            dir.set_vec(x, y, -1);
            dir.normalize();

            if (!ray_tracing(camera, dir, sphere, &color, lights, 0, 1))
                continue;

            draw_pix(i, j, color);
        }

    this->addPixmap(QPixmap::fromImage(*img));
}

void Scene::draw_pix(double x, double y, Color col)
{
    QRgb rgbCol = col.qrgbColor();
    int intX = round(x);
    int intY = round(y);
    img->setPixel(intX, intY, rgbCol);
}

void Scene::draw_background()
{
    Color bgCol = BACKGROUND_COLOR;
    QRgb rgbBgCol = bgCol.qrgbColor();
    this->clear();
    img->fill(rgbBgCol);
}

void Scene::draw_pendulum_thread()
{
    QPainter painter;
    painter.begin(img);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    double centerX, centerY, centerZ;
    sphere->get_center(centerX, centerY, centerZ);
    double x = centerX * -1/centerZ;
    double y = (centerY - sphere->get_radius()) * -1/centerZ;

    painter.drawLine(xWorldCoords(0), yWorldCoords(8),
                     xWorldCoords(x), yWorldCoords(y));

    painter.end();
}

void Scene::add_trajectory()
{
    double centerX, centerY, centerZ;
    sphere->get_center(centerX, centerY, centerZ);
    double x = centerX * -1/centerZ;
    double y = (centerY - 2*sphere->get_radius() - 4) * -1/centerZ;
    trajectory.push_back(std::pair<double, double>(x, y));

    if (trajectory.size() > 1)
        if (
                (abs(x - trajectory[0].first) < 1e-5) &&
                (abs(y - trajectory[0].second) < 1e-5)
           )
        {
            trajectory.clear();
            return;
        }
}

void Scene::draw_trajectory()
{
    QPainter painter;
    painter.begin(img);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    if (trajectory.size() == 0)
        return;

    for (unsigned long long i = 0; i < trajectory.size() - 1; i++)
    {
        std::pair<double, double> cur = trajectory[i];
        std::pair<double, double> next = trajectory[i+1];

        painter.drawLine(xWorldCoords(cur.first), yWorldCoords(cur.second),
                         xWorldCoords(next.first), yWorldCoords(next.second));
    }

    painter.end();
}

} }
