#include "Matrix.hpp"

#include <cstddef>

Matrix::Matrix() : m({}) {}

Matrix::Matrix(const Matrix &otherMatrix)
{
    m = otherMatrix.m;
}

Matrix Matrix::identity()
{
    Matrix newM;
    for (std::size_t i = 0; i < 4; i++) {
        newM.m[i][i] = 1.0;
    }
    return newM;
}

Matrix Matrix::translation(const Vector &vector)
{
    Matrix newM = Matrix::identity();

    newM.m[0][3] = vector.getX();
    newM.m[1][3] = vector.getY();
    newM.m[2][3] = vector.getZ();
    return newM;
}

Matrix Matrix::rotationX(double angle)
{
    Matrix newM = Matrix::identity();
    double rad = angle * M_PI / 180.0;
    double c = std::cos(rad);
    double s = std::sin(rad);
    newM.m[1][1] = c;
    newM.m[1][2] = -s;
    newM.m[2][1] = s;
    newM.m[2][2] = c;
    return newM;
}

Matrix Matrix::rotationY(double angle)
{
    Matrix newM = Matrix::identity();
    double rad = angle * M_PI / 180.0;
    double c = std::cos(rad);
    double s = std::sin(rad);
    newM.m[0][0] = c;
    newM.m[0][2] = s;
    newM.m[2][0] = -s;
    newM.m[2][2] = c;
    return newM;
}

Matrix Matrix::rotationZ(double angle)
{
    Matrix newM = Matrix::identity();
    double rad = angle * M_PI / 180.0;
    double c = std::cos(rad);
    double s = std::sin(rad);
    newM.m[0][0] = c;
    newM.m[0][1] = -s;
    newM.m[1][0] = s;
    newM.m[1][1] = c;
    return newM;
}

void Matrix::operator=(const Matrix &otherMatrix)
{
    m = otherMatrix.m;
}

Matrix::Vec4D Matrix::operator*(const Matrix::Vec4D &v) const
{
    Matrix::Vec4D v4D;

    v4D.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
    v4D.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
    v4D.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
    v4D.w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w;
    return v4D;
}

Matrix Matrix::operator*(const Matrix &otherMatrix) const
{
    Matrix newM;
    for (std::size_t i = 0; i < 4; ++i) {
        for (std::size_t j = 0; j < 4; ++j) {
            for (std::size_t k = 0; k < 4; ++k) {
                newM.m[i][j] += m[i][k] * otherMatrix.m[k][j];
            }
        }
    }
    return newM;
}

Matrix Matrix::transpose() const {
    Matrix result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.m[i][j] = this->m[j][i];
    return result;
}
