#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "util/Point.h"
#include "util/Vector.h"
#include <cmath>

#define PI 3.14159265

class Quaternion{

public:

	double a,b,c,d;

	Quaternion(double a, double b, double c, double d): a(a), b(b), c(c), d(d){}
	Quaternion(const Point & p);
	Quaternion(double angle, Vector r);
	friend Quaternion operator*(const Quaternion & q1, const Quaternion & q);
	Quaternion conjugate();
};


#endif /* QUATERNION_H_ */
