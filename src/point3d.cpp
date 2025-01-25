#include "point3d.h"
#include "vector3d.h"
#include "segment3d.h"

#include <cmath>

using namespace std;

Point3D::Point3D(double x,
	double y,
	double z)
	: X(x)
	, Y(y)
	, Z(z)
{
}

Point3D Point3D::offset(const Vector3D& vec) const
{
	return Point3D(X + vec.X, Y + vec.Y, Z + vec.Z);
}

double Point3D::squareDistance(const Point3D& pt) const
{
	const double dx = (X - pt.X);
	const double dy = (Y - pt.Y);
	const double dz = (Z - pt.Z);

	return (dx * dx + dy * dy + dz * dz);
}

double Point3D::distanceToProjSq(const Segment3D& segment) const
{
	const double lineSqLen = segment.squareLength();
	if (0.0 == lineSqLen)
	{
		return squareDistance(segment.start);
	}

	const double dot =
		Vector3D::dotProduct(
			Vector3D(segment.start, (*this)),
			Vector3D(segment.start, segment.end));
	if (0.0 == dot)
	{
		return squareDistance(segment.start);
	}
	if (0.0 > dot)
	{
		return -1.0;
	}

	const double distToStartSq = squareDistance(segment.start);
	const double distStartToProjSq = (dot * dot / lineSqLen);
	const double distanceSq =
		(distToStartSq - distStartToProjSq);

	if (0.0 >= distanceSq)
	{
		return 0.0;
	}

	return distanceSq;
}