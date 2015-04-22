#include "checkpoint.h"

checkPoint::checkPoint(int x, int y):
    checkPointx(x),
    checkPointy(y)
{}

void checkPoint::setCoordinates(int x, int y){
    checkPointx = x;
    checkPointy = y;
}

void checkPoint::setX(int x){
    checkPointx = x;
}

void checkPoint::setY(int y){
    checkPointy = y;
}

int checkPoint::getX(){
    return checkPointx;
}

int checkPoint::getY(){
    return checkPointy;
}

checkPoint::~checkPoint()
{}
