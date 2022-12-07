#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

namespace FP { namespace vector {

class Vector
{
protected:
    double x;
    double y;
    double z;
public:
    Vector() : x(0), y(0), z(0)
    { }
    Vector(double x1, double y1, double z1) :
        x(x1), y(y1), z(z1)
    { }
    void show( ) const
    {
        std::cout << "( " << x << ", ";
        std::cout << y << ", ";
        std::cout << z << " )\n";
    }

    void set_vec(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void get_vec(double &x, double &y, double &z) const
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }

    double len()
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vector normalize()
    {
        double koef = 1 / len();
        x *= koef;
        y *= koef;
        z *= koef;
        return Vector(x, y, z);
    }

    // + and +=
    Vector operator+(const Vector v) const
    {
        Vector result;
        result.x = x + v.x;
        result.y = y + v.y;
        result.z = z + v.z;
        return result;
    }

    Vector operator+=(const Vector v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return Vector(x, y, z);
    }

    // - and -=
    Vector operator-(const Vector v) const
    {
        Vector result;
        result.x = x - v.x;
        result.y = y - v.y;
        result.z = z - v.z;
        return result;
    }

    Vector operator-(const float n) const
    {
        Vector result;
        result.x = x - n;
        result.y = y - n;
        result.z = z - n;
        return result;
    }

    Vector operator-=(const Vector v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return Vector(x, y, z);
    }

    // *, *= and scalar
    Vector operator*(const Vector v) const
    {
        Vector result;
        result.x = x * v.x;
        result.y = y * v.y;
        result.z = z * v.z;
        return result;
    }

    Vector operator*(const double n) const
    {
        Vector result;
        result.x = x * n;
        result.y = y * n;
        result.z = z * n;
        return result;
    }

    Vector operator*=(const Vector v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return Vector(x, y, z);
    }

    Vector operator*=(const double n)
    {
        x *= n;
        y *= n;
        z *= n;
        return Vector(x, y, z);
    }

    double scalar(const Vector v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    // operators / and /=
    Vector operator/(const double n) const
    {
        Vector result;
        result.x = x / n;
        result.y = y / n;
        result.z = z / n;
        return result;
    }

    Vector operator/=(const double n)
    {
        x /= n;
        y /= n;
        z /= n;
        return Vector(x, y, z);
    }

    // power and sqr
    Vector sqr()
    {
        x *= x;
        y *= y;
        z *= z;
        return Vector(x, y, z);;
    }

    Vector power(const double n)
    {
        x = pow(x, n);
        y = pow(y, n);
        z = pow(z, n);
        return Vector(x, y, z);
    }

};

}}
#endif // VECTOR_H
