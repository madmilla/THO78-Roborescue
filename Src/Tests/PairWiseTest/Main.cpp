#include "VirtualQuadCopter.h"
#include "VirtualATV.h"
#include "Dimension.h"
#include "PairWiseMove.h"
#include <iostream>
#include "Map.hpp"


int main()
{
    PairWiseMove move;

    Dimension atvsize(1,1);
    Dimension coptersize(1,1);
    Dimension searchSize(2,2);
    VirtualQuadCopter copter(coptersize,searchSize,4,4);
    VirtualATV atv(atvsize, 1, 1);
    Map mapp;
    Route atvRoute;
	bool error = false;

   
	Route * result = move.generatePairRoute(atvRoute, atv, copter, mapp )->first;

    if(result->getSize() > 0){ //Quad must move te atv
		if (!(result->getWaypoint(result->getSize() -1 ) == WayPoint(1, 1))){
            error = true;
            std::cout << "Quad must move to atv *waypoint* ERROR" << std::endl;
        }
		else{
			std::cout << "Quad must move te atv SUCCES" << std::endl;
		}
    }
    else{
		error = true;
        std::cout << "Quad must move te atv route *size* ERROR" << std::endl;
    }



	copter.goTo(1, 1);
    atv.goTo(2, 2);
    atvRoute.clearRoute();
    atvRoute.pushWayPoint(WayPoint(1, 1));
    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;

	if (result->getSize() == 1){//Atv is just in range of quadsight
		if (!(result->getWaypoint(result->getSize() - 1) == WayPoint(1, 1))){ 
			error = true;
			std::cout << "Atv is just in range of quadsight *waypoint* ERROR" << std::endl;
		}
		else{
			std::cout << "Atv is just in range of quadsight SUCCES" << std::endl;
		}
	}
	else{
		error = true;
		std::cout << "Atv is just in range of quadsight route *size* ERROR" << std::endl;
	}



    atvRoute.clearRoute();
    atvRoute.pushWayPoint(WayPoint(3, 3));
    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;

    if(result->getSize() == 4){ //Atv moves just out range of quadsight
        if(!(result->getWaypoint(result->getSize() -1) == WayPoint(3, 3))){
            error = true;
            std::cout << "Atv moves just out range of quadsight *waypoint* ERROR"<< std::endl;
        }
		else{
			std::cout << "Atv moves just out range of quadsight SUCCES" << std::endl;
		}
    }
    else{
		error = true;
        std::cout << "Atv moves just out range of quadsight route *size* ERROR"<< std::endl;
    }




    atvRoute.clearRoute();
    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;

    if(result->getSize() != 0){//Empty atv route returns...
       error = true;
       std::cout << "Empty atv route returns empty routePair *route* ERROR"<< std::endl;
    }else{
        std::cout << "Empty atv route returns empty routePair SUCCES"<< std::endl;
    }



    copter.goTo(1, 4); //ATV just outside Quadview
    result = move.generatePairRoute(atvRoute, atv, copter, mapp)->first;

    if(result->getSize() == 3){//Empty atv route returns.. but quad must move
		if ((result->getWaypoint(result->getSize() - 1)) == WayPoint(2, 2)){
			std::cout << "Empty atv route returns sync waypoint SUCCES" << std::endl;
		}
		else{
			error = true;
			std::cout << "Empty atv route returns sync waypoint *waypoint* ERROR" << std::endl;
		}
    }
    else{
		error = true;
		std::cout << "Empty atv route returns sync waypoint *size* ERROR" << std::endl;
    }



	atv.goTo(1, 1);
	copter.goTo(1, 1);
	atvRoute.clearRoute();
	move.movePairWise(atvRoute, atv, copter, mapp);
	//Empty atvRoute in MovePairWise..
	if (atv.getPosition() == WayPoint(1, 1) && copter.getPosition() == WayPoint(1, 1)){
		std::cout << "Empty atv route in movePairWise does nothing SUCCES" << std::endl;
	}
	else{
		if (atv.getPosition() != WayPoint(1, 1)){
			error = true;
			std::cout << "Empty atv route in movePairWise does nothing *ATV* ERROR" << std::endl;
		}
		if(copter.getPosition() != WayPoint(1,1)){
			error = true;
			std::cout << "Empty atv route in movePairWise does nothing *quadcopter* ERROR" << std::endl;
		}
	}



    atvRoute.pushWayPoint(WayPoint(1, 2));
    atvRoute.pushWayPoint(WayPoint(2, 3));
    atvRoute.pushWayPoint(WayPoint(4, 2));
    atvRoute.pushWayPoint(WayPoint(5, 3));
	move.movePairWise(atvRoute, atv, copter, mapp);
	//After MovePairWise vehicles must be on end position..
	if (atv.getPosition() == WayPoint(5, 3) && copter.getPosition() == WayPoint(5, 3)){
		std::cout << "Filled atv route in movePairWise, vehicles on end position SUCCES" << std::endl;
	}
	else{
		if (atv.getPosition() != WayPoint(5, 3)){
			error = true;
			std::cout << "Filled atv route in movePairWise, vehicles on end position *ATV* ERROR" << std::endl;
		}
		if (copter.getPosition() != WayPoint(5, 3)){
			error = true;
			std::cout << "Filled atv route in movePairWise, vehicles on end position *quadcopter* ERROR" << std::endl;
		}
	}


	//Non initialised or out of bounds PairWiseMove must return errors..
	if (move.nextATVWaypoint() == WayPoint(-2, -2) && move.nextQuadCopterWaypoint() == WayPoint(-2, -2)){
		move.initPairWiseMove(atvRoute, atv, copter, mapp);
		while (move.moveQuadCopterToNextWaypoint(copter));
		while (move.moveATVToNextWaypoint(atv));
		if (move.nextATVWaypoint() == WayPoint(-1, -1) && move.nextQuadCopterWaypoint() == WayPoint(-1, -1)){
			std::cout << "atv and quadcopter nextwaypoint must return right error values SUCCES" << std::endl;
		}
		else{
			error = true;
			std::cout << "atv and quadcopter nextwaypoint must return right error values *bounds* ERROR" << std::endl;
		}
	}
	else{
		error = true;
		std::cout << "atv and quadcopter nextwaypoint must return right error values *init* ERROR" << std::endl;
	}



	atv.goTo(1, 1);
	copter.goTo(1, 1);
	move.initPairWiseMove(atvRoute, atv, copter, mapp);
	while (move.moveQuadCopterToNextWaypoint(copter));
	while (move.moveATVToNextWaypoint(atv));
	//After moving vehicles with ToNextWaypoint() they must be on right position..
	if (atv.getPosition() == WayPoint(5, 3) && copter.getPosition() == WayPoint(5, 3)){
		std::cout << "atv and quadcopter moveToNextWayPoint goTo right waypoint SUCCES" << std::endl;
	}
	else{
		if (atv.getPosition() != WayPoint(5, 3)){
			error = true;
			std::cout << "atv and quadcopter moveToNextWayPoint goTo right waypoint *ATV* ERROR" << std::endl;
		}
		if (copter.getPosition() != WayPoint(5, 3)){
			error = true;
			std::cout << "atv and quadcopter moveToNextWayPoint goTo right waypoint *quadcopter* ERROR" << std::endl;
		}
	}



	atv.goTo(1, 1);
	copter.goTo(1, 1);
	move.initPairWiseMove(atvRoute, atv, copter, mapp);
	//InitPairWiseMovement must reset counters..
	if (move.nextATVWaypoint() == WayPoint(1, 2) && move.nextQuadCopterWaypoint() == WayPoint(1, 1)){
		std::cout << "InitPairWiseMovement must reset counters SUCCES" << std::endl;
	}
	else{
		if (move.nextATVWaypoint() != WayPoint(1, 2)){
			error = true;
			std::cout << "InitPairWiseMovement must reset counters *atvcount* ERROR" << std::endl;
		}
		else{
			error = true;
			std::cout << "InitPairWiseMovement must reset counters *coptercount* ERROR" << std::endl;
		}
	}

	if (!error){
		std::cout << "**!!ALL TESTS SUCCESSFUL!!**" << std::endl;
	}

    return error;
}
