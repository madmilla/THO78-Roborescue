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

Circle::circleData Circle::getCircle() {
	circleData circleData;
	circleData.originX = originX;
	circleData.originY = originY;
	circleData.radius = radius;
	return circleData;
}


