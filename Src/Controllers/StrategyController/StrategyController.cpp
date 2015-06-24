#include "StrategyController.h"


StrategyController::StrategyController(Map map, VirtualQuadCopter copter, virtualRosbee virtualrosbee, virtualLidar virtuallidar) :
copter{ copter },
virtualrosbee{ virtualrosbee },
map{ map },
virtuallidar{virtuallidar}

{

}


StrategyController::~StrategyController()
{
}

void StrategyController::scanArea(){
	Route * route = new Route();
	Map MapCopy = map;
	VSLAM vslam(&MapCopy, &virtualrosbee, route, &virtuallidar);
	MapCopy.setScale(5);
	MapCopy.setScaledLocationValue(5, 1, 1);
	MapCopy.setScaledLocationValue(5, 2, 1);
	MapCopy.setScaledLocationValue(5, 3, 1);
	MapCopy.setScaledLocationValue(5, 4, 1);
	MapCopy.setScaledLocationValue(5, 5, 1);
	MapCopy.setScaledLocationValue(4, 5, 1);
	MapCopy.setScaledLocationValue(3, 5, 1);
	MapCopy.setScaledLocationValue(2, 5, 1);
	MapCopy.setScaledLocationValue(1, 5, 1);
	while (!vslam.bool_isVSLAMDone && MapCopy.contains(0)){ vslam.run();
	getchar();
	MapCopy.print();
	}
	MapCopy.print();
	getchar();
}

void StrategyController::searchArea(){
	AreaCoveringAlgorithm(&copter, &map);
	map.print();
	getchar();
}
