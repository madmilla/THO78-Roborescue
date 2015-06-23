#pragma once


class StrategyController
#include "../../map/MapStructure/map.hpp"
#include "../../strategy/Common/Rosbee.h"
#include "../../strategy/pathfinding/VSLAM/scanArea.h"
{
public:

	StrategyController(map map);
	~StrategyController();
private:
	map globalMap;
};

