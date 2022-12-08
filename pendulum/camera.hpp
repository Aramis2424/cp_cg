#ifndef CAMERA_H
#define CAMERA_H

#include "constants.hpp"

namespace FP { namespace camera {
using namespace FP::vector;

class Camera : public Vector
{
private:
    const float fov = FOV;
public:
    Camera()
    {
        set_vec(0, 0, 0);
    }
    Camera(double x, double y, double z)
    {
        set_vec(x, y, z);
    }

    float fovKoeff() const
    { return tan(fov / 2.0); }
};

} }

#endif // CAMERA_H
