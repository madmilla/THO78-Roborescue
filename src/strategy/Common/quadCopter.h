#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "dimension.h"

class QuadCopter
{
public:
    QuadCopter(Dimension copter, Dimension copterSight,int x,int y);
    ~QuadCopter();

    void goTo(int x, int y);
    bool inView(int x, int y);

    Dimension copter;
    Dimension copterSight;
    int x,y;
};

#endif // QUADCOPTER_H
