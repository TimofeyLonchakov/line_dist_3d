#include "segment3d.h"

#include <iostream>

using namespace std;

static const Segment3D segmentOne(Point3D(-1.0, -1.0, -1.0), Point3D(1.0, 1.0, -1.0));
static const Segment3D segmentTwo(Point3D(1.0, 3.0, -1.0), Point3D(3.0, 1.0, -1.0));

int main()
{
	cout << "Distance = " << segmentOne.computeDistance(segmentTwo) << endl;

	return 0;
}
