#include "Tetrahedron.hpp"

#include <cmath>
#include <iostream>

Tetrahedron::Tetrahedron(const Position &point1, const Position &point2, const Position &point3, const Position &point4,
    const Vector &direction, const Color &color, const Color &albedo, const Color &reflection) :
    APrimitive(color, albedo, reflection), _point1(point1), _point2(point2), _point3(point3), _point4(point4),
    _direction(direction) {}

IObject::ObjectType Tetrahedron::getObjectType() const
{
    return IObject::ObjectType::PRIMITIVE;
}

bool Tetrahedron::hit(const Ray &ray, double &t, Vector &normal) {
    bool hit = false;
    double closestT = std::numeric_limits<double>::max();
    Vector tempNormal = Vector(0,0,0);
    double tempT = 0;

    if (rayIntersectsTriangle(ray, _point1, _point2, _point3, tempT, tempNormal) && tempT < closestT) {
        hit = true;
        closestT = tempT;
        normal = tempNormal;
    }

    if (rayIntersectsTriangle(ray, _point1, _point2, _point4, tempT, tempNormal) && tempT < closestT) {
        hit = true;
        closestT = tempT;
        normal = tempNormal;
    }

    if (rayIntersectsTriangle(ray, _point1, _point3, _point4, tempT, tempNormal) && tempT < closestT) {
        hit = true;
        closestT = tempT;
        normal = tempNormal;
    }

    if (rayIntersectsTriangle(ray, _point2, _point3, _point4, tempT, tempNormal) && tempT < closestT) {
        hit = true;
        closestT = tempT;
        normal = tempNormal;
    }

    if (hit) {
        t = closestT;
        if (normal.dot(ray.getVector()) > 0)
            normal = -normal;
    }

    return hit;
}

/* ---- Private ---- */

bool Tetrahedron::rayIntersectsTriangle(const Ray &ray, const Position &v0, const Position &v1, const Position &v2,
    double &t, Vector &normal) {
    const double EPSILON = 1e-8;
    Vector edge1 = v1 - v0;
    Vector edge2 = v2 - v0;
    Vector h = ray.getVector().cross(edge2);
    double a = edge1.dot(h);

    if (std::abs(a) < EPSILON) return false;

    double f = 1.0 / a;
    Vector s = ray.getPoint() - v0;
    double u = f * s.dot(h);
    if (u < 0.0 || u > 1.0) return false;

    Vector q = s.cross(edge1);
    double v = f * ray.getVector().dot(q);

    if (v < 0.0 || u + v > 1.0) return false;

    double tempT = f * edge2.dot(q);
    if (tempT > EPSILON) {
        t = tempT;
        normal = edge1.cross(edge2).normalized();
        return true;
    }

    return false;
}
