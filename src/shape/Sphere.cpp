#include "Sphere.h"
#include <cmath>

HitInfo Sphere::intersection(const Ray & ray){
	double a = Vector(ray.getDir()).dot(Vector(ray.getDir()));
	double b = 2*Vector(ray.getStart()).dot(ray.getDir());
	double c = Vector(ray.getStart()).dot(Vector(ray.getStart()))-1;

	double discr = pow(b,2) - 4*a*c;

	double t1 =(-b-sqrt(discr))/(2*a);
	double t2 =(-b+sqrt(discr))/(2*a);
	double t = t2;

	if (t1<t2){
		if(t1 >= 0){
			t = t1;
		}
	}

	Point intersect = ray.getPoint(t);

	return HitInfo(t, intersect, mtrl, Vector(intersect));
}

