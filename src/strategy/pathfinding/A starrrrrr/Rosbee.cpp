/**
 * @file Rosbee.cpp
 * @author Coen Andriessen
 * @version 1.5
 */

#include "Rosbee.h"


/**
 * Constructor of Rosbee.
 */

Rosbee::Rosbee(){
    // Constructor
}

/**
 * Destructor of Map.
 */

Rosbee::~Rosbee(){
    // Destructor
}

/**
 * Function to check if the rosbee location is changed. When it is changed
 * the location will be stored in the old rosbee location.
 */

bool Rosbee::isLocationChanged(){
    if(rosbeeLocationX == oldRosbeeLocationX && rosbeeLocationY == oldRosbeeLocationY){
        return false;
    }else{
        oldRosbeeLocationX = rosbeeLocationX;
        oldRosbeeLocationY = rosbeeLocationY;
        return true;
    }
}

/**
 * Function to return the rosbee location x.
 * @return rosbeeLocationX
 */

int Rosbee::getRosbeeLocationX(){
    return rosbeeLocationX;
}

/**
 * Function to return the rosbee location y.
 * @return rosbeeLocationY
 */

int Rosbee::getRosbeeLocationY(){
    return rosbeeLocationY;
}

/**
 * Function to return the old rosbee location x.
 * @return oldRosbeeLocationx
 */

int Rosbee::getOldRosbeeLocationX(){
    return oldRosbeeLocationX;
}

/**
 * Function to return the old rosbee location y.
 * @return oldRosbeeLocationY
 */

int Rosbee::getOldRosbeeLocationY(){
    return oldRosbeeLocationY;
}

/**
 * Function to set the rosbee location x.
 *
 * @param x
 */

void Rosbee::setRosbeeLocationX(int x){
    rosbeeLocationX = x;
}

/**
 * Function to set the rosbee location y.
 *
 * @param y
 */

// Set value for rosbeeLocationY.
void Rosbee::setRosbeeLocationY(int y){
    rosbeeLocationY = y;
}




