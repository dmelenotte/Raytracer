#include "Cone.hpp"

#include <cmath>
#include <iostream>

Cone::Cone(const Position &position, float angle, const Vector &direction,
    const Color &color, const Color &albedo, const Color &reflection) :
        APrimitive(color, albedo, reflection), _position(position), _angle(angle), _direction(direction) {}

IObject::ObjectType Cone::getObjectType() const
{
    return IObject::ObjectType::PRIMITIVE;
}

bool Cone::hit(const Ray &ray, double &t, Vector &normal) {

    Vector dir = ray.getVector();
    Position origin = (ray.getPoint() - _position);

    double radians = _angle * (M_PI / 180.0);
    double k = std::tan(radians) * std::tan(radians);

    double dx = dir.getX(), dy = dir.getY(), dz = dir.getZ();
    double ox = origin.getX(), oy = origin.getY(), oz = origin.getZ();

    double A = dx * dx + dz * dz - k * dy * dy;
    double B = 2.0 * (ox * dx + oz * dz - k * oy * dy);
    double C = ox * ox + oz * oz - k * oy * oy;
    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0) return false;

    double sqrtDisc = std::sqrt(discriminant);
    double t1 = (-B - sqrtDisc) / (2.0 * A);
    double t2 = (-B + sqrtDisc) / (2.0 * A);

    if (t1 > 0.001f) {
        t = t1;
    } else if (t2 > 0.001f) {
        t = t2;
    } else {
        return false;
    }

    Position hitPoint = origin + dir * t;

    Vector v(hitPoint.getX(), 0, hitPoint.getZ());
    double slope = std::sqrt(v.dot(v)) / std::tan(_angle);
    normal = Vector(v.getX(), -slope, v.getZ()).normalized();
    
    return true;
}
