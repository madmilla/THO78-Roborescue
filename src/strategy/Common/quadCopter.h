#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "dimension.h"

class quadCopter
{
public:
    quadCopter(Dimension copter, Dimension copterSight,int x,int y);
    ~quadCopter();

    void goTo(int x, int y);
    bool inView(int x, int y);

    Dimension copter;
    Dimension copterSight;
    int x,y;
};

#endif // QUADCOPTER_H
