/**
 * @file Map.h
 * @author Coen Andriessen
 * @version 1.5
 */

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <Rosbee.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <vector>

using namespace std;

class Map
{
public:
    // Constructor of map.
    Map(Rosbee * rosbee);
    // Destructor of map.
    ~Map();
    // Function to set a tile in the map.
    void setTile(int x, int y, int * value);
    // Function to get a tile in the map.
    int getTile(int x, int y);
    // Function to check if the rosbee location is changed.
    void rosbeeLocationChanged();
    // Function to get a specify tile for the scanning algorithm.
    int * getTileForMidAlgorithm(int x, int y);
    // Function to check if the map is loaded.
    bool isLoaded();
    // Function to check if the map is full scanned.
    bool isMapFullScanned();
    // Function to check if the tile is connected to a tile which is not scanned.
    bool isTileConnectedScanned(int x, int y);
    // Function to load a map from a textfile.
    void loadMap(const char * filename);
    // Function to choose a map from storage.
    const char * chooseMap();
    // Function to get number of steps.
    int getNumberOfSteps();
    int GetMap( int x, int y );
    int blockWidth;
    int blockHeight;
    void tilesInRangeLidar();

protected:
    Rosbee * rosbee;
private:
    bool bool_isLoaded;
    std::vector<std::vector<int*>> myMap;
    vector <std::pair<int, int>> myRoute;
    const char * pathMap1 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map1.txt";
    const char * pathMap2 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map2.txt";
    const char * pathMap3 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map3.txt";
    const char * pathMap4 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map4.txt";
    const char * pathMap5 = "C:\\Users\\coen__000\\Documents\\TestSystem\\Map6.txt";
    int numberOfSteps = 0;
};

#endif // MAP_H
