/*
 * Square.cpp
 *
 *  Created on: 9-jan.-2015
 *      Author: Pieter
 */
#include "Square.h"
#include "util/Point.h"

HitInfo Square::intersection(const Ray & ray){
	if(ray.getDir().z == 0){
		return HitInfo();
	}
	double t = (-1*ray.getStart().z)/(ray.getDir().z);
	if(t<0){
		return HitInfo();
	}

	Point hitPoint;
	Point p = ray.getPoint(t);

	if(p.z == 0 && p.x <=1 && p.y <=1 && p.x >= -1 && p.y >= -1){
		hitPoint = p;
	} else {
		return HitInfo();
	}

	return HitInfo(t, hitPoint, mtrl, Vector(p));

}
