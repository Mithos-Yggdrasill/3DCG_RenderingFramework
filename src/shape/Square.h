#ifndef SQUARE_H_
#define SQUARE_H_

#include "shape/Shape.h"

class Square : public Shape {

public:

	virtual HitInfo intersection(const Ray & ray);

};


#endif /* SQUARE_H_ */
