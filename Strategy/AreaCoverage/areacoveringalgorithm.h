#ifndef AREACOVERINGALGORITHM_H
#define AREACOVERINGALGORITHM_H
#include "waypoint.h"
#include "arraymap.h"
#include "testcopter.h"
class AreaCoveringAlgorithm
{
public:
    void setCopterSquare(TestCopter copt, ArrayMap* map);
    int followCovered(TestCopter *copter, ArrayMap* mapp, int wallnumber, int coveredNumber);
    void registerLocation(ArrayMap*,TestCopter*);
    AreaCoveringAlgorithm(TestCopter copter, ArrayMap *mapp);
    ~AreaCoveringAlgorithm();
    int followWall(TestCopter *copter, ArrayMap* mapp, int wallnumber);
    std::vector<WayPoint> result;
    void drawWayPoints(ArrayMap*);
    bool testCoverage();
private:
    ArrayMap* globalmap;
    void goForward();
    int pointOn(int x, int y, TestCopter *copter, ArrayMap* map);
};

#endif // AREACOVERINGALGORITHM_H
