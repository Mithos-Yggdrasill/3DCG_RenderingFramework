#ifndef HITINFO_H_
#define HITINFO_H_

#include "util/Point.h"
#include "util/Vector.h"
#include "shading/Material.h"
#include <cfloat>

class HitInfo {

	double t;
	Point hitPoint;
	Material hitMaterial;
	Vector hitNormal;

	void copy(const HitInfo & hitInfo);

public:

	HitInfo(double t=DBL_MAX):t(t){}

	HitInfo(double t, const Point & p, const Material & m, const Vector h):t(t), hitPoint(p), hitMaterial(m), hitNormal(h) { }

	HitInfo(const HitInfo & hitInfo);

	HitInfo& operator=(const HitInfo & hitInfo);

	double getT() const { return t; }

	void setT(double t) { this->t = t; }

	const Point& getHitPoint() const { return hitPoint; }

	void setHitPoint(const Point& hitPoint) { this->hitPoint = hitPoint; }

	const Material& getHitMaterial() const { return hitMaterial; }

	void setHitMaterial(const Material& hitMaterial) { this->hitMaterial = hitMaterial; }

	const Vector& getHitNormal() const { return hitNormal; }

	void setHitNormal(const Vector& hitNormal) { this->hitNormal = hitNormal; }

};

#endif /* HITINFO_H_ */
