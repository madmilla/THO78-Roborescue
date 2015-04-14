#include "test.h"
#include "map.h"
#include "PointCloud.h"
#include "simulatemap.h"
#include <QCryptographicHash>
#include <qfile.h>
#include <iostream>

Test::Test()
{

}

Test::~Test()
{

}

int Test::run(){
    int error = 0;
    unsigned int size = 20;

    Map testMap("testMap.map", size,size);

    if(testMap.getMapContent().size() != size) error++;

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            if(testMap.getMapContent()[y].size() != size) error++;
            if(testMap.getMapObject(y,x) != 0) error++;
            testMap.setMapObject(1,y,x);
        }
    }

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            if(testMap.getMapObject(y,x) != 1) error++;
        }
    }

    testMap.setMapObject(0,size - 5, size - 2);
    if(testMap.getMapObject(size - 5,size - 2) != 0) error++;

    testMap.setMapObject(1,size - size,size - size);
    if(testMap.getMapObject(size - size,size -size) != 1) error++;

    testMap.setMapObject(1,size - 1,size - (size - 1));
    if(testMap.getMapObject(size - 1,size - (size - 1)) != 1) error++;

    testMap.setMapObject(0,size - 1,size - 1);
    if(testMap.getMapObject(size - 1,size - 1) != 0) error++;

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            testMap.setMapObject(0,y,x);
        }
    }

    testMap.saveMap();

    testMap.setMapObject(3,6,2);
    testMap.setMapObject(1,9,1);

    SimulateMap testSim(&testMap);

    testSim.setScanPoint(6,2);
    testSim.simulate();
    Pointcloud pC = testSim.getPointCloud();
    for(Pointcloud::Point p : pC.getPoints()){
        if(p.X != -1) error++;
        if(p.Y != -3) error++;
    }
    return error;
}
