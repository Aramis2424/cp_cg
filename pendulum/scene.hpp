#ifndef SCENE_HPP
#define SCENE_HPP

#include <QGraphicsScene>
#include <QImage>
#include <vector>
#include "color.hpp"
#include "vector.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "constants.hpp"

namespace FP { namespace scene {
using namespace FP::color;
using namespace FP::vector;
using namespace FP::sphere;
using namespace FP::camera;
using namespace FP::light;

class Scene : public QGraphicsScene
{
private:
    int _width;
    int _height;
    Sphere* sphere;
    Camera* camera;
    Light* light_1;
    Light* light_2;
    std::vector<Light> lights;

    QGraphicsLineItem* pixelLine;
    QImage* img;

    long double time_simulation;
    std::vector<std::pair<double, double>> trajectory;
    bool isTrajectory = false;

private:
    double xSceneCoords(int x)
    {
       return ((2*x + 1) / (float)_width  - 1) *
                            _width/(float)_height * camera->fovKoeff();
    }
    double ySceneCoords(int y)
    {
        return -((2*y + 1) / (float)_height - 1) *
                            camera->fovKoeff();
    }

    int xWorldCoords(double x)
    {
        return static_cast<int>((x * _height -
                                 camera->fovKoeff() * (1 - _width)) /
                                (2 * camera->fovKoeff())
                               );
    }

    int yWorldCoords(double y)
    {
        return static_cast<int>(
                    ((_height - 1) * camera->fovKoeff() - _height * y) /
                     (2 * camera->fovKoeff())
                               );
    }

    Vector sceneReflect(const Vector &I, const Vector &N)
    {
        return I - N * 2.0 * I.scalar(N);
    }
public:
    Scene() : QGraphicsScene()
    {
        _width = WIDTH;
        _height = HEIGHT;
        sphere = new Sphere(sr, sx0, sy0, sz0, sdiffCol, salb, sspec_exp);
        camera = new Camera(cx0, cy0, cz0);
        light_1 = new Light(lx1, ly1, lz1, lintens1);
        light_2 = new Light(lx2, ly2, lz2, lintens2);
        lights.push_back(*light_1);
        lights.push_back(*light_2);
        img = new QImage(_width, _height, QImage::Format_RGB32);
        time_simulation = 0;
    }
    ~Scene()
    {
        delete light_1;
        delete light_2;
        delete camera;
        delete sphere;
        delete img;
    }

    bool ray_tracing(const Vector* orig, const Vector dir,
                     const Sphere* sphere, Color* const col,
                     const std::vector<Light> lights, size_t depth, const int type);

    bool scene_intersect(const Vector *orig, const Vector dir,
                         const Sphere *sphere,
                         Vector &hit, Vector &N, Material &material);

    void draw_pix(double x, double y, Color col);

    void set_place(int latitude)
    { sphere->set_place(latitude); }
    void set_acceleration(bool a)
    { sphere->set_acceleration(a); }
    void set_trajectory(bool a)
    {  isTrajectory = a; }

    void reset_scene()
    {
        if (trajectory.size() > 1) // Сброс траектории
            trajectory.clear();

        time_simulation = 0; // Сброс времени выполнения

        delete sphere; // Создание новой сферы
        sphere = new Sphere(sr, sx0, sy0, sz0, sdiffCol, salb, sspec_exp);
    }

    void render();
    void draw_background();
    void draw_pendulum_thread();
    void add_trajectory();
    void draw_trajectory();










    bool plane_intersect(const Vector* orig, const Vector dir,
                                const Sphere* sphere, Vector &hit,
                                Vector &N, Material &material);
};

} }

#endif // SCENE_HPP
