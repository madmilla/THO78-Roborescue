#include "StrategyController.h"


StrategyController::StrategyController(map Map, QuadCopter copter, virtualRosbee rosbee, Lidar lidar) :
copter{ copter },
rosbee{ rosbee },
Map{ Map },
lidar{lidar}

{

}


StrategyController::~StrategyController()
{
}

void StrategyController::scanArea(){
	Route * route = new Route();
	map mapCopy = Map;
	VSLAM vslam(&mapCopy, &rosbee, route, &lidar);
	mapCopy.setScale(5);
	mapCopy.setScaledLocationValue(8, 8, 1);
	mapCopy.setScaledLocationValue(8, 9, 1);
	mapCopy.setScaledLocationValue(8, 10, 1);
	mapCopy.setScaledLocationValue(8, 7, 1);
	while (mapCopy.contains(0)){ vslam.run();
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
