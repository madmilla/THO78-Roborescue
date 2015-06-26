#ifndef _STRATEGY_CONTROLLER_H
#define _STRATEGY_CONTROLLER_H
#include "Map.hpp"
#ifdef _WIN32
#include "../../../Deps/incl/MingwThread/mingw.thread.h"
#endif
#ifdef linux
	#include <thread>
#endif



#include "VSLAM.h"
#include "areacoveringalgorithm.h"
#include "mapLogicVSLAM.h"
class StrategyController
{
public:
	std::thread* Thread;
	virtualLidar virtuallidar;
	virtualRosbee virtualrosbee;
	Map* map;
        void run();
	StrategyController(Map *map, VirtualQuadCopter copter, virtualRosbee rosbee, virtualLidar virtuallidar);
	~StrategyController();
	void scanArea();
	void searchArea();
	void movePairwise();

	VirtualQuadCopter copter;
};
#endif

