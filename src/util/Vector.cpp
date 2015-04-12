#include "Vector.h"
#include <cmath>

Vector::Vector(const Point & from, const Point & to){
	x = to.x-from.x;
	y = to.y-from.y;
	z = to.z-from.z;
}

Vector operator*(const Vector & v, double a){
	return Vector(v.x*a, v.y*a, v.z*a);
}

Vector operator*(double a, const Vector & v){
	return v*a;
}

Point operator+(const Point & p, const Vector & v){
	return Point(p.x+v.x, p.y+v.y, p.z+v.z);
}

Point operator+(const Vector & v, const Point & p){
	return p+v;
}

Vector operator+(const Vector & v1, const Vector & v2){
	return Vector(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

double Vector::dot(const Vector & v){
	return this->x*v.x + this->y*v.y + this->z*v.z;
}

Vector Vector::cross(const Vector& v){
	return Vector(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

double Vector::length(){
	return sqrt(pow(this->x,2) + pow(this->y,2) + pow(this->z,2));
}

void Vector::normalize(){
	this->x = this->x/length();
	this->y = this->y/length();
	this->z = this->z/length();
}
