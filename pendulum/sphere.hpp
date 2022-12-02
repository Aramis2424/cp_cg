#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <QMainWindow>
#include <iostream>
#include "vector.hpp"
#include "material.hpp"
#include <QTimer>

namespace FP { namespace sphere {
using namespace FP::vector;
using namespace FP::material;

class Sphere
{
private:
    int radius;
    Material* material;
    Vector* center;
public:
    Sphere()
    {
        radius = 10;
        center = new Vector();
        material = new Material(Color(0, 0, 0), Vector(), 1.5);
    }
    Sphere(int r, double x, double y, double z, Color diffCol,
           Vector alb, double s_e)
    {
        radius = r;
        center = new Vector(x, y, z);
        material = new Material(diffCol, alb, s_e);
    }
    ~Sphere()
    {
        delete material;
        delete center;
    }

    void set_center(double x, double y, double z);
    void get_center(double &x, double &y, double &z) const;

    int get_radius(void) { return radius; }

    Material *get_material() const;
    void get_material(Color &difCol, Vector &alb, double &spec) const;

    void moving(long long time_sim);

    bool ray_intersect(const Vector &orig, const Vector &dir,
                       double &t0) const;
};

} }

#endif // SPHERE_HPP
