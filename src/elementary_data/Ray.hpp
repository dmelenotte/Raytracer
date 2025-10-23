#ifndef __RAY__
    #define __RAY__

#include "Position.hpp"
#include "Vector.hpp"

class Ray {
    public:
        Ray() = default;
        Ray(const Position &point, const Vector &vector);
        Ray(const Ray &other);
        ~Ray() = default;
        Position &getPoint();
        const Position &getPoint() const;
        Vector &getVector();
        const Vector &getVector() const;
        void operator=(const Ray &other);
    private:
        Position _point;
        Vector _vector;
};

#endif
