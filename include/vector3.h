#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
#ifndef __APPLE__
#include <corecrt_math_defines.h>
#endif

#include "glm.hpp"
#include "gtc/quaternion.hpp"

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
		Vector3& operator-=(const Vector3& rhs);
		Vector3& operator*=(const Vector3 &rhs);
		Vector3& operator/=(const Vector3 &rhs);

		static Vector3 RotateX(Vector3 point, double angle);
		static Vector3 RotateY(Vector3 point, double angle);
		static Vector3 RotateZ(Vector3 point, double angle);
		static Vector3 Rotate(Vector3 point, Vector3 angles);
		static Vector3 ToScreenSpace(Vector3 a);
		static Vector3 TriangleNormal(Vector3 a, Vector3 b, Vector3 c);
		static bool Render(Vector3 a, Vector3 b, Vector3 c);
		static double angleBetween(Vector3 a, Vector3 b)
		{
			glm::vec3 da = glm::normalize(glm::vec3(a.x, a.y, a.z));
			glm::vec3 db = glm::normalize(glm::vec3(b.x, b.y, b.z));
			return (glm::acos(glm::dot(da, db)) * 180.0 / M_PI);
		}
		static double Magnitude(Vector3 a)
		{
			return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
		}
		static Vector3 Normalized(Vector3 a)
		{
			return (a / Vector3::Magnitude(a));
		}
};

#endif