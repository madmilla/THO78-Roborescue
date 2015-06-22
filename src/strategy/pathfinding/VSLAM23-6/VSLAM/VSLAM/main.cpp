/**
 * @file main.cpp
 * @author Coen Andriessen
 * @version 1.3
 */

#include <VSLAM.h>
#include <Rosbee.h>
#include <map.hpp>
#include <Test.h>
#include <MapSearchNode.h>
#include <mapLogicVSLAM.h>
#include <Route.h>
#include <Lidar.h>
#include <stdio.h>

/**
 *
 * @param args
 */

int main(int argc, char *argv[]){
    Rosbee rosbee;
	Lidar lidar;
    Route *route = new Route;
    map Map;
    MapSearchNode mapSearchNode(&Map, route);
	mapLogicVSLAM MapLogicVSLAM(&Map, &rosbee, &lidar);
	Test test(&Map, &MapLogicVSLAM, &rosbee);
	test.setObjectsInMap();
	VSLAM vslam(&Map, &rosbee, &mapSearchNode, route, &MapLogicVSLAM, &lidar);
	while(1){
		vslam.run();
		if (MapLogicVSLAM.isMapFullyScanned()){
			break;
		}
	}
	test.startTests();
    return 0;
}
