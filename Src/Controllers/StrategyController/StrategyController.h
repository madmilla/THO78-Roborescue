#pragma once
#include "../../map/MapStructure/map.hpp"
#include "../../strategy/pathfinding/VSLAM/VSLAM.h"
#include "../../strategy/pathfinding/AreaCoverage/areacoveringalgorithm.h"
class StrategyController
{
public:
	Lidar lidar;
	virtualRosbee rosbee;
	map Map;
	StrategyController(map Map, QuadCopter copter, virtualRosbee rosbee, Lidar lidar);
	~StrategyController();
	void scanArea();
	void searchArea();
	void movePairwise();

	QuadCopter copter;
};

