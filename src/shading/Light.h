#ifndef LIGHT_H_
#define LIGHT_H_

#include "util/Point.h"
#include "util/Colour.h"

class Light {
private:

	Point pos;

	Colour colour;

public:

	Light(Point pos, Colour colour):pos(pos),colour(colour){}

	void setPosition(const Point & p){ this->pos = p;}

	const Point & getPosition() const { return this->pos;}

	void setColour(const Colour & c){this->colour = c;}

	const Colour & getColour() const {return this->colour;}
};

#endif /* LIGHT_H_ */
