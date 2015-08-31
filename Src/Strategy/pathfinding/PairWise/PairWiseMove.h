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
     * @fn	std::pair<Route*, Route*>* PairWiseMove::generatePairRoute(const Route& atvRoute,
						const VirtualATV& atv,
						const VirtualQuadCopter& copter,
						const Map& map);
     *
     * @brief	Creates two synchronised routes, one for the quadcopter and one ATV from 
     * 			an pre-calculated ATV route.
     * 			As long as the ATV is in sight of the quadCopter, the quadCopter does not move.
     * 			Else the quadCopter moves to next ATV position, following a route calculated by AStar.
     * 			The synchronisation lies in the fact that both routes have the same amount of waypoints.
     * 			
     * 			The first route in the pair is the quadcopter route, the second the ATV route.
     * 			
     * @param	const &atvRoute	an ATV route.
     * @param	const &atv		The ATV.
     * @param	const &copter  	The quadcopter.
     * @param	const &map		a map.
     *
     * @return	A std::pair<Route*, Route*>* with a Route for QuadCopter and a Route for ATV;
     */
	std::pair<Route*, Route*>* generatePairRoute(const Route& atvRoute,
						const VirtualATV& atv,
						const VirtualQuadCopter& copter,
						const Map& map);
	
	/**
	* @fn	 void PairWiseMove::movePairWise(const Route& atvRoute,
						VirtualATV& atv,
						VirtualQuadCopter& copter,
						const Map& map);
	*
	* @brief	Runs generatePairRoute, and moves ATV and quadcopter to end position.
	* 			Returns when both vehicles are finished.
	*
	* @param	const &atvRoute	an ATV route.
	* @param	&atv			The ATV.
	* @param	&copter  		The copter.
	* @param    const &map		a map
	* 
	*/
    void movePairWise(const Route& atvRoute,
						VirtualATV& atv,
						VirtualQuadCopter& copter,
						const Map& map);
	
	/**
	* @fn	void PairWiseMove::initPairWiseMove(const Route& atvRoute,
                          const VirtualATV& atv,
                          const VirtualQuadCopter& copter,
                          const Map& map);
	*
	* @brief	Sets local pairWiseRoute variable with route calculated by generatePairRoute.
	* 			Sets both local waypoint counters to 0.
	* 			This so you can use the functions that move the vehicles step by step.
	*
	* @param	const &atvRoute	an ATV route.
    * @param	const &atv		The ATV.
    * @param	const &copter  	The quadcopter.
    * @param	const &map		a map.
	*
	*/
    void initPairWiseMove(const Route& atvRoute,
                          const VirtualATV& atv,
                          const VirtualQuadCopter& copter,
                          const Map& map);
	
	/**
	* @fn	WayPoint& PairWiseMove::nextATVWaypoint();
	*
	* @brief	Returns the next waypoint for the ATV.
	* 			If next WayPoint is out of range, a WayPoint(-1, -1) is returned.
	* 			If PairWiseMove is not initialised, a WayPoint(-2, -2) is returned.
	* 			
	* @return	If available, next ATV WayPoint, else an error WayPoint.
	* 			
	*/
	WayPoint& nextATVWaypoint();
	
	/**
	* @fn	bool PairWiseMove::moveATVToNextWaypoint(VirtualATV& atv);
	*
	* @brief	Moves the ATV to the next waypoint.
	* 			
	* @param	&atv	The ATV.
	* 			
	* @return	True if move successful, false and std::cout message if not.
	*
	*/
    bool moveATVToNextWaypoint(VirtualATV& atv);
	
	/**
	* @fn	WayPoint& PairWiseMove::nextQuadCopterWaypoint();
	*
	* @brief	Returns the next waypoint for the quadcopter.
	* 			If next WayPoint is out of range, a WayPoint(-1, -1) is returned.
	* 			If PairWiseMove is not initialised, a WayPoint(-2, -2) is returned.
	* 			
	* @return	If available, next QuadCopter WayPoint, else an error WayPoint.
	*/
    WayPoint& nextQuadCopterWaypoint();
	
	/**
	* @fn	bool PairWiseMove::moveQuadCopterToNextWaypoint(VirtualQuadCopter& copter);
	*
	* @brief	Moves the quadcopter to the next waypoint.
	* 			
	* @param	&copter		The quadcopter.
	* 			
	* @return	True if move successful, false and std::cout message if not.
	*
	*/
    bool moveQuadCopterToNextWaypoint(VirtualQuadCopter& copter);


private:
	//Route for step by step moving
    std::pair<Route*, Route*>* pairWiseRoute = nullptr;

	//Counters to see what is the next waypoint. route[Number] == next waypoint.
    int quadCopterWaypointCounter = 0;
    int ATVWaypointCounter = 0;
};

#endif // PAIRWISEMOVE_H