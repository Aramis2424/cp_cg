#include <iostream>
#include <QPainter>

#include "scene.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "material.hpp"
#include "vector.hpp"


namespace FP { namespace scene {

void Scene::draw_pix(double x, double y, Color col)
{
    QRgb rgbCol = col.qrgbColor();
    int intX = round(x);
    int intY = round(y);
    img->setPixel(intX, intY, rgbCol);
}

bool Scene::scene_intersect(const Vector* orig, const Vector dir,
                            const Sphere* sphere, Vector &hit,
                            Vector &N, Material &material)
{
    double spheres_dist = std::numeric_limits<double>::max();

        double dist_i;
        if (sphere->ray_intersect(*orig, dir, dist_i) && dist_i < spheres_dist) {
            spheres_dist = dist_i;
            hit = *orig + dir*dist_i;

            double x, y, z;
            sphere->get_center(x, y, z);
            Vector tmp(x, y, z);

            N = (hit - tmp).normalize();

            material = *sphere->get_material();
        }

    //return spheres_dist < 1000;

    double checkerboard_dist = std::numeric_limits<double>::max();
    double origX, origY, origZ; orig->get_vec(origX, origY, origZ);
    double dirX, dirY, dirZ; dir.get_vec(dirX, dirY, dirZ);

//    Color t1; Vector t2; double t3; Vector diffuse_color;
//    sphere->get_material(t1, t2, t3);
//    diffuse_color = t1;
    material = *sphere->get_material();
    Color diffuse_color = material.get_diffuse();
    Vector albedo = material.get_albedo();
    double spec = material.get_spec_exp();

    if (fabs(dirY)>1e-3)
    {
        float d = -(origY+4)/dirY; // the checkerboard plane has equation y = -4
        Vector pt = *orig + dir*d;
        double ptX, ptY, ptZ; pt.get_vec(ptX, ptY, ptZ);
        if (d > 0 && fabs(ptX) < 10 && ptZ < -10 && ptZ > -30 && d < spheres_dist)
        {
            checkerboard_dist = d;
            hit = pt;
            N = Vector(0,1,0);
            //std::cout << ((int(.5*hitX+1000) + int(.5*hitZ)) & 1) << " ";
            diffuse_color = (int(0.5*ptX+1000) + int(0.5*ptZ)) & 1 ?
                        Color(0.3, 0.3, 0.3) : Color(0.3, 0.21, 0.9);
            //diffuse_color = diffuse_color * 0.3;
            material = Material(diffuse_color, albedo, spec);
            //material = Material(diffuse_color, Vector(1,0,0), 0);
        }
    }
    return std::min(spheres_dist, checkerboard_dist)<1000;
}

bool Scene::ray_tracing(const Vector* orig, const Vector dir,
                        const Sphere* sphere, Color* const col,
                        const std::vector<Light> lights, size_t depth = 0)
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

    /////////////////////////////////////////////--v
    Vector reflect_dir = sceneReflect(dir, N).normalize();
    Color reflect_color;
    // offset the original point to avoid occlusion by the object itself
    Vector reflect_orig = reflect_dir.scalar(N) < 0 ?
                point - N*1e-3 : point + N*1e-3;
    bool isObject = ray_tracing(&reflect_orig, reflect_dir,
                                   sphere, &reflect_color, lights, depth + 1);
    if (!isObject)
        reflect_color = BACKGROUND_COLOR;
    //////////////////////////////////////////////--^

    double diffuse_light_intensity = 0, specular_light_intensity = 0;
    for (size_t i = 0; i < lights.size(); i++)
    {
        Vector light_dir = (lights[i] - point).normalize();

        ////////////////////////////////////--v
        // shadow
        float light_distance = (lights[i] - point).len();
        // checking if the point lies in the shadow of the lights[i]
        Vector shadow_orig = light_dir.scalar(N) < 0 ?
                    point - N * 1e-3 : point + N * 1e-3;
        Vector shadow_pt, shadow_N;
        Material tmpmaterial;
        if (scene_intersect(&shadow_orig, light_dir, sphere,
                            shadow_pt, shadow_N, tmpmaterial) &&
                (shadow_pt-shadow_orig).len() < light_distance)
            continue;
        ////////////////////////////////////--^

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

    return true;
}

void Scene::render()
{   
    Vector dir;
    Color color = BACKGROUND_COLOR;
    sphere->moving(time_simulation);
    time_simulation += 0.2;

    this->draw_background();
    this->draw_pendulum_thread();

    #pragma omp parallel for num_threads(8) private(dir, color)
    for (int j = 0; j < _height; j++)
        for (int i = 0; i < _width; i++)
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
    this->addPixmap(QPixmap::fromImage(*img));
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

    painter.drawLine(xWorldCoords(0), yWorldCoords(7),
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

    for (unsigned long long i = 0; i < trajectory.size() - 1; i++)
    {
        std::pair<double, double> cur = trajectory[i];
        std::pair<double, double> next = trajectory[i+1];

//        if (cur.first <= (centerX + sphere->get_radius())-1/centerZ &&
//                cur.first >= (centerX - sphere->get_radius())*-1/centerZ &&
//                cur.second <= (centerY + 0*sphere->get_radius())-1/centerZ &&
//                cur.second >= (centerY - 2*sphere->get_radius())*-1/centerZ)
//            continue;

        painter.drawLine(xWorldCoords(cur.first), yWorldCoords(cur.second),
                         xWorldCoords(next.first), yWorldCoords(next.second));
    }

    painter.end();
}

} }
