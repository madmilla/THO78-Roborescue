#include "waypoint.h"
#include "testcopter.h"
#include "testatv.h"
#include <vector>

#ifndef PAIRWISEMOVE
#define PAIRWISEMOVE

class PairWiseMove{
public:
    PairWiseMove();

    std::vector<WayPoint> quadCopterPairRoute(std::vector<WayPoint> atvRoute,
                                             testATV atv,
                                             TestCopter copter
                                             );
};

#endif // PAIRWISEMOVE

