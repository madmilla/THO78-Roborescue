#include "testcopter.h"

TestCopter::TestCopter(Dimension copter, Dimension copterSight, int x, int y):
copter{copter},
  copterSight{copterSight},
x{x},
y{y}
{

}

TestCopter::~TestCopter()
{

}

void TestCopter::goTo(int x, int y){
    this->x = x;
    this->y = y;
}

bool TestCopter::inView(int x, int y){
    if(((this->x) -(copterSight.width/2) <= x) && ((this->x) + (copterSight.width/2) >= x)){
        if(((this->y) - (copterSight.height/2) <= y) && ((this->y) + copterSight.height/2) >= y){
            return true;
        }
    }
    return false;
}
