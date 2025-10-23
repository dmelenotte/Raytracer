#include "Box.hpp"

#include <cmath>

Box::Box(const Position &position, int width, int height, int depth, const Vector &direction,
    const Color &color, const Color &albedo, const Color &reflection) :
    APrimitive(color, albedo, reflection),
    _position(position), _width(width), _height(height), _depth(depth), _direction(direction) {}

IObject::ObjectType Box::getObjectType() const
{
    return IObject::ObjectType::PRIMITIVE;
}

bool Box::hit(const Ray &ray, double &t, Vector &normal)
{
    Vector dir = ray.getVector();
    Position origin = ray.getPoint();
    Position min = Position(
        _position.getX() - _width /2,
        _position.getY() - _height /2,
        _position.getZ() - _depth /2
    );
    Position max = Position(
        _position.getX() + _width /2,
        _position.getY() + _height /2,
        _position.getZ() + _depth /2
    );

    double tMin = (min.getX() - origin.getX()) / dir.getX();
    double tMax = (max.getX() - origin.getX()) / dir.getX();
    if (tMin > tMax)
        std::swap(tMin, tMax);

    double tyMin = (min.getY() - origin.getY()) / dir.getY();
    double tyMax = (max.getY() - origin.getY()) / dir.getY();
    if (tyMin > tyMax)
        std::swap(tyMin, tyMax);

    if ((tMin > tyMax) || (tyMin > tMax))
        return false;
    if (tyMin > tMin)
        tMin = tyMin;
    if (tyMax < tMax)
        tMax = tyMax;

    double tzMin = (min.getZ() - origin.getZ()) / dir.getZ();
    double tzMax = (max.getZ() - origin.getZ()) / dir.getZ();
    if (tzMin > tzMax)
        std::swap(tzMin, tzMax);

    if ((tMin > tzMax) || (tzMin > tMax))
        return false;
    if (tzMin > tMin)
        tMin = tzMin;
    if (tzMax < tMax)
        tMax = tzMax;

    if (tMax < 0.001f)
        return false;

    t = (tMin > 0.001f) ? tMin : tMax;
    Position hitPoint = origin + dir * t;
    const double epsilon = 1e-4;
    if (std::abs(hitPoint.getX() - min.getX()) < epsilon)
        normal = Vector(-1, 0, 0);
    else if (std::abs(hitPoint.getX() - max.getX()) < epsilon)
        normal = Vector(1, 0, 0);
    else if (std::abs(hitPoint.getY() - min.getY()) < epsilon)
        normal = Vector(0, -1, 0);
    else if (std::abs(hitPoint.getY() - max.getY()) < epsilon)
        normal = Vector(0, 1, 0);
    else if (std::abs(hitPoint.getZ() - min.getZ()) < epsilon)
        normal = Vector(0, 0, -1);
    else
        normal = Vector(0, 0, 1);
    return true;
}
