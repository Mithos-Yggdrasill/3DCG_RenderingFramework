#include "Quaternion.h"

Quaternion::Quaternion(const Point & p){
	a = 0;
	b = p.x;
	c = p.y;
	d = p.z;
}

Quaternion::Quaternion(double angle, Vector r){
	a = cos(angle/2*PI/180);
	b = sin(angle/2*PI/180)*r.x;
	c = sin(angle/2*PI/180)*r.y;
	d = sin(angle/2*PI/180)*r.z;
}

Quaternion operator*(const Quaternion & q1, const Quaternion & q2){
	double a,b,c,d;
	a = q1.a * q2.a - q1.b * q2.b - q1.c * q2.c - q1.d * q2.d;
	b = q1.a * q2.b + q1.b * q2.a + q1.c * q2.d - q1.d * q2.c;
	c = q1.a * q2.c - q1.b * q2.d + q1.c * q2.a + q1.d * q2.b;
	d = q1.a * q2.d + q1.b * q2.c - q1.c * q2.b + q1.d * q2.a;
	return Quaternion(a,b,c,d);
}

Quaternion Quaternion::conjugate(){
	double a,b,c,d;
	a = this->a;
	b = this->b*(-1);
	c = this->c*(-1);
	d = this->d*(-1);
	return Quaternion(a,b,c,d);
}
