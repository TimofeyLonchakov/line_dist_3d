#pragma once

#include "point3d.h"

class Vector3D;

class Segment3D
{
public:
	Segment3D(const Point3D& ptStart,
		const Point3D& ptEnd);

public:
	double squareLength() const;
	Segment3D offset(const Vector3D& vec) const;
	double computeDistance(const Segment3D& seg) const;

public:
	Point3D start, end;
};