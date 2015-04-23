#include "waypoint.h"
#include "quadCopter.h"
#include "ATV.h"
#include <vector>

#ifndef PAIRWISEMOVE
#define PAIRWISEMOVE

class PairWiseMove{
public:
    PairWiseMove();

    std::vector<WayPoint> quadCopterPairRoute(std::vector<WayPoint> atvRoute,
                                             ATV atv,
                                             quadCopter copter
                                             );
};

#endif // PAIRWISEMOVE

