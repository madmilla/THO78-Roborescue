/**
 * @file main.cpp
 * @author Coen Andriessen
 * @version 1.3
 */

#include <scanArea.h>
#include <Rosbee.h>
#include <map.hpp>
#include <Test.h>
#include <MapSearchNode.h>
#include <mapLogicVSLAM.h>
#include <Route.h>
#include <Lidar.h>

/**
 *
 * @param args
 */

int main(int argc, char *argv[]){
    Rosbee rosbee;
	Lidar lidar;
    Route *route = new Route;
    map Map;
    Test test(&Map);  

	scanArea scanarea(&Map, &rosbee, &mapSearchNode, route, &MapLogicVSLAM, &lidar);
	while(1){
		scanarea.run();
		if (MapLogicVSLAM.isMapFullyScanned()){
			break;
		}
	}
	Map.print();
	while (true);
    return 0;
}
