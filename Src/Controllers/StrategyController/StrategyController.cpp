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
	while (mapCopy.contains(0)){ vslam.run(); break; }
	mapCopy.print();
	getchar();
}

void StrategyController::searchArea(){
	AreaCoveringAlgorithm(&copter, &Map);
	Map.print();
	getchar();
}
