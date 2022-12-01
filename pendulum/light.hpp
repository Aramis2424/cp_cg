#ifndef LIGHT_H
#define LIGHT_H

#include "vector.hpp"

namespace FP { namespace light {
using namespace FP::vector;

class Light : public Vector
{
private:
    double intensity;
public:
    Light()
    {
        set_vec(0, 0, 0);
        intensity = 0;
    }
    Light(double x, double y, double z, double intens)
    {
        set_vec(x, y, z);
        intensity = intens;
    }

    double get_intensity() const
    {
        return intensity;
    }
    Vector reflect(const Light &I, const Light &N) {
        return I - N*2.f*(I*N);
    }
};

} }

#endif // LIGHT_H
