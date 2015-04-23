#include "quadCopter.h"

quadCopter::quadCopter(Dimension copter, Dimension copterSight, int x, int y):
copter{copter},
  copterSight{copterSight},
x{x},
y{y}
{

}

quadCopter::~quadCopter()
{

}

void quadCopter::goTo(int x, int y){
    this->x = x;
    this->y = y;
}

bool quadCopter::inView(int x, int y){
    if(((this->x) -(copterSight.width/2) <= x) && ((this->x) + (copterSight.width/2) >= x)){
        if(((this->y) - (copterSight.height/2) <= y) && ((this->y) + copterSight.height/2) >= y){
            return true;
        }
    }
    return false;
}
