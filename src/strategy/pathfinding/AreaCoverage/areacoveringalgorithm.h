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
*
* @author Mathijs Arends
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
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
#ifndef AREACOVERINGALGORITHM_H
#define AREACOVERINGALGORITHM_H
#include <waypoint.h>
#include <point.hpp>
#include <map.hpp>
#include <quadCopter.h>
#include <vector>
#include <route.h>
#include <aStar.h>
class AreaCoveringAlgorithm
{
public:
	point astarfrom=point(0,0);
	point astarto=point(0,0);
    void setCopterSquare(TestCopter copt, map* map);
    int followCovered(TestCopter *copter, map* mapp, int wallnumber, int coveredNumber);
    void registerLocation(map*,TestCopter*);
    AreaCoveringAlgorithm(TestCopter copter, map *mapp);
    ~AreaCoveringAlgorithm();
    int followWall(TestCopter *copter, map* mapp, int wallnumber);
    Route result;
    void drawWayPoints(map*);
    bool testCoverage();
	Route getRoute();
private:
	// isCoveredInDirecten true or fales TI rules
    bool isCoveredInDirection(Dimension d, TestCopter* t );
    bool isBoxedIn(TestCopter*, map *map);
    void moveBackOnRoute(TestCopter* copter);
    map* globalmap;
    void goForward();
    bool moveingBack;
    int movesBack=0;
    int stuckWaypointIndex;
    int pointOn(int x, int y, TestCopter *copter, map* map);
};

#endif // AREACOVERINGALGORITHM_H
