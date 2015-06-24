#ifndef _STRATEGY_CONTROLLER_H
#define _STRATEGY_CONTROLLER_H
#include "Map.hpp"
#include "VSLAM.h"
#include "areacoveringalgorithm.h"
#include "MapLogicVSLAM.h"
class StrategyController
{
public:
	virtualLidar virtuallidar;
	virtualRosbee virtualrosbee;
	Map map;
	StrategyController(Map map, VirtualQuadCopter copter, virtualRosbee rosbee, virtualLidar virtuallidar);
	~StrategyController();
	void scanArea();
	void searchArea();
	void movePairwise();

	VirtualQuadCopter copter;
};
#endif

