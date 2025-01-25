#pragma once

#include "point3d.h"

class Vector3D : public Point3D
{
public:
	Vector3D(const Point3D& fromOrigin = Point3D());
	Vector3D(const Point3D& start,
		const Point3D& end);

public:
	Vector3D operator*(double val) const;
	Vector3D operator+(const Vector3D& vec) const;
	bool isNull() const;
	double squareLength() const;
	double length() const;
	Vector3D normalized() const;

public:
	static Vector3D crossProduct(const Vector3D& from,
		const Vector3D& to);
	static double dotProduct(const Vector3D& one,
		const Vector3D& two);
};
