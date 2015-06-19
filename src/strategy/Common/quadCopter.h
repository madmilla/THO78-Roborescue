#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "dimension.h"

class QuadCopter
{
public:
    QuadCopter(Dimension size, Dimension fov, int x, int y);
    ~QuadCopter();

    void goTo(int x, int y);
    bool inView(int x, int y);

    // Getters
    Dimension getSize() { return size; };
    Dimension getFov() { return fov; };
    int getX() { return x; };
    int getY() { return y; };
private:
    Dimension size;
    Dimension fov;
    int x;
    int y;
};

#endif // QUADCOPTER_H
