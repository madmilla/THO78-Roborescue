#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "dimension.h"

class QuadCopter
{
public:
    QuadCopter(Dimension copter, Dimension copterSight,int x,int y);
    ~QuadCopter();
    Dimension copter;
    Dimension copterSight;
    int x,y;
};

#endif // QUADCOPTER_H
