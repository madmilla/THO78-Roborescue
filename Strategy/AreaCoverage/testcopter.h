#ifndef TESTCOPTER_H
#define TESTCOPTER_H
#include "dimension.h"
class TestCopter
{
public:
    TestCopter(Dimension copter, Dimension copterSight,int x,int y);
    ~TestCopter();
    Dimension copter;
    Dimension copterSight;
    int x,y;
};

#endif // TESTCOPTER_H
