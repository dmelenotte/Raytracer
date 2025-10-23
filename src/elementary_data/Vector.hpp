#ifndef __VECTOR__
    #define __VECTOR__

class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector(const Vector &otherVector);
        ~Vector() = default;
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setX_Y_Z(double x, double y, double z);
        double getX() const;
        double getY() const;
        double getZ() const;
        double length() const;
        double dot(const Vector &otherVector) const;
        Vector normalized() const;
        Vector cross(const Vector &otherVector) const;
        void operator=(const Vector &otherVector);
        Vector operator+(const Vector &otherVector) const;
        void operator+=(const Vector &otherVector);
        Vector operator-(const Vector &otherVector) const;
        Vector operator-() const;
        void operator-=(const Vector &otherVector);
        Vector operator*(const Vector &otherVector) const;
        Vector operator*(double value) const;
        void operator*=(const Vector &otherVector);
        void operator*=(double value);
        Vector operator/(const Vector &otherVector) const;
        Vector operator/(double value) const;
        void operator/=(const Vector &otherVector);
        void operator/=(double value);
    private:
        double _x;
        double _y;
        double _z;
};

#endif
