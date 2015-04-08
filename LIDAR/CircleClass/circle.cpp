#include "circle.h"

Circle::Circle(int originX, int originY, int radius):
    originX{originX},
    originY{originY},
    radius{radius}
{}

Circle::~Circle()
{

}

void Circle::setCircle(int originX, int originY, int radius) {
    originX = originX;
    originY = originY;
    radius = radius;
}

std::vector Circle::getOrigin() {
    std::vector<int> origin (originX, originY);
    return origin;
}

int getRadius() {
    return radius;
}

