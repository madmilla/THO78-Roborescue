#include "StrategyController.h"


StrategyController::StrategyController(map Map, QuadCopter copter, virtualRosbee virtualrosbee, virtualLidar virtuallidar) :
copter{ copter },
virtualrosbee{ virtualrosbee },
Map{ Map },
virtuallidar{virtuallidar}

{

}


StrategyController::~StrategyController()
{
}

void StrategyController::scanArea(){
	Route * route = new Route();
	map mapCopy = Map;
	VSLAM vslam(&mapCopy, &virtualrosbee, route, &virtuallidar);
	mapCopy.setScale(5);
	mapCopy.setScaledLocationValue(5, 1, 1);
	mapCopy.setScaledLocationValue(5, 2, 1);
	mapCopy.setScaledLocationValue(5, 3, 1);
	mapCopy.setScaledLocationValue(5, 4, 1);
	mapCopy.setScaledLocationValue(5, 5, 1);
	mapCopy.setScaledLocationValue(4, 5, 1);
	mapCopy.setScaledLocationValue(3, 5, 1);
	mapCopy.setScaledLocationValue(2, 5, 1);
	mapCopy.setScaledLocationValue(1, 5, 1);
	while (!vslam.bool_isVSLAMDone && mapCopy.contains(0)){ vslam.run();
	getchar();
	mapCopy.print();
	}
	mapCopy.print();
	getchar();
}

void StrategyController::searchArea(){
	AreaCoveringAlgorithm(&copter, &Map);
	Map.print();
	getchar();
}
