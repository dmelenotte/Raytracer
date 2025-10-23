#ifndef __TETRAHEDRON__
    #define __TETRAHEDRON__

#include "APrimivite.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Color.hpp"

class Tetrahedron : public APrimitive {
    public:
        Tetrahedron(const Position &point1, const Position &point2, const Position &point3, const Position &point4,
            const Vector &direction, const Color &color, const Color &albedo, const Color &reflection);
        ~Tetrahedron() = default;
        IObject::ObjectType getObjectType() const;
        bool hit(const Ray &ray, double &t, Vector &normal);
    private:
        bool rayIntersectsTriangle(const Ray &ray, const Position &v0, const Position &v1, const Position &v2,
            double &t, Vector &normal);

        Position _point1;
        Position _point2;
        Position _point3;
        Position _point4;
        Vector _direction;
};

#endif
