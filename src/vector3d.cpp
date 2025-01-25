#include "vector3d.h"
#include "consts.h"

#include <cmath>

using namespace std;

Vector3D::Vector3D(const Point3D& fromOrigin)
	: Point3D(fromOrigin)
{
}

Vector3D::Vector3D(const Point3D& start,
	const Point3D& end)
	: Point3D((end.X - start.X), (end.Y - start.Y), (end.Z - start.Z))
{
}

Vector3D Vector3D::operator*(double val) const
{
	return Vector3D(Point3D(X * val, Y * val, Z * val));
}

Vector3D Vector3D::operator+(const Vector3D& vec) const
{
	return Vector3D(Point3D(X * vec.X, Y * vec.Y, Z * vec.Z));
}

bool Vector3D::isNull() const
{
	return (INACCURACY_SQUARE >= squareLength());
}

double Vector3D::squareLength() const
{
	return (X * X + Y * Y + Z * Z);
}

double Vector3D::length() const
{
	return sqrt(squareLength());
}

Vector3D Vector3D::normalized() const
{
	const double len = length();

	if (INACCURACY >= len)
	{
		return Vector3D();
	}

	return Vector3D(Point3D(X / len, Y / len, Z / len));
}

Vector3D Vector3D::crossProduct(const Vector3D& from,
	const Vector3D& to)
{
	return Vector3D(Point3D(
		(from.Y * to.Z - from.Z * to.Y),
		(from.Z * to.X - from.X * to.Z),
		(from.X * to.Y - from.Y * to.X)));
}

double Vector3D::dotProduct(const Vector3D& one,
	const Vector3D& two)
{
	return ((one.X * two.X) + (one.Y * two.Y) + (one.Z * two.Z));
}