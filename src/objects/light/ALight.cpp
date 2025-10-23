#include "ALight.hpp"

ALight::ALight(float intensity) : _intensity(intensity) {}

double ALight::getIntensity() const
{
    return _intensity;
}
