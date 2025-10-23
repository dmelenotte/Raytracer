#include "APrimivite.hpp"

APrimitive::APrimitive(const Color &color, const Color &albedo, const Color &reflection) :
    _color(color), _albedo(albedo), _reflection(reflection) {}

const Color &APrimitive::getColor() const
{
    return _color;
}

const Color &APrimitive::getAlbedo() const
{
    return _albedo;
}

const Color &APrimitive::getReflectivity() const
{
    return _reflection;
}
