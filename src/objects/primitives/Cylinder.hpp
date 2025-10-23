#ifndef __CYLINDER__
    #define __CYLINDER__

#include "APrimivite.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Color.hpp"

class Cylinder : public APrimitive {
    public:
        Cylinder(const Position &position, float radius, const Vector &directional,
            const Color &color, const Color &albedo, const Color &reflection);
        ~Cylinder() = default;
        IObject::ObjectType getObjectType() const;
        bool hit(const Ray &ray, double &t, Vector &normal);
    private:
        Position _position;
        float _radius;
        Vector _directional;
};

#endif
