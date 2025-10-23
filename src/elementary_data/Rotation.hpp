#ifndef __ROTATION__
    #define __ROTATION__

#include "Vector.hpp"

class Rotation {
    public:
        Rotation();
        Rotation(double x, double y, double z);
        Rotation(const Rotation &otherRotation);
        ~Rotation() = default;
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setX_Y_Z(double x, double y, double z);
        double getX() const;
        double getY() const;
        double getZ() const;
        void operator=(const Rotation &otherRotation);
        bool operator==(const Rotation &otherRotation) const;
        bool operator!=(const Rotation &otherRotation) const;
        operator Vector () const;
    private:
        double _x;
        double _y;
        double _z;
};

#endif
