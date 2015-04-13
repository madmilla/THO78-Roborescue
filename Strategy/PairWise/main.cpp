#include "testcopter.h"
#include "testatv.h"
#include "dimension.h"
#include "pairwisemove.h"
#include <iostream>

int main()
{
    PairWiseMove move;

    Dimension atvsize(1,1);
    Dimension coptersize(1,1);
    Dimension searchSize(2,2);
    TestCopter copter(coptersize,searchSize,4,4);
    testATV atv(atvsize, 0, 0);

    std::vector<WayPoint> atvRoute;
    //atvRoute.push_back(WayPoint(1, 1));


    std::vector<WayPoint> result = move.quadCopterPairRoute(atvRoute, atv, copter );

    bool error = false;

    if(result.size() == 1){ //Quad must move te atv
        if(!(result[0].x == 0 && result[0].y == 0)){
            error = true;
            std::cout << "Quad must move te atv ERROR" << std::endl;
        }
        std::cout << "Quad must move te atv SUCCES" << std::endl;
    }

    copter = TestCopter(coptersize,searchSize,0,0);
    atv = testATV(atvsize, 0, 0);
    atvRoute.clear();
    atvRoute.push_back(WayPoint(1, 1));

    result = move.quadCopterPairRoute(atvRoute, atv, copter );


    if(!(result.size() == 0)){ //Atv is just in range of quadsight
            error = true;
            std::cout << "Atv is just in range of quadsight ERROR"<< std::endl;
    }else{
        std::cout << "Atv is just in range of quadsight SUCCES"<< std::endl;
    }

    atvRoute.clear();
    atvRoute.push_back(WayPoint(2, 2));

    result = move.quadCopterPairRoute(atvRoute, atv, copter );
    if(result.size() == 1){ //Atv is just out range of quadsight
        if(!(result[0].x == 2 && result[0].y == 2)){
            error = true;
            std::cout << "Atv is just out range of quadsight ERROR"<< std::endl;
        }
        std::cout << "Atv is just out range of quadsight SUCCES" << std::endl;
    }

    atvRoute.clear();
    result = move.quadCopterPairRoute(atvRoute, atv, copter );
    if(!result.size() == 0){//Empty atv route returns...
       error = true;
       std::cout << "Empty atv route returns empty pair route ERROR"<< std::endl;
    }
    std::cout << "Empty atv route returns empty pair route SUCCES"<< std::endl;

    atvRoute.push_back(WayPoint(1, 2));
    atvRoute.push_back(WayPoint(2, 3));
    atvRoute.push_back(WayPoint(4, 2));
    atvRoute.push_back(WayPoint(5, 3));
    atvRoute.push_back(WayPoint(-1, -1));
    result = move.quadCopterPairRoute(atvRoute, atv, copter );
    if(result.size() == 3){//Longer route
        std::cout << "Long route size: Good, SUCCES" << std::endl;
        if(!(result[0].x == 1 && result[0].y == 2)){
            error = true;
            std::cout << "Point 1,2 ERROR" << std::endl;
        }
        else{
            std::cout << "Point 1,2 SUCCES" << std::endl;
        }
        if(!(result[1].x == 4 && result[1].y == 2)){
            error = true;
            std::cout << "Point 4,2 ERROR" << std::endl;
        }
        else{
            std::cout << "Point 4,2 SUCCES" << std::endl;
        }
        if(!(result[2].x == -1 && result[2].y == -1)){
            error = true;
            std::cout << "Point -1,-1 ERROR" << std::endl;
        }
        else{
            std::cout << "Point -1,-1 SUCCES" << std::endl;
        }
    }
    else{
        error = true;
        std::cout << "Long route size: fault, ERROR" << std::endl;
    }

    return error;
}
