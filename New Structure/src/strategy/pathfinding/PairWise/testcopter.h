#include "QRect"
#include "dimension.h"

#ifndef TESTCOPTER_H
#define TESTCOPTER_H

class TestCopter
{
public:
    TestCopter(Dimension copter, Dimension copterSight,int x,int y);
    ~TestCopter();

    void goTo(int x, int y);
    bool inView(int x, int y);

    Dimension copter;
    Dimension copterSight;
    int x,y;
};

#endif // TESTCOPTER_H
