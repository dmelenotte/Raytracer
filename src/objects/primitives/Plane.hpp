#ifndef __PLANE__
    #define __PLANE__

#include "APrimivite.hpp"

#include "../../elementary_data/Color.hpp"
#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Vector.hpp"
#include "../../elementary_data/Ray.hpp"

class Plane : public APrimitive {
    public:
        Plane(char axis, int position, const Color &color, const Color &albedo, const Color &reflection);
        ~Plane() = default;
        IObject::ObjectType getObjectType() const;
        bool hit(const Ray &ray, double &t, Vector &normal);
    private:
        char _axis;
        Vector _normal;
        Position _origin;
};

#endif