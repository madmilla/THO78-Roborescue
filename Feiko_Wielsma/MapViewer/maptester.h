#ifndef MAPTESTER_H
#define MAPTESTER_H
#include "mapsystem.h"
#include <string>

class MapTester
{
public:
    MapTester(MapSystem* mapSystem);
    ~MapTester();
    bool runTests();
    void assert(bool ,std::string);
private:
    MapSystem* mapSystem;
    bool testsSucceeded;
};

#endif // MAPTESTER_H
