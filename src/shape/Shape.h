#ifndef SHAPE_H_
#define SHAPE_H_

#include "shape/IRaytraceable.h"
#include "shading/Material.h"

class Shape: public IRaytraceable {

protected:

	Material mtrl;

public:

	Shape(){ }

	const Material& getMaterial() const { return mtrl; }

	void setMaterial(const Material& mtrl) { this->mtrl = mtrl; }
};

#endif /* SHAPE_H_ */
