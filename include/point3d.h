#pragma once

class Vector3D;
class Segment3D;

class Point3D
{
public:
	Point3D(double x = 0.0,
		double y = 0.0,
		double z = 0.0);

public:
	Point3D offset(const Vector3D& vec) const;
	double squareDistance(const Point3D& pt) const;
	double distanceToProjSq(const Segment3D& segment) const;

public:
	double X, Y, Z;
};