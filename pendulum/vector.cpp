//#include <vector.h>
//#include <math.h>

//class Vector
//{
//private:
//    double x;
//    double y;
//    double z;
//public:
//    Vector() : x(0), y(0), z(0)
//    { }
//    Vector(double x1, double y1, double z1) :
//        x(x1), y(y1), z(z1)
//    { }

//    double len()
//    {
//        return sqrt(x * x + y * y + z * z);
//    }

//    Vector normalize()
//    {
//        double koef = 1 / len();
//        x *= koef;
//        y *= koef;
//        z *= koef;
//        return Vector(x, y, z);
//    }

//    // + и +=
//    Vector operator+(const Vector v) const
//    {
//        Vector result;
//        result.x = x + v.x;
//        result.y = y + v.y;
//        result.z = z + v.z;
//        return result;
//    }

//    Vector operator+=(const Vector v)
//    {
//        x += v.x;
//        y += v.y;
//        z += v.z;
//        return Vector(x, y, z);
//    }

//    // - и -=
//    Vector operator-(const Vector v) const
//    {
//        Vector result;
//        result.x = x - v.x;
//        result.y = y - v.y;
//        result.z = z - v.z;
//        return result;
//    }

//    Vector operator-=(const Vector v)
//    {
//        x -= v.x;
//        y -= v.y;
//        z -= v.z;
//        return Vector(x, y, z);
//    }

//    // *, *= и скалярное
//    Vector operator*(const Vector v) const
//    {
//        Vector result;
//        result.x = x * v.x;
//        result.y = y * v.y;
//        result.z = z * v.z;
//        return result;
//    }

//    Vector operator*(const int n) const
//    {
//        Vector result;
//        result.x = x * n;
//        result.y = y * n;
//        result.z = z * n;
//        return result;
//    }

//    Vector operator*=(const Vector v)
//    {
//        x *= v.x;
//        y *= v.y;
//        z *= v.z;
//        return Vector(x, y, z);
//    }

//    Vector operator*=(const int n)
//    {
//        x *= n;
//        y *= n;
//        z *= n;
//        return Vector(x, y, z);
//    }

//    double scalar(const Vector v)
//    {
//        return x * v.x + y * v.y + z * v.z;
//    }

//    // операции / и /=
//    Vector operator/(const int n) const
//    {
//        Vector result;
//        result.x = x / n;
//        result.y = y / n;
//        result.z = z / n;
//        return result;
//    }

//    Vector operator/=(const int n)
//    {
//        x /= n;
//        y /= n;
//        z /= n;
//        return Vector(x, y, z);
//    }

//    // Возведение в степень
//    Vector sqr()
//    {
//        x *= x;
//        y *= y;
//        z *= z;
//        return Vector(x, y, z);;
//    }

//    Vector power(const int n)
//    {
//        x = pow(x, n);
//        y = pow(y, n);
//        z = pow(z, n);
//        return Vector(x, y, z);
//    }

//};

////vector_t pow_vec_n(vector_t v1, const int n)
////{
////    v1.x = pow(v1.x, n);
////    v1.y = pow(v1.y, n);
////    v1.z = pow(v1.z, n);
////    return v1;
////}

////vector_t mul_vec_n(vector_t v1, const int n)
////{
////    v1.x = v1.x * n;
////    v1.y = v1.y * n;
////    v1.z = v1.z * n;
////    return v1;
////}

////vector_t div_vec_n(vector_t v1, const int n)
////{
////    v1.x = v1.x / n;
////    v1.y = v1.y / n;
////    v1.z = v1.z / n;
////    return v1;
////}

////double len_vec(const vector_t v)
////{
////    int len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
////    return len;
////}

////vector_t normalize_vec(vector_t v)
////{
////    double k = 1 / len_vec(v);
////    v.x = v.x * k;
////    v.y = v.y * k;
////    v.z = v.z * k;
////    return v;
////}

////vector_t sqr_vec(vector_t v)
////{
////    v.x = v.x * v.x;
////    v.y = v.y * v.y;
////    v.z = v.z * v.z;
////    return v;
////}

////double mul_scalar_vec(const vector_t v1, const vector_t v2)
////{
////    int res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
////    return res;
////}

////vector_t sum_vec(vector_t v1, const vector_t v2)
////{
////    v1.x = v1.x + v2.x;
////    v1.y = v1.y + v2.y;
////    v1.z = v1.z + v2.z;
////    return v1;
////}

////vector_t sub_vec(vector_t v1, const vector_t v2)
////{
////    v1.x = v1.x - v2.x;
////    v1.y = v1.y - v2.y;
////    v1.z = v1.z - v2.z;
////    return v1;
////}

////vector_t mul_vec(vector_t v1, const vector_t v2)
////{
////    v1.x = v1.x * v2.x;
////    v1.y = v1.y * v2.y;
////    v1.z = v1.z * v2.z;
////    return v1;
////}
