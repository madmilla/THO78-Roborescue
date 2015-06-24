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

scanArea::scanArea(map *Map, virtualRosbee *rosbee, MapSearchNode *mapSearchNode, Route *route, mapLogicVSLAM *MapLogicVSLAM, virtualLidar *virtuallidar){
    // Constructor
    this->Map = Map;
    this->rosbee = rosbee;
    this->mapSearchNode = mapSearchNode;
    this->route = route;
	this->MapLogicVSLAM = MapLogicVSLAM;
	this->virtuallidar = virtuallidar;
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
	if (!MapLogicVSLAM->isMapFullyScanned()){
		MapLogicVSLAM->setTilesInRangevirtuallidar();
		if (!Container::route.getSize()){
			tileLocation = MapLogicVSLAM->getUnscannedTile();
			std::cout << tileLocation[0] << tileLocation[1] << std::endl;
			std::cout << rosbee->getRosbeeLocationX() << rosbee->getRosbeeLocationY() << std::endl;
			if (!MapLogicVSLAM->isMapFullyScanned()){
				mapSearchNode->Search(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY(), int(tileLocation[0]), int(tileLocation[1]));
			}
		}
		if (Container::route.getSize() >= 1){
			newRosbeeLocation = Container::route.getNewTile();
			if (Map->getScaledHeuristicLocationValue(newRosbeeLocation[0], newRosbeeLocation[1]) == 9 || 
				Map->getScaledLocationValue((newRosbeeLocation[0]), (newRosbeeLocation[1] + virtuallidar->getRange())) == 9 ||
				Map->getScaledLocationValue((newRosbeeLocation[0] + virtuallidar->getRange()), (newRosbeeLocation[1])) == 9){
				Container::route.clearRoute();
			}
			else{
				rosbee->moveTo((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()), (newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
				rosbee->setRosbeeLocationX((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()));
				rosbee->setRosbeeLocationY((newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
				std::cout << "Rosbee Location: " << rosbee->getRosbeeLocationX() << " , " << rosbee->getRosbeeLocationY() << std::endl;
				Map->setScaledLocationValue(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY(), 3);
			}
		}
	}
}

