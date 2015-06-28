/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file AreaCoverageAlgorithm.cpp
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

#include "areacoveringalgorithm.h"
#include "iostream"
#define left Dimension(-1, 0)
#define right Dimension(1, 0)
#define forward Dimension(0, -1)
#define down Dimension(0, 1)

 /** Basic constructor, This requiers a test copter and a Map to function
*/
AreaCoveringAlgorithm::AreaCoveringAlgorithm(VirtualQuadCopter *copter, Map* mapp) {
	mapp->setScale(5);
	globalMap = mapp;
	std::cout << "Start";
	followWall(copter, mapp, 1);
	std::cout << "followed wall";
	getchar();
	followCovered(copter, mapp, 1, 3);
	this->drawWayPoints(mapp);
}

/** This method gives the waypoints in the result section the value of 7 on the array Map
This is usefull for gui implementations */

void AreaCoveringAlgorithm::drawWayPoints(Map* map) {
	for (WayPoint *point : result.wayPoints) {
		map->setScaledLocationValue(point->x,point->y,7);
	}
}


 /** This function returns true if the function coveres the entire area  */
bool AreaCoveringAlgorithm::testCoverage(){
	if (globalMap->contains(0)) { //Als er nog tiles in zitten die 0 zijn dus onbekeken
		std::cout << "Not all areas covered, alg failed";
		return false;
	} 
	else {
		std::cout << "No Spaces left unchecked, Coverage Route Succes";
		return true;
	}
}

/** This function makes the area coverage algorithm follow the wall
*/

int AreaCoveringAlgorithm::followWall(VirtualQuadCopter *copter, Map *mapp,
                                      int wallnumber) {
	this->registerLocation(mapp, copter);
	Dimension direction(0, 0);
	direction.height = 1;
	int x = 0;
	while(true) {
		mapp->print();
		getchar();
		x++;
		this->registerLocation(mapp, copter);
		if (result.wayPoints.size() > 2 && *(result.wayPoints.at(
			result.wayPoints.size() - 1)) == *(result.wayPoints.at(0))) {
			return x;
		}
    if (pointOn(direction.width, direction.height, copter, mapp) == wallnumber){ // Als er iets in de wegstaat voor de copter
		std::cout << "Iets in de weg";
		if (direction == down){ // als hij op het scherm naar beneden gaat
			if (pointOn(-1, 0, copter, mapp) == wallnumber){ // En de copter kan niet naar rechts
				if (pointOn(1, 0, copter, mapp) == wallnumber) {
					direction = forward;
				}
				else {
					direction = right;
					moveingBack = false;
				}
			}
			else {
				direction = left;
				moveingBack = false;
			}
		} else if (direction == right){ // als hij op het scherm naar beneden gaat
        if (pointOn(0, 1, copter, mapp) == wallnumber){ // En de copter kan niet naar beneden
			if (pointOn(0, -1, copter, mapp) == wallnumber) {
				//  std::cout << "Ik zit vast";
				direction = left;
			} // en hij kan ook niet rechts
			else {
				direction = forward;
				moveingBack = false;
			}
        }
        else {
			direction = down;
			moveingBack = false;
        }
    } 
	else if (direction == left){ // als hij op het scherm naar beneden gaat
        if (pointOn(0, -1, copter, mapp) == wallnumber){ // En de copter kan niet omhoog
			if (pointOn(0, 1, copter, mapp) == wallnumber){
            direction = right;
			} // en hij kan ook niet rechts
			else {
				direction = down;
				moveingBack = false;
			}
		}
		else {
			direction = forward;
			moveingBack = false;
        }
    } else if (direction == forward){ // als hij op het scherm naar beneden gaat
        if (pointOn(1, 0, copter, mapp) == wallnumber){ // En de copter kan niet naar beneden
			if (pointOn(-1, 0, copter, mapp) == wallnumber){
				direction = down;
			} // en hij kan ook niet rechts
			else {
				direction = left;
				moveingBack = false;
			}
        }
        else {
			direction = right;
			moveingBack = false;
        }
    }
    } 
	else if (pointOn(0, 1, copter, mapp) != wallnumber &&
               pointOn(1, 0, copter, mapp) != wallnumber &&
               pointOn(-1, 0, copter, mapp) != wallnumber &&
               pointOn(0, -1, copter, mapp) != wallnumber) {
		if (direction == left) {
			direction = forward;
		} else if (direction == down) {
			direction = left;
		} else if (direction == forward) {
			direction = right;
		} else if (direction == right) {
			direction = down;
		}
    }
    copter->setX(copter->getX() + direction.width);
    copter->setY(copter->getY() + direction.height);
	}
  return 0;
}

 /** this function makes the area coverage function foollow his own covered
  * area effectifly covering all the area's of the Map.
  */
  
int AreaCoveringAlgorithm::followCovered(VirtualQuadCopter *copter, Map* mapp,
	                          int wallnumber, int coveredNumber) {
	bool boxed = false;
	int checker = 0;
	moveingBack=false;
	coveredNumber++;
	Dimension direction(0, 0);
	direction.height = 1;
	int sightxinitial = copter->getFov().width - 1;
	while (globalMap->contains(0)) {
		mapp->print();	
		getchar();
		checker++;
		this->drawWayPoints(mapp);
		std::cout << "Copter: " << copter->getX() << " " << copter->getY() << "\n";
		std::cout << this->isCoveredInDirection(down,copter);
		if (!boxed){ 
			this->registerLocation(mapp, copter);
		}
		if (isBoxedIn(copter, mapp)) {
			if(!boxed) astarfrom = point(copter->getX(), copter->getY());
		boxed = true;
		std::cout << "Boxed in";
		moveBackOnRoute(copter);
		std::cout << "Boxed in gone back";
		std::cout << "Copter: " << copter->getX() << " " << copter->getY() << "\n";
		continue;
    } else if (boxed) {
		std::cout << "Niet meer boxed in";
		astarto = point(copter->getX(), copter->getY());
		aStar findroute;
		Route shortest = findroute.getRoute(findroute.findPath(astarfrom.getX(), astarfrom.getY(), astarto.getX(), astarto.getY(),*globalMap));
		result.addRoutePart(shortest);
		moveingBack = false;
		boxed = false;
    }
    if (pointOn(direction.width, direction.height, copter, mapp) ==
            wallnumber ||
            isCoveredInDirection(direction,copter)||
        pointOn(direction.width * (sightxinitial),
                direction.height * (sightxinitial), copter, mapp) ==
            wallnumber){ // Als er iets in de wegstaat voor de copter
		std::cout << " covered";
		if (direction == down){ // als hij op het scherm  naar beneden gaat
			std::cout << " Down covered";
			if (pointOn(-1, 0, copter, mapp) == wallnumber ||
				isCoveredInDirection(left,copter) ||
				pointOn(-1 * (sightxinitial), 0, copter, mapp) ==
                wallnumber){ // En de copter kan niet naar links
				if (pointOn(1, 0, copter, mapp) == wallnumber ||
					isCoveredInDirection(right,copter)||
					pointOn(1 * (sightxinitial), 0, copter, mapp) == wallnumber) {
						std::cout << "Ik zit vast";
						moveBackOnRoute(copter);
				} // en hij kan ook niet rechts
				else {
					direction = right;
					moveingBack = false;
				} // ga naar links
			} else {
				direction = left;
				moveingBack = false;
			}
		} else if (direction == right){ // als hij op het scherm naar rechts gaat
			if (pointOn(0, 1, copter, mapp) == wallnumber ||
				isCoveredInDirection(down,copter)||
				pointOn(0, 1 * (sightxinitial), copter, mapp) ==
                wallnumber){ // En de copter kan niet naar beneden
				if (pointOn(0, -1, copter, mapp) == wallnumber ||
					isCoveredInDirection(forward,copter)||
					pointOn(0, (sightxinitial) * -1, copter, mapp) == wallnumber) {
						moveBackOnRoute(copter);
				} else {
					direction = forward;
					moveingBack = false;
				}
			}
			else {
				direction = down;
				moveingBack = false;
			}
		} else if (direction == left){ // als hij op het scherm naar beneden gaat
			if (pointOn(0, -1, copter, mapp) == wallnumber ||
				isCoveredInDirection(forward,copter)||
				pointOn(0, -1 * (sightxinitial), copter, mapp) ==
                wallnumber){ // En de copter kan niet omhoog
					if (pointOn(0, 1, copter, mapp) == wallnumber ||
						isCoveredInDirection(down,copter)||
						pointOn(0, 1 * (sightxinitial), copter, mapp) == wallnumber){
							moveBackOnRoute(copter);
					} else {
						direction = down;
						moveingBack = false;
					}
				}
				else {
					direction = forward;
					moveingBack = false;
				}
			} else if (direction == forward){ // als hij op het scherm naar vooruit gaat
				std::cout << "Forward covered";
				if (pointOn(1, 0, copter, mapp) == wallnumber ||
					isCoveredInDirection(right,copter)||
					pointOn(1 * (sightxinitial), 0, copter, mapp) ==
					wallnumber){ // En de copter kan niet naar links
						std::cout << "Forward right covered";
						if (pointOn(-1, 0, copter, mapp) == wallnumber ||
							isCoveredInDirection(left,copter)||
							pointOn(-1 * (sightxinitial), 0, copter, mapp) == wallnumber) {
								moveBackOnRoute(copter);
						} else {
							direction = left;
							moveingBack = false;
						}
					}
					else {
						direction = right;
						moveingBack = false;
					}
				}
			}
		if (!moveingBack) {
			copter->setX(copter->getX() + direction.width);
			copter->setY(copter->getY() + direction.height);
		};
	}
  return 0;
}

Route AreaCoveringAlgorithm::getRoute(){
	Route route(result);
	route.scale = globalMap->getScale();
	route.scaleWaypoints();
	return route;
}

 /** this function returns the value on the point of the given Map */
int AreaCoveringAlgorithm::pointOn(int x, int y, VirtualQuadCopter *copter,
                                   Map* map) {
	if (copter->getX() + x < int(map->getScaledWidth() )&& copter->getX() + x > -1) {
		if (copter->getY() + y > -1 && copter->getY() + y < int(map->getScaledHeight())) {
			return map->getScaledLocationValue(copter->getX() + x,copter->getY() + y);
		} else {
			return 1;
		}
	}
	else return 1;
}

 /** This method sets empty the area's around the test copter to covered.  */
void AreaCoveringAlgorithm::registerLocation(Map* map,
                                             VirtualQuadCopter *copter) {
  result.wayPoints.push_back(new WayPoint(copter->getX(), copter->getY()));
  int sightxinitial = copter->getFov().width - 1;
  sightxinitial = sightxinitial / 2;
  // werkt wel voor x en y omdat ie toch vierkant is, zo niet dan moet ik een
  // sight y initial maken
  for (int i = copter->getX() - sightxinitial; i <= copter->getX() + sightxinitial; i++) {

    for (int ii = copter->getY() - sightxinitial; ii <= copter->getY() + sightxinitial;
         ii++) {
      if (i < int(map->getScaledWidth()) && i > -1 && ii > -1 &&
		  ii < int(map->getScaledHeight())) {
        if (map->getScaledLocationValue(i,ii) == 0) {
          map->setScaledLocationValue(i,ii,3);
        }
      }
    }
  }
}
 /** this method checks if there are uncovered areas around the copter. if there are empty areas it will return false else true */
bool AreaCoveringAlgorithm::isBoxedIn(VirtualQuadCopter *copter, Map* map) {
    if (   !(isCoveredInDirection(forward,copter)|| pointOn(0,-1,copter,map)==1||pointOn(0,-2,copter,map)==1) ){return false;}
    if (   !(isCoveredInDirection(down,copter)|| pointOn(0,1,copter,map)==1||pointOn(0,2,copter,map)==1) ){return false;}
    if (   !(isCoveredInDirection(right,copter)|| pointOn(1,0,copter,map)==1|| pointOn(2,0,copter,map)==1) ){return false;}
    if (   !(isCoveredInDirection(left,copter)|| pointOn(-1,0,copter,map)==1|| pointOn(-2,0,copter,map)==1) ){return false;}
    return true;


}

AreaCoveringAlgorithm::~AreaCoveringAlgorithm(){
	// Destructor
}

void AreaCoveringAlgorithm::setCopterSquare(VirtualQuadCopter copt, Map* map) {
	map->setScaledLocationValue(copt.getX(), copt.getY(), 10);
}

 /** this function moves the VirtualQuadCopter back on the route and keeps track of howfar it went back */
void AreaCoveringAlgorithm::moveBackOnRoute(VirtualQuadCopter *copter) {
	if (moveingBack) {
		std::cout << "Route print\n";
		std::cout << result;
		std::cout << "Moves back:" <<movesBack;
		copter->setX(result.wayPoints.at(stuckWaypointIndex + movesBack)->x);
		copter->setY(result.wayPoints.at(stuckWaypointIndex + movesBack)->y);
		movesBack += -1;
	} else {
		std::cout << "Dit een keer hoop ik";
		moveingBack = true;
		stuckWaypointIndex = int(result.wayPoints.size() - 1);
		movesBack = 0;
	}
}
 /** This function checks if the VirtualQuadCopter is covered in the given direction it
  *not only checks directly in front of it but in front of the entire sight range of the copter */

bool AreaCoveringAlgorithm::isCoveredInDirection(Dimension d, VirtualQuadCopter *t ){
    int index;
    bool uncovered=true;
    int sightxinitial =2;
    if(d.height){
		for(int i=-1; i<= 1;i++){
			if(pointOn(i, d.height * (sightxinitial), t, globalMap) == 0){
				index = i;uncovered= false;
			}
			if(pointOn(i, d.height * (sightxinitial), t, globalMap) == 1){
				
			}
		}
	}
	else{
        for(int i=-1; i<= 1;i++){
			if(pointOn( d.width * (sightxinitial),i, t, globalMap) == 0){ 
				index = i;
				uncovered = false;
			}
		}
	}
    return uncovered;
}
