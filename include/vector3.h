#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
//#include <corecrt_math_defines.h>

struct Vector3
{
    public:
        Vector3() : x(0), y(0), z(0) { return; }
        Vector3(double x, double y, double z) : x(x), y(y), z(z) { return; }
        Vector3(double x, double y) : x(x), y(y), z(0) { return; }

        double x;
        double y;
        double z;

		Vector3 operator+(const Vector3 &rhs) const;
		Vector3 operator-(const Vector3 &rhs) const;
		Vector3 operator*(const Vector3 &rhs) const;
		Vector3 operator/(const Vector3 &rhs) const;

		Vector3 operator+(const double &rhs) const;
		Vector3 operator-(const double &rhs) const;
		Vector3 operator*(const double &rhs) const;
		Vector3 operator/(const double &rhs) const;

		Vector3& operator+=(const Vector3& rhs);
		Vector3& operator*=(const Vector3 &rhs);

		static Vector3 RotateX(Vector3 point, double angle);
		static Vector3 RotateY(Vector3 point, double angle);
		static Vector3 RotateZ(Vector3 point, double angle);
		static Vector3 Rotate(Vector3 point, Vector3 angles);
		static Vector3 ToScreenSpace(Vector3 a);
};

#endif