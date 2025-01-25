#include "segment3d.h"
#include "vector3d.h"

#include <cmath>

using namespace std;

Segment3D::Segment3D(const Point3D& ptStart,
	const Point3D& ptEnd)
	: start(ptStart)
	, end(ptEnd)
{
}

double Segment3D::squareLength() const
{
	return start.squareDistance(end);
}

Segment3D Segment3D::offset(const Vector3D& vec) const
{
	return Segment3D(
		start.offset(vec),
		end.offset(vec));
}

double Segment3D::computeDistance(const Segment3D& seg) const
{
	const Vector3D vecOne(start, end);
	const Vector3D vecTwo(seg.start, seg.end);
	const Vector3D planeNormal(
		Vector3D::crossProduct(vecOne, vecTwo).normalized());
	const bool samePlane = planeNormal.isNull();

	const double planeDistance =
		(samePlane
			? 0.0
			: Vector3D::dotProduct(Vector3D(seg.start, start),
				planeNormal));
	const Vector3D planeOffset =
		(samePlane
			? Vector3D()
			: (planeNormal * planeDistance));

	const Segment3D segmentTwoProj(seg.offset(planeOffset));

	if ((0.0 >= Vector3D::dotProduct(
		Vector3D::crossProduct(
			Vector3D(start, segmentTwoProj.start),
			Vector3D(start, end)),
		Vector3D::crossProduct(
			Vector3D(start, segmentTwoProj.end),
			Vector3D(start, end)))) &&
		(0.0 >= Vector3D::dotProduct(
			Vector3D::crossProduct(
				Vector3D(segmentTwoProj.start, start),
				Vector3D(segmentTwoProj.start, segmentTwoProj.end)),
			Vector3D::crossProduct(
				Vector3D(segmentTwoProj.start, end),
				Vector3D(segmentTwoProj.start, segmentTwoProj.end)))))
	{
		return fabs(planeDistance);
	}

	const double distancesSq[] =
	{
		segmentTwoProj.start.distanceToProjSq(*this),
		segmentTwoProj.end.distanceToProjSq(*this),
		start.distanceToProjSq(segmentTwoProj),
		end.distanceToProjSq(segmentTwoProj),
		segmentTwoProj.start.squareDistance(start),
		segmentTwoProj.start.squareDistance(end),
		segmentTwoProj.end.squareDistance(start),
		segmentTwoProj.end.squareDistance(end)
	};

	double distanceSq = -1.0;
	for (int index = 0; index < sizeof(distancesSq) / sizeof(distancesSq[0]); ++index)
	{
		if (0.0 > distancesSq[index])
		{
			continue;
		}
		if (0.0 == distancesSq[index])
		{
			return 0.0;
		}
		if ((0.0 > distanceSq) ||
			(distancesSq[index] < distanceSq))
		{
			distanceSq = distancesSq[index];
		}
	}

	if (0.0 <= distanceSq)
	{
		return sqrt((planeDistance * planeDistance) + distanceSq);
	}

	return -1.0;
}