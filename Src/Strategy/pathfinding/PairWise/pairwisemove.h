/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file PairWiseMove.h
* @date Created: 4/28/2015
* @version 1.5
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

#ifndef PAIRWISEMOVE_H
#define PAIRWISEMOVE_H

#include "WayPoint.h"
#include "VirtualQuadCopter.h"
#include "VirtualATV.h"
#include "Route.h"
#include "Map.hpp"
#include "aStar.h"
#include <vector>


class PairWiseMove{
public:

    /**
     * @fn	PairWiseMove::PairWiseMove();
     *
     * @brief	Default constructor, does nothing.
     *
     */

    PairWiseMove();

    /**
     * @fn	std::vector<WayPoint> PairWiseMove::QuadCopterPairRoute(std::vector<WayPoint> atvRoute,
     * 		ATV atv, QuadCopter copter);
     *
     * @brief	Creates a QuadCopter route from an ATV route.
     * 			As long as the ATV is in sight of QuadCopter, QuadCopter does not move.
     * 			Else the QuadCopter moves to next ATV position, with the route calculated by AStar.
     *
     * @param	atvRoute	an ATV route.
     * @param	atv			The ATV.
     * @param	copter  	The quadcopter.
     * @param	map			a map.
     *
     * @return	A std::vector with WayPoints for QuadCopter;
     */

    std::pair<Route*, Route*>* generatePairRoute(Route atvRoute,
                                                    VirtualATV atv,
                                                    VirtualQuadCopter copter,
                                                    Map map);
	/**
	* @fn	 void PairWiseMove::movePairWise(Route atvRoute, VirtualATV atv, VirtualQuadCopter copter, 
	* 		 Map map);
	*
	* @brief	Runs generatePairRoute, and moves atv and quadcopter to end position.
	* 			Returns when both vehicles are finished.
	*
	* @param	atvRoute	an atv route.
	* @param	atv			The atv.
	* @param	copter  	The copter.
	* @param    map			a map
	* 
	*/
    void movePairWise(Route atvRoute,
                      VirtualATV atv,
                      VirtualQuadCopter copter,
                      Map map);
	/**
	* @fn	void PairWiseMove::initPairWiseMove(Route atvRoute, VirtualATV atv, VirtualQuadCopter copter,
            Map map);
	*
	* @brief	Sets local variable pairWiseRoute with route calculated by generatePairRoute.
	* 			Sets both counters to 0.
	* 			This so you can use the functions to move vehicles step by step.
	*
	* @param	atvRoute	an atv route.
	* @param	atv			The atv.
	* @param	copter  	The copter.
	* @param    map			a map
	*
	*/
    void initPairWiseMove(Route atvRoute,
                          VirtualATV atv,
                          VirtualQuadCopter copter,
                          Map map);
	/**
	* @fn	WayPoint* PairWiseMove::nextATVWaypoint();
	*
	* @brief	Returns the next waypoint for the ATV.
	* 			
	*/
	WayPoint* nextATVWaypoint();
	/**
	* @fn	void PairWiseMove::nextATVWaypoint();
	*
	* @brief	Moves the ATV to the next waypoint.
	*
	*/
    void moveATVToNextWaypoint(VirtualATV atv);
	/**
	* @fn	WayPoint* PairWiseMove::nextQuadCopterWaypoint();
	*
	* @brief	Returns the next waypoint for the quadcopter.
	*
	*/
    WayPoint* nextQuadCopterWaypoint();
	/**
	* @fn	void PairWiseMove::nextATVWaypoint();
	*
	* @brief	Moves the quadcopter to the next waypoint.
	*
	*/
    void moveQuadCopterToNextWaypoint(VirtualQuadCopter copter);


private:
    std::pair<Route*, Route*>* pairWiseRoute = nullptr;
    int quadCopterWaypointCounter = 0;
    int ATVWaypointCounter = 0;
};

#endif // PAIRWISEMOVE_H
