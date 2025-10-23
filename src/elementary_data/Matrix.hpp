#ifndef __MATRIX__
    #define __MATRIX__

#include "../elementary_data/Vector.hpp"
#include "../elementary_data/Position.hpp"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <array>

struct Matrix {
    struct Vec4D {
        double x;
        double y;
        double z;
        double w;

        Vec4D() : x(0), y(0), z(0), w(0) {}
        Vec4D(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
        Vector toVector() const {return {x / w, y / w, z / w};}
    };

    std::array<std::array<double, 4>, 4> m;

    Matrix();
    Matrix(const Matrix &otherMatrix);
    ~Matrix() = default;
    static Matrix identity();
    static Matrix translation(const Vector &vector);
    static Matrix rotationX(double angle);
    static Matrix rotationY(double angle);
    static Matrix rotationZ(double angle);
    void operator=(const Matrix &otherMatrix);
    Vec4D operator*(const Vec4D &v) const;
    Matrix operator*(const Matrix &otherMatrix) const;
    Matrix transpose() const;
};

#endif
