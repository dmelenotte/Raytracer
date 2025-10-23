#include "Color.hpp"

#include <cmath>

Color::Color() : _r(0), _g(0), _b(0), _a(0) {}

Color::Color(double r, double g, double b, double a) :
    _r(r), _g(g), _b(b), _a(a) {}

Color::Color(const Color &otherColor)
{
    _r = otherColor._r;
    _g = otherColor._g;
    _b = otherColor._b;
    _a = otherColor._a;
}

void Color::change(Color::ColorCode colorCode, double newColorCode)
{
    switch (colorCode) {
        case ColorCode::R:
            _r = newColorCode;
            return;
        case ColorCode::G:
            _g = newColorCode;
            return;
        case ColorCode::B:
            _b = newColorCode;
            return;
        case ColorCode::A:
            _a = newColorCode;
            return;
        default:
            return;
    }
}

double Color::get(Color::ColorCode colorCode) const
{
    double color = 0;

    switch (colorCode) {
        case ColorCode::R:
            color = _r;
            break;
        case ColorCode::G:
            color = _g;
            break;
        case ColorCode::B:
            color = _b;
            break;
        case ColorCode::A:
            color = _a;
            break;
        default:
            break;
    }
    return color;
}

void Color::clamp()
{
    _r = std::min(255.0, std::max(0.0, _r));
    _g = std::min(255.0, std::max(0.0, _g));
    _b = std::min(255.0, std::max(0.0, _b));
    _a = std::min(255.0, std::max(0.0, _a));
}

void Color::operator=(const Color &otherColor)
{
    _r = otherColor._r;
    _g = otherColor._g;
    _b = otherColor._b;
    _a = otherColor._a;
}

bool Color::operator==(const Color &otherColor) const
{
    if (_r == otherColor._r && _g == otherColor._g && _b == otherColor._b && _a == otherColor._a) {
        return true;
    }
    return false;
}

bool Color::operator!=(const Color &otherColor) const
{
    if (_r == otherColor._r && _g == otherColor._g && _b == otherColor._b && _a == otherColor._a) {
        return false;
    }
    return true;
}

Color Color::operator+(const Color &otherColor) const
{
    return Color(_r + otherColor._r, _g + otherColor._g, _b + otherColor._b, _a);
}

void Color::operator+=(const Color &otherColor)
{
    _r += otherColor._r;
    _g += otherColor._g;
    _b += otherColor._b;
}

Color Color::operator-(const Color &otherColor) const
{
    return Color(_r - otherColor._r, _g - otherColor._g, _b - otherColor._b, _a);
}

void Color::operator-=(const Color &otherColor)
{
    _r -= otherColor._r;
    _g -= otherColor._g;
    _b -= otherColor._b;
}

Color Color::operator*(const Color &otherColor) const
{
    return Color(_r * otherColor._r, _g * otherColor._g, _b * otherColor._b, _a);
}

Color Color::operator*(double value) const
{
    return Color(_r * value, _g * value, _b * value, _a);
}

void Color::operator*=(const Color &otherColor)
{
    _r *= otherColor._r;
    _g *= otherColor._g;
    _b *= otherColor._b;
}

void Color::operator*=(double value)
{
    _r *= value;
    _g *= value;
    _b *= value;
}

Color Color::operator/(const Color &otherColor) const
{
    return Color((otherColor._r != 0) ? (_r / otherColor._r) : _r,
        (otherColor._g != 0) ? (_g / otherColor._g) : _g,
        (otherColor._b != 0) ? (_b / otherColor._b) : _b, _a);
}

Color Color::operator/(double value) const
{
    if (value == 0.0f) {
        return Color(_r, _g, _b, _a);
    }
    return Color(_r / value, _g / value, _b / value, _a);
}

void Color::operator/=(const Color &otherColor)
{
    if (otherColor._r != 0)
    {
        _r /= otherColor._r;
    }
    if (otherColor._g != 0)
    {
        _g /= otherColor._g;
    }
    if (otherColor._b != 0)
    {
        _b /= otherColor._b;
    }
}

void Color::operator/=(double value)
{
    if (value == 0) {
        return;
    }
    _r /= value;
    _g /= value;
    _b /= value;
}
