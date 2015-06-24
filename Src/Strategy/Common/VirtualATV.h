#ifndef ATV_H
#define ATV_H

#include "dimension.h"
#include "waypoint.h"

class VirtualATV{
public:
    VirtualATV(Dimension size, int x, int y);

    void goTo(int x, int y);
    void goTo(WayPoint* waypoint);

    // Getters
    Dimension getSize() { return size; }
    int getX() { return x; }
    int getY() { return y; }

    // Setters
    void setSize(Dimension size) { this->size = size; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
private:
    Dimension size;
    int x;
    int y;
};

#endif //ATV_H
