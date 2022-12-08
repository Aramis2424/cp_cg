#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"

namespace FP { namespace material {
using namespace FP::vector;
using namespace FP::color;

class Material
{
private:
    Color diffuse;
    Vector albedo;
    double spec_exp;
public:
    Material() : spec_exp(0)
    { }
    Material(Color diffCol, Vector alb, double s_e)
    {
        diffuse = diffCol;
        albedo = alb;
        spec_exp = s_e;
    }

    void get_material(Color &difCol, Vector &alb, double &spec) const
    {
        difCol = diffuse;
        alb = albedo;
        spec = spec_exp;
    }

    double get_spec_exp()
    {
        return spec_exp;
    }

    Vector get_albedo()
    {
        return albedo;
    }

    Color get_diffuse()
    {
        return diffuse;
    }
};

} }

#endif // MATERIAL_HPP
