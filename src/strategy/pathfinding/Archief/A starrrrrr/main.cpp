/**
 * @file main.cpp
 * @author Coen Andriessen
 * @version 1.3
 */

#include "mainwindow.h"
//#include <QApplication>
#include "scanArea.h"
#include "Rosbee.h"
#include "Map.h"
#include "Test.h"
#include "MapSearchNode.h"

/**
 *
 * @param args
 */

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Rosbee rosbee;
    Map map(&rosbee);
    Test test(&map);  
    map.loadMap(map.chooseMap());
    MapSearchNode mapSearchNode(&map);
    scanArea scanarea(&map, &rosbee, &mapSearchNode);
    MainWindow w(&map, &rosbee, &scanarea);
    test.testsBeforeScanning();
    scanarea.run();
    test.testsAfterScanning();
    w.show();
    return a.exec();
    //return 0;
}
