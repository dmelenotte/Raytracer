#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight(float intensity, float shininess, const Vector &direction) :
        ALight(intensity), _shininess(shininess), _direction(direction.normalized()) {}

IObject::ObjectType DirectionalLight::getObjectType() const
{
    return IObject::ObjectType::LIGHT;
}

ILight::LightType DirectionalLight::getLightType() const
{
    return ILight::LightType::DIRECTIONAL;
}

double DirectionalLight::getShininess() const
{
    return _shininess;
}

const Vector &DirectionalLight::getDirectional() const
{
    return _direction;
}
