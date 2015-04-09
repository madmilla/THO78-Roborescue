#include "testcopter.h"
#include "testatv.h"
#include "dimension.h"
#include "pairwisemove.h"

int main(int argc, char *argv[])
{
    PairWiseMove move;

    Dimension atvsize(1,1);
    Dimension coptersize(1,1);
    Dimension searchSize(2,2);
    TestCopter copter(coptersize,searchSize,4,4);
    testATV atv(atvsize, 0, 0);

    std::vector<WayPoint> atvRoute;
    atvRoute.push_back(WayPoint(1, 1));


    std::vector<WayPoint> result = move.quadCopterPairRoute(atvRoute, atv, copter );

    if(result.size() > 0){
    if(result[0].x == 0 && result[0].y == 0){
        return 0;
    }
}

    return 1;
}
