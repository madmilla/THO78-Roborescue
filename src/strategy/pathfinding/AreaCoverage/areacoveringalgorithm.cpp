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
#include <chrono>
#include <thread>
#include "iostream"
#define left Dimension(-1, 0)
#define right Dimension(1, 0)
#define forward Dimension(0, -1)
#define down Dimension(0, 1)
 /** Basic constructor, This requiers a test copter and a map to function
*/
AreaCoveringAlgorithm::AreaCoveringAlgorithm(TestCopter copter,
                                             ArrayMap *mapp) {
  globalmap = mapp;
  followWall(&copter, mapp, 1);
  followCovered(&copter, mapp, 1, 3);
  this->drawWayPoints(mapp);
}
 /** This method gives the waypoints in the result section the value of 15 on the array map
This is usefull for gui implementations */
void AreaCoveringAlgorithm::drawWayPoints(ArrayMap *map) {

  for (WayPoint point : result) {
    map->data.at(point.x)->at(point.y) = 15;
  }
}


 /** This function returns true if the function coveres the entire area  */
bool AreaCoveringAlgorithm::testCoverage() {
  if (globalmap->contains(0)) {
    std::cout << "Not all areas covered, alg failed";
    return false;
  } else {
    std::cout << "No Spaces left unchecked, Coverage Route Succes";
    return true;
  }
}


/** This function makes the area coverage algorithm follow the wall
*/

int AreaCoveringAlgorithm::followWall(TestCopter *copter, ArrayMap *mapp,
                                      int wallnumber) {
  this->registerLocation(mapp, copter);

  Dimension direction(0, 0);
  direction.height = 1;  for (int x = 0; x < 250; x++) {

    this->registerLocation(mapp, copter);
    if (result.size() > 2 && result.at(result.size() - 1) == result.at(0)) {
     // std::cout << "Follow wall goed einde " <<copter->x << "  "<<copter->y ;
      return x;
    }
    if (pointOn(direction.width, direction.height, copter, mapp) ==
        wallnumber) // Als er iets in de wegstaat voor de copter
    {
      if (direction == down) // als hij op het scherm naar beneden gaat
      {

        if (pointOn(-1, 0, copter, mapp) ==
            wallnumber) // En de copter kan niet naar rechts
        {
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
      } else if (direction == right) // als hij op het scherm naar beneden gaat
      {

        if (pointOn(0, 1, copter, mapp) ==
            wallnumber) // En de copter kan niet naar beneden
        {
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
      } else if (direction == left) // als hij op het scherm naar beneden gaat
      {

        if (pointOn(0, -1, copter, mapp) ==
            wallnumber) // En de copter kan niet omhoog
        {
          if (pointOn(0, 1, copter, mapp) == wallnumber) {
       //     std::cout << "Ik zit vast";
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
      } else if (direction ==
                 forward) // als hij op het scherm naar beneden gaat
      {
        if (pointOn(1, 0, copter, mapp) ==
            wallnumber) // En de copter kan niet naar beneden
        {
          if (pointOn(-1, 0, copter, mapp) == wallnumber) {
         //   std::cout << "Ik zit vast";
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

      // direction= Dimension(1,0);
    } else if (pointOn(0, 1, copter, mapp) != wallnumber &&
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

      //std::cout << "wall lost";
    }
    copter->x = copter->x + direction.width;
    copter->y = copter->y + direction.height;
  }
  return 0;
}
 /** this function makes the area coverage function foollow his own covered area effectifly covering all the area's of the map.
  */
int AreaCoveringAlgorithm::followCovered(TestCopter *copter, ArrayMap *mapp,
                                         int wallnumber, int coveredNumber) {
  bool boxed = false;
  moveingBack=false;
  coveredNumber++;

  Dimension direction(0, 0);
  direction.height = 1;
  int sightxinitial = copter->copterSight.width - 1;
  //for(int i=0; i<300;i++){
    while (globalmap->contains(0)) {
    this->registerLocation(mapp, copter);

    if (checkIfBoxedIn(copter, mapp)) {
      boxed = true;
      moveBackOnRoute(copter);
      //std::cout << "boxed in";

      continue;
    } else if (boxed) {
      moveingBack = false;
      boxed = false;
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));

    // if(pointOn(direction.width*sightxinitial,direction.height*sightxinitial,copter,mapp)==
    // 3){QTextStream(stdout) <<"return";return x;}
    if (pointOn(direction.width, direction.height, copter, mapp) ==
            wallnumber ||
            checkIfCoveredInDirection(direction,copter)||
   //     pointOn(direction.width * (sightxinitial),
   //             direction.height * (sightxinitial), copter,
   //             mapp) == coveredNumber ||
        pointOn(direction.width * (sightxinitial),
                direction.height * (sightxinitial), copter, mapp) ==
            wallnumber) // Als er iets in de wegstaat voor de copter
    {
      if (direction == down) // als hij op het scherm  naar beneden gaat
      {
        //std::cout << " going down";

        if (pointOn(-1, 0, copter, mapp) == wallnumber ||
            checkIfCoveredInDirection(left,copter) ||
            pointOn(-1 * (sightxinitial), 0, copter, mapp) ==
                wallnumber) // En de copter kan niet naar links
        {
          if (pointOn(1, 0, copter, mapp) == wallnumber ||
             checkIfCoveredInDirection(right,copter)||
              pointOn(1 * (sightxinitial), 0, copter, mapp) == wallnumber) {
          //  std::cout << "Ik zit vast";
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

      } else if (direction == right) // als hij op het scherm naar rechts gaat
      {

        if (pointOn(0, 1, copter, mapp) == wallnumber ||
            checkIfCoveredInDirection(down,copter)||
            pointOn(0, 1 * (sightxinitial), copter, mapp) ==
                wallnumber) // En de copter kan niet naar beneden
        {
          if (pointOn(0, -1, copter, mapp) == wallnumber ||
             checkIfCoveredInDirection(forward,copter)||
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
      } else if (direction == left) // als hij op het scherm naar beneden gaat
      {

        if (pointOn(0, -1, copter, mapp) == wallnumber ||
            checkIfCoveredInDirection(forward,copter)||
            pointOn(0, -1 * (sightxinitial), copter, mapp) ==
                wallnumber) // En de copter kan niet omhoog
        {
          if (pointOn(0, 1, copter, mapp) == wallnumber ||
              checkIfCoveredInDirection(down,copter)||
              pointOn(0, 1 * (sightxinitial), copter, mapp) == wallnumber) {

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
      } else if (direction == forward) // als hij op het scherm naar vooruit gaat
      {

        if (pointOn(1, 0, copter, mapp) == wallnumber ||
           checkIfCoveredInDirection(right,copter)||
            pointOn(1 * (sightxinitial), 0, copter, mapp) ==
                wallnumber) // En de copter kan niet naar links
        {
          if (pointOn(-1, 0, copter, mapp) == wallnumber ||
             checkIfCoveredInDirection(left,copter)||
              pointOn(-1 * (sightxinitial), 0, copter, mapp) == wallnumber) {

            moveBackOnRoute(copter);
          } else {
            direction = left;
            moveingBack = false;
          }
        }

        else {
          direction = forward;
          moveingBack = false;
        }
      }

      // direction= Dimension(1,0);
    }

    if (!moveingBack) {
      copter->x = copter->x + direction.width;
      copter->y = copter->y + direction.height;
    };
  }
  return 0;
}
 /** this function returns the value on the point of the given map */
int AreaCoveringAlgorithm::pointOn(int x, int y, TestCopter *copter,
                                   ArrayMap *map) {
  if (copter->x + x < int(map->data.size() )&& copter->x + x > -1) {

    if (copter->y + y > -1 && copter->y + y < int(map->data.at(copter->x)->size())) {
      return map->data.at(copter->x + x)->at(copter->y + y);
    } else {
      return 1;
    }
  }
  else return 1;
}
 /** This method sets empty the area's around the test copter to covered.  */
void AreaCoveringAlgorithm::registerLocation(ArrayMap *map,
                                             TestCopter *copter) {
  result.push_back(WayPoint(copter->x, copter->y));
  int sightxinitial = copter->copterSight.width - 1;
  sightxinitial = sightxinitial / 2;
  // werkt wel voor x en y omdat ie toch vierkant is, zo niet dan moet ik een
  // sight y initial maken
  for (int i = copter->x - sightxinitial; i <= copter->x + sightxinitial; i++) {

    for (int ii = copter->y - sightxinitial; ii <= copter->y + sightxinitial;
         ii++) {
      if (i < int(map->data.size()) && i > -1 && ii > -1 &&
          ii < int(map->data.at(i)->size())) {
        if (map->data.at(i)->at(ii) == 0) {
          map->data.at(i)->at(ii) = 3;
        }
      }
    }
  }
}
 /** this method checks if there are uncovered areas around the copter. if there are empty areas it will return false else true */
bool AreaCoveringAlgorithm::checkIfBoxedIn(TestCopter *copter, ArrayMap *map) {
  //int coveredNumber = 0;
  //int sightxinitial = copter->copterSight.width - 1;
  //if (pointOn(-1 * (sightxinitial), 0, copter, map) != coveredNumber &&
      //pointOn(1 * (sightxinitial), 0, copter, map) != coveredNumber &&
      //pointOn(0, (sightxinitial)*1, copter, map) != coveredNumber &&
     // pointOn(0, (sightxinitial) * -1, copter, map) != coveredNumber) {
    //return true;
  //} else {
    //return false;
  //}
    if (   !(checkIfCoveredInDirection(forward,copter)|| pointOn(0,-1,copter,map)==1||pointOn(0,-2,copter,map)==1) ){return false;}
    if (   !(checkIfCoveredInDirection(down,copter)|| pointOn(0,1,copter,map)==1||pointOn(0,2,copter,map)==1) ){return false;}
    if (   !(checkIfCoveredInDirection(right,copter)|| pointOn(1,0,copter,map)==1|| pointOn(2,0,copter,map)==1) ){return false;}
    if (   !(checkIfCoveredInDirection(left,copter)|| pointOn(-1,0,copter,map)==1|| pointOn(-2,0,copter,map)==1) ){return false;}
    //pointOn(1 * (sightxinitial), 0, copter, map) != coveredNumber
    return true;


}
/*void AreaCoveringAlgorithm::getCells(Map map){
    bool lastwasnull=false;
//    map.print();
    int x=0;
    int y=0;
    while(true){
        Tile* t =map.getTileAt(x,y);
       if(t!=nullptr&&t->type=='0'&& !isInCell(t)){
       QTextStream(stdout) << t->x << "  "<< t->y << "\n";
       getCellFrom(map,t);
    }


    x++;
    if(t==nullptr){x=0;y++;
        if(lastwasnull==true){break;}

        lastwasnull=true;}

    else{lastwasnull=false;}


}


}*/
AreaCoveringAlgorithm::~AreaCoveringAlgorithm() {}

/*void AreaCoveringAlgorithm::getCellFrom(Map map, Tile* source){
    Tile* xMax;
    bool firstJump=true;
    bool lastnull=false;
    Cell product;
    int x=source->x;
    int y=source->y;
     QTextStream(stdout) << x << " " <<y << "geting cell from \n";
    while(true){

    Tile* checking = map.getTileAt(x,y);
    if (checking!=nullptr &&checking->type=='0'&& !isInCell(checking))
    {
        if(lastnull&&checking->x!=source->x){break;}
        QTextStream(stdout) << checking->x << "  "<< checking->y << " geting
cell \n";

        product.tiles.push_back(checking);
        x++;
        lastnull=false;
        if(firstJump){xMax =checking;}
    }

    else{y++;x=source->x;if(lastnull==true){break;}lastnull=true;firstJump=false;}
    if(firstJump!=true&&checking->x==xMax->x){y++;x=source->x;if(lastnull==true){break;}lastnull=true;firstJump=false;}


    }
    cells.push_back(product);

}*/
/*bool AreaCoveringAlgorithm::isInCell(Tile *t){
    for(Cell cell: cells){
        if(cell.contains(t)){return true;}



    }
    return false;





}*/
/*void AreaCoveringAlgorithm::generateCellPath(Cell c){



}*/
void AreaCoveringAlgorithm::setCopterSquare(TestCopter copt, ArrayMap *map) {
  map->data.at(copt.x)->at(copt.y) = 10;
}
 /** this function moves the testcopter back on the route and keeps track of howfar it went back */
void AreaCoveringAlgorithm::moveBackOnRoute(TestCopter *copter) {
  if (moveingBack) {

    copter->x = result.at(stuckWaypointIndex + movesBack).x;
    copter->y = result.at(stuckWaypointIndex + movesBack).y;
    movesBack = movesBack--;
  } else {
    moveingBack = true;
    stuckWaypointIndex = int(result.size() - 1);
    movesBack = 0;
  }
}
 /** This function checks if the testcopter is covered in the given direction it not only checks directly in front of it but in front of the entire sight range of the copter */


bool AreaCoveringAlgorithm::checkIfCoveredInDirection(Dimension d, TestCopter *t ){
   // std::cout << t->x << " " << t->y;
    bool uncovered=true;
    //std::cout << "DEBIGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
    int sightxinitial =2;
    //std::cout << sightxinitial;
    if(d.height){
    for(int i=-1; i<= 1;i++){
    if(pointOn(i, d.height * (sightxinitial), t, globalmap) == 0){index = i;uncovered= false;}
    if(pointOn(i, d.height * (sightxinitial), t, globalmap) == 1){}


    }}
   else{
        for(int i=-1; i<= 1;i++){
        if(pointOn( d.width * (sightxinitial),i, t, globalmap) == 0){ index = i;uncovered=false;}



    }}
    return uncovered;



}
