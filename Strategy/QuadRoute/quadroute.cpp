#include "quadroute.h"
#include <iostream>

Quadroute::Quadroute()
{

}

Quadroute::~Quadroute()
{

}

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
