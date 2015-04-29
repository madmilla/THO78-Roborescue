#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Map
{
public:
    static const int MAP_WIDTH = 20;
    static const int MAP_HEIGHT = 20;
    static const char CHAR_FREE = '0';
    static const char CHAR_BLOCK = '1';
    static const char CHAR_QUAD = '2';
    static const char CHAR_FINISH = '3';
    static const char CHAR_ROUTE = '4';
    static const int FREE = 0;
    static const int BLOCK = 1;
    static const int QUAD = 2;
    static const int FINISH = 3;
    static const int ROUTE = 4;

    Map();
    ~Map();

    void set(int x, int y, int value);
    int get(int x, int y);

    static Map * loadFromFile(const char * filename);
    void saveToFile(const char * filename);

    void setFinish();
    typedef int (*pointer_to_arrays)[MAP_HEIGHT];

    pointer_to_arrays getObjectMatrix();
    //void setRoute(int waypoints[][MAP_HEIGHT], const int numberOfWaypoints);

private:
    int objectMatrix[MAP_WIDTH][MAP_HEIGHT];
};

#endif // MAP_H
