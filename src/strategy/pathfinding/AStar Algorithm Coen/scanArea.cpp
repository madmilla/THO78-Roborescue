/**
 * @file scanArea.cpp
 * @author Coen Andriessen
 * @version 1.5
 */

#include "scanArea.h"


/**
 * Constructor of scanArea.
 *
 * @param map
 * @param rosbee
 */

scanArea::scanArea(Map *map, Rosbee *rosbee){
    // Constructor
    this->map = map;
    this->rosbee = rosbee;
}

/**
 * Destructor of scanArea.
 */

scanArea::~scanArea(){
    // Destructor
}


/**
 * Function to start the scanMidAlgorithm.
 */

void scanArea::run(){
    if(map->isLoaded()){
        scanMidAlgorithm(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY());
    }
}

/**
 * Function to scan the room.
 *
 * @param x
 * @param y
 * @return tileLocation
 * @return scanMidAlgorithm()
 */

int * scanArea::scanMidAlgorithm(int x, int y){
    // Temp to store location.
    int * tileLocation;
    // Get tile that is needed for the algorithm.
    tileLocation = map->getTileForMidAlgorithm(x, y);
    // Set rosbee location to the tile location what is stored in tileLocation.
    rosbee->setRosbeeLocationX(tileLocation[0]);
    rosbee->setRosbeeLocationY(tileLocation[1]);
    // Check if the rosbeelocation is changed.
    map->rosbeeLocationChanged();
    // Check if the map is full scanned. When this is true the algorithm can stop.
    // When it is false call the function with the new rosbee location.
    if(map->isMapFullScanned() == true){
        return tileLocation;
    }else{
        return scanMidAlgorithm(tileLocation[0], tileLocation[1]);
    }
}


