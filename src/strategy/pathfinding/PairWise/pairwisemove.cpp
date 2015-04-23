#include "pairwisemove.h"


PairWiseMove::PairWiseMove(){}

std::vector<WayPoint>PairWiseMove::quadCopterPairRoute(std::vector<WayPoint> atvRoute,
                                  ATV atv,
                                  quadCopter copter){
    std::vector<WayPoint> quadRoute;
    if(copter.x != atv.x || copter.y != atv.y){
        quadRoute.push_back(WayPoint(atv.x,atv.y));
        copter.goTo(atv.x, atv.y);
    }
    for(int i = 0; i < atvRoute.size(); i++){
        int atvPosX = atvRoute[i].x;
        int atvPosY = atvRoute[i].y;

        if(!copter.inView(atvPosX, atvPosY)){
            quadRoute.push_back(WayPoint(atvPosX,atvPosY));
            copter.goTo(atvPosX, atvPosY);
        }

        atv.goTo(atvPosX, atvPosY);
    }
    return quadRoute;
}
