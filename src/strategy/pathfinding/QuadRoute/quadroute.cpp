/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file quadroute.cpp
* @date Created: 4/7/2015
*
* @author Jasper Stas
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

#include "quadroute.h"
#include <iostream>

/**
 * Basic constructor.
 * */
Quadroute::Quadroute()
{

}

/**
 * Basic deconstructor.
 * */
Quadroute::~Quadroute()
{

}

/**
 * This method creates a route from the quad to the finish position on the map.
 * */
void Quadroute::createRoute(pointer_to_arrays objectMatrix, Map *map){
    int quadLocationX;
    int quadLocationY;
    int finishX;
    int finishY;

    for(int x = 0; x < MAP_WIDTH; x++){
        for (int y = 0; y < MAP_HEIGHT; y++){
            if(objectMatrix[x][y] == 2){
                quadLocationX = x;
                quadLocationY = y;
            }
            else if(objectMatrix[x][y] == 3){
                finishX = x;
                finishY = y;
            }
        }
    }

    int tempX;
    int tempY;
    int i = 0;
    int waypointsX[MAP_HEIGHT+MAP_WIDTH];
    waypointsX[i] = quadLocationX;
    int waypointsY[MAP_HEIGHT+MAP_WIDTH];
    waypointsY[i] = quadLocationY;
    int previousX = quadLocationX;
    int previousY = quadLocationY;
    bool locationEdited;

    std::cout << "start quad (" << quadLocationX << "," << quadLocationY << ")" << std::endl;

    while(quadLocationX != finishX || quadLocationY != finishY){
        tempX = quadLocationX - finishX;
        tempY = quadLocationY - finishY;
        locationEdited = false;
        std::cout << "(" << quadLocationX << "," << quadLocationY << ")" << std::endl;

        //ERROR HANDLING
        if(waypointsX[i] == waypointsX[i-1] &&
                waypointsY[i] == waypointsY[i-1]){
            i-=1;
        }
        //ERROR HANDLING

        if(i>0){
            previousX = waypointsX[i-1];
            previousY = waypointsY[i-1];
        }

        //als quad zich aan de bovenkant van de finish bevindt
        if(tempY>0 && !locationEdited){
            if((objectMatrix[quadLocationX][quadLocationY-1]==0 ||
                    objectMatrix[quadLocationX][quadLocationY-1]==3) &&
                    quadLocationY-1 != previousY){
                quadLocationY--;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
            if(!locationEdited){
                if(!locationEdited && (tempX<=0 || previousX==quadLocationX-1)){
                    if((objectMatrix[quadLocationX+1][quadLocationY]==0 ||
                            objectMatrix[quadLocationX+1][quadLocationY]==3) &&
                            quadLocationX+1 != previousX){
                        quadLocationX++;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
                if(!locationEdited && (tempX>=0 || previousX==quadLocationX+1)){
                    if((objectMatrix[quadLocationX-1][quadLocationY]==0 ||
                            objectMatrix[quadLocationX-1][quadLocationY]==3) &&
                            quadLocationX-1 != previousX){
                        quadLocationX--;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
            }
        }
        //als quad zich rechts van de finish bevindt
        if(tempX<0 && !locationEdited){
            if((objectMatrix[quadLocationX+1][quadLocationY]==0 ||
                    objectMatrix[quadLocationX+1][quadLocationY]==3) &&
                    quadLocationX+1 != previousX){
                quadLocationX++;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
            if(!locationEdited){
                if(!locationEdited && (tempY<=0 || previousY==quadLocationY-1)){
                    if((objectMatrix[quadLocationX][quadLocationY+1]==0 ||
                        objectMatrix[quadLocationX][quadLocationY+1]==3) &&
                            quadLocationY+1 != previousY){
                        quadLocationY++;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
                if(!locationEdited && (tempY>=0 || previousY==quadLocationY+1)){
                    if((objectMatrix[quadLocationX][quadLocationY-1]==0 ||
                        objectMatrix[quadLocationX][quadLocationY-1]==3) &&
                            quadLocationY-1 != previousY){
                        quadLocationY--;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
            }
        }
        //als quad zich links van de finish bevindt
        if(tempX>0 && !locationEdited){
            if((objectMatrix[quadLocationX-1][quadLocationY]==0 ||
                    objectMatrix[quadLocationX-1][quadLocationY]==3) &&
                    quadLocationX-1 != previousX){
                quadLocationX--;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
            if(!locationEdited){
                if(!locationEdited && (tempY<=0 || previousY==quadLocationY-1)){
                    if((objectMatrix[quadLocationX][quadLocationY+1]==0 ||
                            objectMatrix[quadLocationX][quadLocationY+1]==3) &&
                            quadLocationY+1 != previousY){
                        quadLocationY++;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
                if(!locationEdited && (tempY>=0 || previousY==quadLocationY+1)){
                    if((objectMatrix[quadLocationX][quadLocationY-1]==0 ||
                            objectMatrix[quadLocationX][quadLocationY-1]==3) &&
                            quadLocationY-1 != previousY){
                        quadLocationY--;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
            }
        }
        //als quad zich aan de onderkant van de finish bevindt
        if(tempY<0 && !locationEdited){
            if((objectMatrix[quadLocationX][quadLocationY+1]==0 ||
                    objectMatrix[quadLocationX][quadLocationY+1]==3) &&
                    quadLocationY+1 != previousY){
                quadLocationY++;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
            if(!locationEdited){
                if(!locationEdited && (tempX<=0 || previousX==quadLocationX-1)){
                    if((objectMatrix[quadLocationX+1][quadLocationY]==0 ||
                            objectMatrix[quadLocationX+1][quadLocationY]==3) &&
                            quadLocationX+1 != previousX){
                        quadLocationX++;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
                if(!locationEdited && (tempX>=0 || previousX==quadLocationX+1)){
                    if((objectMatrix[quadLocationX-1][quadLocationY]==0 ||
                            objectMatrix[quadLocationX-1][quadLocationY]==3) &&
                            quadLocationX-1 != previousX){
                        quadLocationX--;
                        locationEdited = true;
                    }
                    else{
                        locationEdited = false;
                    }
                }
            }
        }

        /*if(tempX<0 && !locationEdited){
            if((objectMatrix[quadLocationX+1][quadLocationY]==0 ||
                    objectMatrix[quadLocationX+1][quadLocationY]==3) &&
                    quadLocationX+1 != previousX){
                quadLocationX++;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
        }
        if(tempY<0 && !locationEdited){
            if((objectMatrix[quadLocationX][quadLocationY+1]==0 ||
                    objectMatrix[quadLocationX][quadLocationY+1]==3) &&
                    quadLocationY+1 != previousY){
                quadLocationY++;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
        }
        if(tempX>0 && !locationEdited){
            if((objectMatrix[quadLocationX-1][quadLocationY]==0 ||
                    objectMatrix[quadLocationX-1][quadLocationY]==3) &&
                    quadLocationX-1 != previousX){
                quadLocationX--;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
        }
        if(tempY>0 && !locationEdited){
            if((objectMatrix[quadLocationX][quadLocationY-1]==0 ||
                    objectMatrix[quadLocationX][quadLocationY-1]==3) &&
                    quadLocationY-1 != previousY){
                quadLocationY--;
                locationEdited = true;
            }
            else{
                locationEdited = false;
            }
        }
        if(!locationEdited){
            if(!locationEdited){
                if((objectMatrix[quadLocationX+1][quadLocationY]==0 ||
                        objectMatrix[quadLocationX+1][quadLocationY]==3) &&
                        quadLocationX+1 != previousX){
                    quadLocationX++;
                    locationEdited = true;
                }
                else{
                    locationEdited = false;
                }
            }
            if(!locationEdited){
                if((objectMatrix[quadLocationX][quadLocationY+1]==0 ||
                        objectMatrix[quadLocationX][quadLocationY+1]==3) &&
                        quadLocationY+1 != previousY){
                    quadLocationY++;
                    locationEdited = true;
                }
                else{
                    locationEdited = false;
                }
            }
            if(!locationEdited){
                if((objectMatrix[quadLocationX-1][quadLocationY]==0 ||
                        objectMatrix[quadLocationX-1][quadLocationY]==3) &&
                        quadLocationX-1 != previousX){
                    quadLocationX--;
                    locationEdited = true;
                }
                else{
                    locationEdited = false;
                }
            }
            if(!locationEdited){
                if((objectMatrix[quadLocationX][quadLocationY-1]==0 ||
                        objectMatrix[quadLocationX][quadLocationY-1]==3) &&
                        quadLocationY-1 != previousY){
                    quadLocationY--;
                    locationEdited = true;
                }
                else{
                    locationEdited = false;
                }
            }
        }
        */
        i++;
        waypointsX[i] = quadLocationX;
        waypointsY[i] = quadLocationY;
    }
    for(int j = 1; j<i; j++){
        std::cout << "j = " << j << ", waypoint (" << waypointsX[j] << "," << waypointsY[j] << ")" << std::endl;
        map->set(waypointsX[j], waypointsY[j], 4);
    }
    std::cout << "final quad (" << quadLocationX << "," << quadLocationY << ")" << std::endl;
    std::cout << "finish (" << finishX << "," << finishY << ")" << std::endl;

    //int waypoints[i][i];
    //for(int x = 0; x < i; x++){
    //    waypoints[x][0] = waypointsX[x];
    //    waypoints[x][1] = waypointsY[x];
    //}
    //map->setRoute(waypoints, i);
}
