#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <QMainWindow>
#include <iostream>
#include "vector.hpp"
#include "material.hpp"
#include "placment.hpp"
#include <QTimer>

namespace FP { namespace sphere {
using namespace FP::vector;
using namespace FP::material;

class Sphere
{
private:
    double radius;
    Material* material;
    Vector* center;
    struct
    {
        //const double omega = 7.292e-5; // Стандарт
        //const double omega = 0.01; // Ускорение Земли -- линии
        //const double omega = 0.03; // Ускорение Земли -- тр-ки
        double omega;
        double omega_z;
        double omega_0;
        double gl;
        double _omega_;
        double omega_minus;
        double omega_plus;
        double phi = 90; // Северный полюс по умолчанию
    }place;
    bool acceleration = false;
private:
    double xt(long long t, double x0)
    {
        return 9.0/20 * x0 * cos(22.0/99 * t) + 11.0/20 * x0 * cos(18.0/99 * t);
    }
    double yt(long long t, double x0)
    {
        return -9.0/20 * x0 * sin(22.0/99 * t) + 11.0/20 * x0 * sin(18.0/99 * t);
    }

    double x_new(long double t, double x0)
    {
        return x0*place.omega_minus/(2.0*place._omega_) * cos(place.omega_plus*t) +\
               x0*place.omega_plus/(2.0*place._omega_) * cos(place.omega_minus*t);
    }
    double y_new(long double t, double x0)
    {
        return -x0*place.omega_minus/(2.0*place._omega_) * sin(place.omega_plus*t) +\
               x0*place.omega_plus/(2.0*place._omega_) * sin(place.omega_minus*t);
    }

public:
    Sphere()
    {
        radius = 10;
        center = new Vector();
        material = new Material(Color(0, 0, 0), Vector(), 1.5);
    }
    Sphere(double r, double x, double y, double z, Color diffCol,
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

    void set_place(int latitude)
    {
        place.phi = latitude;
        place.omega_z = place.omega * sin(place.phi);
        place.gl = 10.0 / 50.0;
        place.omega_0 = sqrt(place.gl);
        place._omega_ = sqrt(place.omega_0*place.omega_0 + place.omega_z*place.omega_z);
        place.omega_minus = place._omega_ - place.omega_z;
        place.omega_plus = place._omega_ + place.omega_z;
    }
    void set_acceleration(bool a)
    {
        acceleration = a;
        if (acceleration)
            place.omega = 0.04;
        else
            place.omega = 7.292e-5;
    }

    int get_radius(void) { return radius; }

    Material *get_material() const;
    void get_material(Color &difCol, Vector &alb, double &spec) const;

    void moving(long double time_sim);

    bool ray_intersect(const Vector &orig, const Vector &dir,
                       double &t0) const;
};

} }

#endif // SPHERE_HPP
