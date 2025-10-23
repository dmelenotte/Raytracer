#include "Plane.hpp"

#include <cmath>

Plane::Plane(char axis, int position, const Color &color, const Color &albedo, const Color &reflection) :
        APrimitive(color, albedo, reflection), _axis(axis)
{
    _normal = Vector(0.0, 1.0, 0.0);
    if (_axis == 'Z')
        _origin.setX_Y_Z(0,0,position);
    if (axis == 'Y')
        _origin.setX_Y_Z(0,position,0);
    if (axis == 'X')
        _origin.setX_Y_Z(position,0,0);
}

IObject::ObjectType Plane::getObjectType() const
{
    return IObject::ObjectType::PRIMITIVE;
}

bool Plane::hit(const Ray &ray, double &t, Vector &normal)
{
    if (_axis == 'X') {
        if (std::abs(ray.getVector().getX()) < 1e-6) {
            return false;
        }
        t = (_origin.getX() - ray.getPoint().getX()) / ray.getVector().getX();
        if (t > 0.001f) {
            normal = Vector(1, 0, 0);
            return true;
        }
    }
    if (_axis == 'Y') {
        if (std::abs(ray.getVector().getY()) < 1e-6) {
            return false;
        }
        t = (_origin.getY() - ray.getPoint().getY()) / ray.getVector().getY();
        if (t > 0.001f) {
            normal = Vector(0, 1, 0);
            return true;
        }
    }
    if (_axis == 'Z') {
        if (std::abs(ray.getVector().getZ()) < 1e-6) {
            return false;
        }
        t = (_origin.getZ() - ray.getPoint().getZ()) / ray.getVector().getZ();
        if (t > 0.001f) {
            normal = Vector(0, 0, 1);
            return true;
        }
    }
    return false;
}
