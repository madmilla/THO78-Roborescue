/**
 * @file main.cpp
 * @author Coen Andriessen
 * @version 1.3
 */

//#include "mainwindow.h"
//#include <QApplication>
#include <scanArea.h>
#include <Rosbee.h>
#include <map.hpp>
#include <Test.h>
#include <MapSearchNode.h>
#include <mapLogicVSLAM.h>
#include <Route.h>

/**
 *
 * @param args
 */

int main(int argc, char *argv[]){
    //QApplication a(argc, argv);
    Rosbee rosbee;
    Route *route = new Route;
    map Map;
    Test test(&Map);  
    //Map.loadMap(Map.chooseMap());
    MapSearchNode mapSearchNode(&Map, route);
	mapLogicVSLAM MapLogicVSLAM(&Map, &rosbee);
	scanArea scanarea(&Map, &rosbee, &mapSearchNode, route, &MapLogicVSLAM);
    //MainWindow w(&map, &rosbee, &scanarea);
    //test.testsBeforeScanning();
    scanarea.run();
    //test.testsAfterScanning();
    //w.show();
    //return a.exec();
	while (true){

	}
    return 0;
}
