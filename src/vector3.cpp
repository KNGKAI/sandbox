#include "vector3.h"
#include "camera.h"
#include "renderer.h"

Vector3 Vector3::operator+(const Vector3 &rhs) const { return Vector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z); }
Vector3 Vector3::operator-(const Vector3 &rhs) const { return Vector3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z); }
Vector3 Vector3::operator*(const Vector3 &rhs) const { return Vector3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z); }
Vector3 Vector3::operator/(const Vector3 &rhs) const { return Vector3(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z); }

Vector3 Vector3::operator+(const double &rhs) const { return Vector3(this->x + rhs, this->y + rhs, this->z + rhs); }
Vector3 Vector3::operator-(const double &rhs) const { return Vector3(this->x - rhs, this->y - rhs, this->z - rhs); }
Vector3 Vector3::operator*(const double &rhs) const { return Vector3(this->x * rhs, this->y * rhs, this->z * rhs); }
Vector3 Vector3::operator/(const double &rhs) const { return Vector3(this->x / rhs, this->y / rhs, this->z / rhs); }

Vector3 &Vector3::operator+=(const Vector3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

Vector3 &Vector3::operator*=(const Vector3 &rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	return *this;
}

Vector3 &Vector3::operator/=(const Vector3& rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	return *this;
}

Vector3 Vector3::RotateX(Vector3 point, double angle)
{
	double s = sin(angle * M_PI / 180.0);
	double c = cos(angle * M_PI / 180.0);
	return (Vector3(point.x, point.y * c + point.z * s, point.z * c + point.y * s));
}

Vector3 Vector3::RotateY(Vector3 point, double angle)
{
	double s = sin(angle * M_PI / 180.0);
	double c = cos(angle * M_PI / 180.0);
	return (Vector3(point.x * c - point.z * s, point.y, point.z * c + point.x * s));
}

Vector3 Vector3::RotateZ(Vector3 point, double angle)
{
	double s = sin(angle * M_PI / 180.0);
	double c = cos(angle * M_PI / 180.0);
	return (Vector3(point.x * c - point.z * s, point.y * c + point.x * s, point.z));
}

Vector3 Vector3::Rotate(Vector3 point, Vector3 angles)
{
	point = RotateX(point, angles.x);
	point = RotateZ(point, angles.z);
	point = RotateY(point, angles.y);
	return (point);
}

Vector3 Vector3::ToScreenSpace(Vector3 a)
{
	Vector3 v;
	int width, height;

	v = a - Camera::transform.position;
	v = Vector3::Rotate(v, Camera::transform.rotation);
	glfwGetWindowSize(Renderer::window(), &width, &height);
	double r = (double)(height) / width;
	return (Vector3(
		(Camera::surface.z / v.z * v.x + Camera::surface.x) * r,
		(Camera::surface.z / v.z * v.y + Camera::surface.y),
		0.0));
}

Vector3 Vector3::TriangleNormal(Vector3 a, Vector3 b, Vector3 c)
{
	Vector3 u;
	Vector3 v;
	Vector3 normal;

	u = b - a;
	v = c - a;
	normal.x = (u.y * v.z) - (u.z * v.y);
	normal.y = (u.z * v.x) - (u.x * v.z);
	normal.z = (u.x * v.y) - (u.y * v.x);
	return (normal);
}
bool Vector3::Render(Vector3 a, Vector3 b, Vector3 c)
{
	a -= Camera::transform.position;
	a = Vector3::Rotate(a, Camera::transform.rotation);
	b -= Camera::transform.position;
	b = Vector3::Rotate(b, Camera::transform.rotation);
	c -= Camera::transform.position;
	c = Vector3::Rotate(c, Camera::transform.rotation);
	return (Vector3::TriangleNormal(a, b, c).z < 0);
}