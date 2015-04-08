#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>

class Circle
{
public:
    Circle(originX, originX, radius);
    ~Circle();

    void setCircle(int originX, int originY, int radius);
    std::vector getOrigin();
    int getRadius();

private:
    int originX;
    int originY;
    int radius;
};

#endif // CIRCLE_H
