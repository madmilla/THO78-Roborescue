/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file AreaCoverageAlgorithm.h
* @date Created: 4/28/2015
* @version 1.0
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

#include "pairwisemove.h"


PairWiseMove::PairWiseMove(){}

void PairWiseMove::movePairWise(Route atvRoute,
                                  ATV atv,
                                  QuadCopter copter, map map){
    aStar routemaker;
	if (copter.getX() != atv.getX() || copter.getY() != atv.getY()){			//QuadCopter on ATV start position?
		auto route = routemaker.findPath(copter.getX(), copter.getY(), atv.getX(), atv.getY(), map);
       for(auto wayPoint : route){                      //If not -> QuadCopter move to ATV
           copter.goTo(wayPoint.first, wayPoint.second);
       }
    }
    for(int i = 0; i < atvRoute.getRouteSize(); i++){			//Loop trough ATV route
        WayPoint* atvPosition = atvRoute.getWaypoint(i);
        if(!copter.inView(atvPosition->x, atvPosition->y)){		//Check if ATV is in view
			auto route = routemaker.findPath(copter.getX(), copter.getY(), atv.getX(), atv.getY(), map);
            for(auto wayPoint : route){                         //If not -> QuadCopter move to ATV
                copter.goTo(wayPoint.first, wayPoint.second);
            }
        }
        atv.goTo(atvPosition->x, atvPosition->y);						//Move ATV
    }
}

std::pair<Route*, Route*>* PairWiseMove::QuadCopterPairRoute(Route atvRoute,
                                  ATV atv,
                                  QuadCopter copter, map map){
    aStar routemaker;
    Route* quadPairRoute = new Route;
    Route* atvPairRoute  = new Route;

	if (copter.getX() != atv.getX() || copter.getY() != atv.getY()){                             //QuadCopter on ATV start position?
        auto route = routemaker.findPath(copter.getX(), copter.getY(), atv.getX(), atv.getY(), map);
        for(auto wayPoint : route){                                         //If not -> QuadCopter move to ATV
            quadPairRoute->pushWayPoint(new WayPoint(wayPoint.first, wayPoint.second));
            atvPairRoute->pushWayPoint(new WayPoint(atv.getX(), atv.getY()));         //ATV stay on position!
        }

    }
    for(int i = 0; i < atvRoute.getRouteSize(); i++){                       //Loop trough ATV route
        WayPoint* atvNextPosition = atvRoute.getWaypoint(i);                //Get next ATV position

        if(!copter.inView(atvNextPosition->x, atvNextPosition->y)){                 //Check if ATV is in view
            auto route = routemaker.findPath(copter.getX(), copter.getY(), atvNextPosition->x, atvNextPosition->y, map);
            for(auto wayPoint : route){
                quadPairRoute->pushWayPoint(new WayPoint(wayPoint.first, wayPoint.second));//If not -> move to ATV
                atvPairRoute->pushWayPoint(new WayPoint(atvNextPosition->x, atvNextPosition->x));//Atv stay on place
            }
        }
        else{
            quadPairRoute->pushWayPoint(new WayPoint(copter.getX(), copter.getY()));//Quadcopter stay on place
            atvPairRoute->pushWayPoint(new WayPoint(atvNextPosition->x, atvNextPosition->y ));//atv move to next position
        }
    }
    return new std::pair<Route*, Route*>(quadPairRoute, atvPairRoute);
}

