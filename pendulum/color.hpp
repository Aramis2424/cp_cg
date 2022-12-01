#ifndef COLOR_HPP
#define COLOR_HPP

#include <QColor>
#include <iostream>

#include "vector.hpp"

namespace FP { namespace color {
using namespace FP::vector;

class Color : public QColor, public Vector
{
private:
    double _r;
    double _g;
    double _b;
    double _a;
public:
    Color() : QColor()
    {
        _r = 0;
        _g = 0;
        _b = 0;
        _a = 255;
        set_vec(0,0,0);
    }

    Color(double r, double g, double b, double a = 255)
    {
        _r = r;
        _g = g;
        _b = b;
        _a = a;
        set_vec(r, g, b);
    }

    Color set(double r, double g, double b, double a = 255)
    {
        _r = r;
        _g = g;
        _b = b;
        _a = a;
        set_vec(r, g, b);

        return Color(_r, _g, _b, _a);
    }
    void show() const
    {
        std::cout << _r << " ";
        std::cout << _g << " ";
        std::cout << _b << " ";
        std::cout << _a << std::endl;
    }

    QColor qtcolor();
    QRgb qrgbColor();
};

} }

#endif // COLOR_HPP
