/**
 * @file scanArea.h
 * @author Coen Andriessen
 * @version 1.3
 */

#ifndef SCANAREA_H
#define SCANAREA_H

#include <iostream>
#include "Map.h"
#include "Rosbee.h"
#include "MapSearchNode.h"


class scanArea
{
public:
    // Constructor of scanArea.
    scanArea(Map *map, Rosbee *rosbee, MapSearchNode *mapSearchNode);
    // Destructor of scanArea.
    ~scanArea();
    // Function to start the scan algorithm.
    void run();
    // Function to run the scan algorithm.
    int * scanMidAlgorithm(int x, int y);
private:
    Map *map;
    Rosbee *rosbee;
    MapSearchNode *mapSearchNode;

};

#endif // SCANAREA_H
