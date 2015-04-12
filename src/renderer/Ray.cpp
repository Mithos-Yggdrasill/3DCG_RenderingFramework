/*
 * ray.cpp
 *
 *  Created on: 8-jan.-2015
 *      Author: Pieter
 */
#include "Ray.h"

Point Ray::getPoint(double t) const {
	return this->getStart() + t*this->getDir();
}



