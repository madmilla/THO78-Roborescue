#include "../../../Common/QuadCopter.h"
#include "../../../Common/ATV.h"
#include "../../../Common/dimension.h"
#include "../../../pathfinding/PairWise/pairwisemove.h"
#include <iostream>
#include "../../../Map/MapStructure/map.hpp"

#define TEST

#ifdef TEST
int main()
{
    std::cout << "ikbenhier";
    PairWiseMove move;

    Dimension atvsize(1,1);
    Dimension coptersize(1,1);
    Dimension searchSize(2,2);
    QuadCopter copter(coptersize,searchSize,4,4);
    ATV atv(atvsize, 0, 0);
    map mapp;


    Route atvRoute;
    //atvRoute.push_back(WayPoint(1, 1));


    Route * result = move.generatePairRoute(atvRoute, atv, copter, mapp )->first;

    bool error = false;

    if(result->getSize() == 1){ //Quad must move te atv
        if(!(result->getWaypoint(0)->x == 0 && result->getWaypoint(0)->y == 0)){
            error = true;
            std::cout << "Quad must move to atv waypoint ERROR" << std::endl;
        }
        std::cout << "Quad must move te atv SUCCES" << std::endl;
    }
    else{
        std::cout << "Quad must move te atv size ERROR" << std::endl;
    }

    copter = QuadCopter(coptersize,searchSize,0,0);
    atv = ATV(atvsize, 0, 0);
    atvRoute.clearRoute();
    atvRoute.pushWayPoint( new WayPoint(1, 1));

    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;


    if(!(result->getSize() == 0)){ //Atv is just in range of quadsight
            error = true;
            std::cout << "Atv is just in range of quadsight ERROR"<< std::endl;
    }else{
        std::cout << "Atv is just in range of quadsight SUCCES"<< std::endl;
    }

    atvRoute.clearRoute();
    atvRoute.pushWayPoint( new WayPoint(2, 2));

    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;
    if(result->getSize() == 1){ //Atv is just out range of quadsight
        if(!(result->getWaypoint(0)->x == 2 && result->getWaypoint(0)->y == 2)){
            error = true;
            std::cout << "Atv is just out range of quadsight waypoint ERROR"<< std::endl;
        }
        std::cout << "Atv is just out range of quadsight SUCCES" << std::endl;
    }
    else{
        std::cout << "Atv is just out range of quadsight size ERROR"<< std::endl;
    }

    atvRoute.clearRoute();
    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;
    if(!result->getSize() == 0){//Empty atv route returns...
       error = true;
       std::cout << "Empty atv route returns empty pair route ERROR"<< std::endl;
    }else{
        std::cout << "Empty atv route returns empty pair route SUCCES"<< std::endl;
    }

    copter.goTo(1, 4);
    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;
    if(!result->getSize() == 1){//Empty atv route returns...
       error = true;
       std::cout << "Empty atv route returns sync waypoint size ERROR"<< std::endl;
    }
    else{
        if(result->getWaypoint(0)->x == 0 && result->getWaypoint(0)->y == 0){
            std::cout << "Empty atv route returns sync waypoint SUCCES"<< std::endl;
        }
        else{
            error = true;
            std::cout << "Empty atv route returns sync waypoint waypoint ERROR"<< std::endl;
        }
    }

    copter.goTo(0,0);
    atvRoute.pushWayPoint(new WayPoint(1, 2));
    atvRoute.pushWayPoint(new WayPoint(2, 3));
    atvRoute.pushWayPoint(new WayPoint(4, 2));
    atvRoute.pushWayPoint(new WayPoint(5, 3));
    atvRoute.pushWayPoint(new WayPoint(-1, -1));
    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;
    if(result->getSize() == 3){//Longer route
        std::cout << "Long route size: Good, SUCCES" << std::endl;
        if(!(result->getWaypoint(0)->x == 1 && result->getWaypoint(0)->y == 2)){
            error = true;
            std::cout << "  Point 1,2 ERROR" << std::endl;
        }
        else{
            std::cout << "  Point 1,2 SUCCES" << std::endl;
        }
        if(!(result->getWaypoint(1)->x == 4 && result->getWaypoint(1)->y == 2)){
            error = true;
            std::cout << "  Point 4,2 ERROR" << std::endl;
        }
        else{
            std::cout << "  Point 4,2 SUCCES" << std::endl;
        }
        if(!(result->getWaypoint(2)->x == -1 && result->getWaypoint(2)->y == -1)){
            error = true;
            std::cout << "  Point -1,-1 ERROR" << std::endl;
        }
        else{
            std::cout << "  Point -1,-1 SUCCES" << std::endl;
        }
    }
    else{
        error = true;
        std::cout << "Long route size: fault, ERROR" << std::endl;
    }

    return error;
}
#else

int main(int argc, char *argv[])
{

}
#endif
