#ifndef __POSITION__
    #define __POSITION__

#include "Vector.hpp"

class Position {
    public:
        Position();
        Position(double x, double y, double z);
        Position(const Position &otherPosition);
        ~Position() = default;
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setX_Y_Z(double x, double y, double z);
        double getX() const;
        double getY() const;
        double getZ() const;
        void operator=(const Position &otherPosition);
        bool operator==(const Position &otherPosition) const;
        bool operator!=(const Position &otherPosition) const;
        Position operator+(const Position &p) const;
        Position operator+(const Vector &vector) const;
        Position operator-(const Position &p) const;
        Position operator-(const Vector &vector) const;
        operator Vector () const;
    private:
        double _x;
        double _y;
        double _z;
};

#endif
