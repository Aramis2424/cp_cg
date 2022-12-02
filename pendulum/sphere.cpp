#include "sphere.hpp"

namespace FP { namespace sphere {

void Sphere::set_center(double x, double y, double z)
{
    if (center)
        center->set_vec(x, y, z);
}

void Sphere::get_center(double &x, double &y, double &z) const
{
    center->get_vec(x, y, z);
}

Material* Sphere::get_material() const
{
    return this->material;
}

void Sphere::get_material(Color &difCol, Vector &alb, double &spec) const
{
    difCol = material->get_diffuse();
    alb = material->get_albedo();
    spec = material->get_spec_exp();
}

void Sphere::moving(long long time_sim)
{
    // get current coords
    double cur_x, cur_y, cur_z;
    get_center(cur_x, cur_y, cur_z);

    // new coords

    cur_x = xt(time_sim, 15);
    cur_z = yt(time_sim, 15) - 20;
    //std::cout << xt(time_sim, 10) << std::endl;
    //std::cout << 9/20 * 10 * cos(22/99 * time_sim) + 11/20 * 10 * cos(18/99 * time_sim) << std::endl;
    //std::cout << cos(18/99 * time_sim) << std::endl;
    //std::cout << "=======" << std::endl;
//    double dx = 0.2;
//    if (time_sim < 50)
//        cur_x -= dx;
//    else
//        cur_x += dx;

    //cur_z -= 0.5;
    //cur_x = 1;
    //cur_z = -25;

    set_center(cur_x, cur_y, cur_z);
}

bool Sphere::ray_intersect(const Vector &orig, const Vector &dir,
                           double &t0) const
    {
        Vector L = *center - orig;
        float tca = L.scalar(dir);
        float d2 = L.scalar(L) - tca*tca;

        if (d2 > radius*radius)
            return false;

        float thc = sqrtf(radius*radius - d2);
        t0 = tca - thc;
        float t1 = tca + thc;

        if (t0 < 0 && t1 < 0)
            return false;
        return true;
    }

} }
