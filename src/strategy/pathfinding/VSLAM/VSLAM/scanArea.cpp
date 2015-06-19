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

scanArea::scanArea(Map *map, Rosbee *rosbee, MapSearchNode *mapSearchNode, Route *route){
    // Constructor
    this->map = map;
    this->rosbee = rosbee;
    this->mapSearchNode = mapSearchNode;
    this->route = route;
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
		while(!map->isMapFullScanned()){
			int * newRosbeeLocation;
			int * tileLocation;
			if (!Container::route.getSize()){
				map->tilesInRangeLidar();
				tileLocation = map->getUnscannedTile();
				mapSearchNode->Search(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY(), int(tileLocation[0]), int(tileLocation[1]));
			}
			while (Container::route.getSize()){
				newRosbeeLocation = Container::route.getNewTile();
				map->updateMap();
				if (!map->tileIsAccessible(newRosbeeLocation[0], newRosbeeLocation[1])){
					std::cout << "niet accessible" << std::endl;
					Container::route.clearRoute();
				}else{
					rosbee->moveTo((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()), (newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
					rosbee->setRosbeeLocationX((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()));
					rosbee->setRosbeeLocationY((newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
					std::cout << "Rosbee Location : " << rosbee->getRosbeeLocationX() << "," << rosbee->getRosbeeLocationY() << std::endl;
					map->tilesInRangeLidar();
				}
			}
		}
		map->printMap();
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