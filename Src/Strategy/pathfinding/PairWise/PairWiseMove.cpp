/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file PairWiseMove.cpp
* @date Created: 4/28/2015
* @version 1.7
*
* @author Jacob Visser
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#include "PairWiseMove.h"


PairWiseMove::PairWiseMove(){}

std::pair<Route*, Route*>* PairWiseMove::generatePairRoute(const Route& atvRoute,
                                                           const VirtualATV& atv,
                                                           const VirtualQuadCopter& copter,
                                                           const Map& map){
    aStar routemaker;
    Route* quadPairRoute = new Route;
    Route* atvPairRoute  = new Route;

	if (!copter.inView(atv.getX(), atv.getY())){						//QuadCopter on ATV start position?
        auto route = routemaker.findPath(copter.getX(), copter.getY(), atv.getX(), atv.getY(), map);
        for(auto wayPoint : route){                                     //If not -> QuadCopter move to ATV
			quadPairRoute->pushWayPoint(WayPoint(wayPoint.first, wayPoint.second));
																		//ATV stay on position!
            atvPairRoute->pushWayPoint(WayPoint(atv.getX(), atv.getY()));
        }
    }
    for(int i = 0; i < atvRoute.getSize(); ++i){						//Loop trough ATV route
        WayPoint& atvNextPosition = atvRoute.getWaypoint(i);			//Get next ATV position
        if(!copter.inView(atvNextPosition.x, atvNextPosition.y)){     //Check if ATV is in view
            auto route = routemaker.findPath(copter.getX(), copter.getY(), atvNextPosition.x, atvNextPosition.y, map);
            for(auto &wayPoint : route){									//If not -> move to ATV
                quadPairRoute->pushWayPoint(WayPoint(wayPoint.first, wayPoint.second));
																		//Atv stay on place
                atvPairRoute->pushWayPoint(WayPoint(atvNextPosition.x, atvNextPosition.y));
            }
        }
        else{															//Quadcopter stay on place
            quadPairRoute->pushWayPoint(WayPoint(copter.getX(), copter.getY()));
																		//atv move to next position
            atvPairRoute->pushWayPoint(WayPoint(atvNextPosition.x, atvNextPosition.y ));
        }
    }
    return new std::pair<Route*, Route*>(quadPairRoute, atvPairRoute);
}

void PairWiseMove::movePairWise(const Route& atvRoute,
									VirtualATV& atv,
									VirtualQuadCopter& copter, 
									const Map& map){

	std::pair<Route*, Route*>* routePair = this->generatePairRoute(atvRoute,
																	atv, copter, map);

	Route* pairQuadRoute = routePair->first;
	Route* pairATVRoute = routePair->second;

	for (int i = 0; i < pairQuadRoute->getSize(); ++i){		//Routes have the same size, so pick one
		copter.goTo(pairQuadRoute->getWaypoint(i));			//-> maybe return something when done?
		atv.goTo(pairATVRoute->getWaypoint(i));				//-> maybe return something when done?
		//Sleep?
	}
}

void PairWiseMove::initPairWiseMove(const Route& atvRoute,
										const VirtualATV& atv,
										const VirtualQuadCopter& copter, const Map& map){

    pairWiseRoute = generatePairRoute(atvRoute, atv, copter, map);		//Generate route
    quadCopterWaypointCounter = 0;										//Reset counters
    ATVWaypointCounter = 0;

}

WayPoint& PairWiseMove::nextATVWaypoint(){								//If next waypoint available
    if(pairWiseRoute != nullptr && ATVWaypointCounter < pairWiseRoute->second->getSize()){ 
		WayPoint& tmp = pairWiseRoute->second->getWaypoint(ATVWaypointCounter);
        ATVWaypointCounter++;
        return tmp;
    }
	else if (pairWiseRoute == nullptr){									//If next not available due empty route
		return *(new WayPoint(-2, -2));									//Return error value
	}																	//When detected please delete waypoint
	else{																//If next not available due out of range
		return *(new WayPoint(-1, -1));									//Return error value waypoint
	}																	//When detected please delete waypoint
}

bool PairWiseMove::moveATVToNextWaypoint(VirtualATV& atv){
	WayPoint& tmp = nextATVWaypoint();
	if (tmp != WayPoint(-1, -1)){
		if (tmp != WayPoint(-2, -2)){
			atv.goTo(tmp);
			return true;
		}
		else{
			std::cout << "moveATVToNextWaypoint: PairWiseMove not initialised";
		}
	}
	return false;
}

WayPoint& PairWiseMove::nextQuadCopterWaypoint(){						//If next waypoint available
    if(pairWiseRoute != nullptr && quadCopterWaypointCounter < pairWiseRoute->first->getSize()){	
		WayPoint& tmp = pairWiseRoute->first->getWaypoint(quadCopterWaypointCounter);
        quadCopterWaypointCounter++;
        return tmp;
    }																	
	else if (pairWiseRoute == nullptr){									//If next not available due empty route
		return *(new WayPoint(-2, -2));									//Return error value
																		//When detected please delete waypoint
	}
	else{																//If next not available due out of range
		return *(new WayPoint(-1, -1));									//Return error value waypoint
	}																	//When detected please delete waypoint
}

bool PairWiseMove::moveQuadCopterToNextWaypoint(VirtualQuadCopter& copter){
	WayPoint& tmp = nextQuadCopterWaypoint();
	if (tmp != WayPoint(-1, -1)){
		if (tmp != WayPoint(-2, -2)){
			copter.goTo(tmp);
			return true;
		}
		else{
			std::cout << "moveQuadCopterToNextWaypoint: PairWiseMove not initialised";
		}
	}
	return false;
}

