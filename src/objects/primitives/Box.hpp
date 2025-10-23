#ifndef __BOX__
    #define __BOX__

#include "APrimivite.hpp"

#include "../../elementary_data/Position.hpp"
#include "../../elementary_data/Color.hpp"

class Box : public APrimitive {
    public:
        Box(const Position &position, int width, int height, int depth, const Vector &direction,
            const Color &color, const Color &albedo, const Color &reflection);
        ~Box() = default;
        IObject::ObjectType getObjectType() const;
        bool hit(const Ray &ray, double &t, Vector &normal);
    private:
        Position _position;
        int _width;
        int _height;
        int _depth;
        Vector _direction;
};

#endif
