#include "StrategyController.h"


StrategyController::StrategyController(Map *map, VirtualQuadCopter copter, virtualRosbee virtualrosbee, virtualLidar virtuallidar) :
copter{ copter },
virtualrosbee{ virtualrosbee },
map{ map },
virtuallidar{virtuallidar}

{
	Thread = new std::thread(&StrategyController::run, this);
	Thread->detach();
}


StrategyController::~StrategyController()
{
	
}

void StrategyController::scanArea(){
	Route * route = new Route();
	Map MapCopy = *map;
	VSLAM vslam(&MapCopy, &virtualrosbee,route, &virtuallidar);
	MapCopy.setScale(30);
	while (MapCopy.contains(0)){
	 vslam.run();
	std::cout << "get char" << std::endl;
	virtuallidar.start(virtualrosbee.getVirtualRosbeeLocationX(),virtualrosbee.getVirtualRosbeeLocationY(),virtualrosbee.getVirtualRosbeeFlank());
	getchar();
	std::cout << "got char" << std::endl;
	MapCopy.print();
	}
	MapCopy.print();
        std::cout << "ScanAreaDone";
	getchar();
}

void StrategyController::searchArea(){
	map->print();
        std::cout << "ScanAreaDone";
	getchar();
	AreaCoveringAlgorithm(&copter, map);
	map->print();
	getchar();
}
void StrategyController::movePairwise(){
	//AreaCoveringAlgorithm(&copter, map);
	map->print();
	getchar();
}
void StrategyController::run(){
	std::cout << "Strategy running" << std::endl;
	scanArea();
	searchArea();


}
