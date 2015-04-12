#ifndef AFACE_H_
#define AFACE_H_

#include "shape/mesh/IFace.h"

class AFace: public IFace {

public:
	virtual HitInfo intersection(const Ray & ray);
	virtual ~AFace(){ };
	bool hit(const Ray& ray) const;
	double getT(const Ray& ray) const;
protected:
	virtual Vector getHitNormal(const Point & hitPoint) = 0;
};

#endif /* AFACE_H_ */
