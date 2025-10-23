#include "Entity.hpp"

#include <cmath>

Entity::Entity(std::shared_ptr<IObject> object)
{
    IPrimitive *ptr = dynamic_cast<IPrimitive *>(object.get());
    if (ptr == nullptr) {
        return;
    }
    _primitive.reset(ptr, [](IPrimitive *){});
}

Entity::Entity(const Entity &other)
{
    _primitive = other._primitive;
    _lights = other._lights;
    _connectedEntities = other._connectedEntities;
}

Entity::~Entity()
{
    _primitive.reset();
}

void Entity::registerEntity(const Entity &entity)
{
    _connectedEntities.push_back(entity);
}

void Entity::registerLights(const std::vector<std::shared_ptr<IObject>> &lights)
{
    for (auto it = lights.begin(); it != lights.end(); ++it) {
        ILight *ptr = dynamic_cast<ILight *>((*it).get());
        if (ptr == nullptr) {
            continue;
        }
        std::shared_ptr<ILight> newLight(ptr, [](ILight *){});
        _lights.push_back(newLight);
    }
}

Color Entity::calculateLightning(const Vector &hitPoint, const Vector &normal, const Vector &viewDirection)
{
    Color total(255, 255, 255);
    total *= _primitive->getColor();
    total /= 255;
    for (auto it = _lights.begin(); it != _lights.end(); ++it) {
        if ((*it)->getLightType() == ILight::AMBIENT) {
            total *= (*it)->getIntensity();
            break;
        }
    }
    for (auto it = _lights.begin(); it != _lights.end(); ++it) {
        if ((*it)->getLightType() == ILight::DIRECTIONAL) {
            std::shared_ptr<DirectionalLight> light(dynamic_cast<DirectionalLight *>((*it).get()),
                [](DirectionalLight *){});
            bool shadow = this->inShadow(hitPoint, -light->getDirectional());
            if (shadow) {
                continue;
            }
            double ndotl = std::max(0.0, normal.dot(-light->getDirectional()));
            Color diffuse = _primitive->getColor() * Color(255, 255, 255);
            diffuse /= 255;
            diffuse *= light->getIntensity() * ndotl;
            Vector reflexionDirection = light->getDirectional() - normal * (2.0 * light->getDirectional().dot(normal));

            double specular = std::pow(std::max(0.0, reflexionDirection.dot(viewDirection)), light->getShininess());
            Color specularColor = Color{255, 255, 255} * specular;
            total = total + diffuse + specularColor;
        }
    }
    total.change(Color::R, (total.get(Color::R) * _primitive->getAlbedo().get(Color::R) / 255.0));
    total.change(Color::G, (total.get(Color::G) * _primitive->getAlbedo().get(Color::G) / 255.0));
    total.change(Color::B, (total.get(Color::B) * _primitive->getAlbedo().get(Color::B) / 255.0));
    total.clamp();
    return total;
}

std::shared_ptr<IPrimitive> &Entity::getPrimitive()
{
    return _primitive;
}

const std::shared_ptr<IPrimitive> &Entity::getPrimitive() const
{
    return _primitive;
}

/* ---- Private ---- */

bool Entity::inShadow(const Vector &point, const Vector &lightDirection)
{
    Vector originShadow = point + lightDirection * 0.01f;
    Ray ray(Position(originShadow.getX(), originShadow.getY(), originShadow.getZ()), lightDirection);
    double t;
    Vector normal;
    if (_primitive->hit(ray, t, normal)) {
        return true;
    }
    for (auto it = _connectedEntities.begin(); it != _connectedEntities.end(); ++it) {
        bool shadow = (*it).getPrimitive()->hit(ray, t, normal);
        if (shadow) {
            return true;
        }
    }
    return false;
}
