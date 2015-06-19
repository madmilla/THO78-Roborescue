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

scanArea::scanArea(map *Map, Rosbee *rosbee, MapSearchNode *mapSearchNode, Route *route, mapLogicVSLAM *MapLogicVSLAM){
    // Constructor
    this->Map = Map;
    this->rosbee = rosbee;
    this->mapSearchNode = mapSearchNode;
    this->route = route;
	this->MapLogicVSLAM = MapLogicVSLAM;
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
    //if(map->isLoaded()){
		//while(!map->isMapFullScanned()){
			int * newRosbeeLocation;
			int * tileLocation;
			if (!Container::route.getSize()){
				//map->tilesInRangeLidar();
				MapLogicVSLAM->setTilesInRangeLidar();
				Map->print();
				tileLocation = MapLogicVSLAM->getUnscannedTile();
				std::cout << tileLocation[0] << tileLocation[1] << std::endl;
				std::cout << rosbee->getRosbeeLocationX() << rosbee->getRosbeeLocationY() << std::endl;
				mapSearchNode->Search(rosbee->getRosbeeLocationX(), rosbee->getRosbeeLocationY(), int(tileLocation[0]), int(tileLocation[1]));
			}
			//while (Container::route.getSize()){
				//newRosbeeLocation = Container::route.getNewTile();
				//map->updateMap();
				//if (!map->tileIsAccessible(newRosbeeLocation[0], newRosbeeLocation[1])){
				//	std::cout << "niet accessible" << std::endl;
				//	Container::route.clearRoute();
				//}else{
				//	rosbee->moveTo((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()), (newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
				///	rosbee->setRosbeeLocationX((newRosbeeLocation[0] - rosbee->getRosbeeLocationX()));
				//	rosbee->setRosbeeLocationY((newRosbeeLocation[1] - rosbee->getRosbeeLocationY()));
				//	std::cout << "Rosbee Location : " << rosbee->getRosbeeLocationX() << "," << rosbee->getRosbeeLocationY() << std::endl;
					//map->tilesInRangeLidar();
				//}
			//}
		//}
		//map->printMap();
    //}
}

