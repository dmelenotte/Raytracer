#include "AmbientLight.hpp"

AmbientLight::AmbientLight(float intensity) : ALight(intensity) {}

IObject::ObjectType AmbientLight::getObjectType() const
{
    return IObject::ObjectType::LIGHT;
}

ILight::LightType AmbientLight::getLightType() const
{
    return ILight::LightType::AMBIENT;
}
