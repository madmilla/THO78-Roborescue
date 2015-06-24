#pragma once
#include "../../map/MapStructure/map.hpp"
#include "../../strategy/pathfinding/VSLAM/VSLAM.h"
#include "../../strategy/pathfinding/AreaCoverage/areacoveringalgorithm.h"
class StrategyController
{
public:
	virtualLidar virtuallidar;
	virtualRosbee virtualrosbee;
	map Map;
	StrategyController(map Map, QuadCopter copter, virtualRosbee rosbee, virtualLidar virtuallidar);
	~StrategyController();
	void scanArea();
	void searchArea();
	void movePairwise();

	QuadCopter copter;
};

