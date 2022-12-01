#include "color.hpp"

namespace FP { namespace color {

QColor Color::qtcolor()
{
    _r *= 255;
    _g *= 255;
    _b *= 255;

    _r = static_cast<int>(_r);
    _g = static_cast<int>(_g);
    _b = static_cast<int>(_b);

    if (_r > 255)
        _r = 255;
    if (_g > 255)
        _g = 255;
    if (_b > 255)
        _b = 255;

    if (_r < 0)
        _r = 0;
    if (_g < 0)
        _g = 0;
    if (_b < 0)
        _b = 0;

    return QColor(_r, _g, _b, _a);
}

QRgb Color::qrgbColor()
{
    float max = std::max(_r, std::max(_g, _b));
    if (max > 1)
    {
        _r /= max;
        _g /= max;
        _b /= max;
    }
    _r *= 255;
    _g *= 255;
    _b *= 255;

    _r = static_cast<int>(_r);
    _g = static_cast<int>(_g);
    _b = static_cast<int>(_b);

    if (_r > 255)
        _r = 255;
    if (_g > 255)
        _g = 255;
    if (_b > 255)
        _b = 255;

    if (_r < 0)
        _r = 0;
    if (_g < 0)
        _g = 0;
    if (_b < 0)
        _b = 0;

    return qRgb(_r, _g, _b);
}

} }
