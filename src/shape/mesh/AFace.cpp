#include "AFace.h"
#include "util/Vector.h"
#include "util/Point.h"
#include <cmath>

HitInfo AFace::intersection(const Ray & ray){
	Vector m = getFacePlaneNormal();
	if (std::abs(m.dot(ray.getDir()) < 0.0000001)){
		return 0;
	}
	double t = (m.dot(Vector(ray.getStart(),getVertex(0))))/(m.dot(ray.getDir()));
	if (t < 0){
		return 0;
	}

	Point hitPoint = ray.getPoint(t);

	Vector v1, v2, v3;
	for (unsigned i; i < 3; i++){
		v1 = Vector(getVertex(i), getVertex((i+1)%3));
		v2 = Vector(getVertex(i), hitPoint);
		v3 = v1.cross(v2);
		if(v3.dot(m) >= 0){
			return 0;
		}
	}

	return HitInfo(t, hitPoint, Material(), getFacePlaneNormal());
}
