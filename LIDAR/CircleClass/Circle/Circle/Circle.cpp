#include "Circle.h"

Circle::Circle(int originX, int originY, int radius) :
originX{ originX },
originY{ originY },
radius{ radius }
{}

Circle::~Circle()
{

}

void Circle::setCircle(int x, int y, int r) {
	originX = x;
	originY = y;
	radius = r;
}

Circle::origins Circle::getOrigin() {
	origins origin;
	origin.originX = originX;
	origin.originY = originY;
	return origin;
}

int Circle::getRadius() {
	return radius;
}

