#ifndef AREACOVERINGALGORITHM_H
#define AREACOVERINGALGORITHM_H
#include "map.h"
#include "waypoint.h"
#include "cell.h"
#include "arraymap.h"
#include "testcopter.h"
class AreaCoveringAlgorithm
{
public:
    void setCopterSquare(TestCopter copt, ArrayMap* map);
    int followCovered(TestCopter *copter, ArrayMap* mapp, int wallnumber, int coveredNumber);
    void registerLocation(ArrayMap*,TestCopter*);
    AreaCoveringAlgorithm(TestCopter copter, ArrayMap *mapp);
    void getCells(Map map);
    ~AreaCoveringAlgorithm();
    std::vector<Cell> cells;
    void generateCellPath(Cell c);
    int followWall(TestCopter *copter, ArrayMap* mapp, int wallnumber);
    std::vector<WayPoint> result;
    void drawWayPoints(ArrayMap*);
private:
    void goForward();
    int pointOn(int x, int y, TestCopter *copter, ArrayMap* map);
    bool isInCell(Tile* t);

    void getCellFrom(Map map,Tile* source);
};

#endif // AREACOVERINGALGORITHM_H
