/**
 * @file scanArea.h
 * @author Coen Andriessen
 * @version 1.3
 */

#ifndef SCANAREA_H
#define SCANAREA_H

#include <iostream>
#include "../../../map/mapstructure/map.hpp"
#include "../../Common/virtualRosbee.h"
#include "../AStar/MapSearchNode.h"
#include "../../Common/route.h"
#include "mapLogicVSLAM.h"
#include "../../Common/Lidar.h"


class scanArea
{
public:
    // Constructor of scanArea.
	scanArea(map *Map, virtualRosbee *rosbee, MapSearchNode *mapSearchNode, Route *route, mapLogicVSLAM *MapLogicVSLAM, Lidar *lidar);
    // Destructor of scanArea.
    ~scanArea();
    // Function to start the scan algorithm.
    void run();
private:
    map *Map;
	virtualRosbee *rosbee;
    MapSearchNode *mapSearchNode;
	mapLogicVSLAM *MapLogicVSLAM;
    Route * route;
	Lidar * lidar;
	int * newRosbeeLocation;
	int * tileLocation;

};

#endif // SCANAREA_H
