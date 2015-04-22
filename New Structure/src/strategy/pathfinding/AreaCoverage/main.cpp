#include <iostream>
#include "dimension.h"
#include "testcopter.h"
#include "arraymap.h"
#include "areacoveringalgorithm.h"
using namespace std;

int main()
{
    Dimension Sightrange(3,3);
    Dimension coptersize(1,1);
    TestCopter copter(coptersize,Sightrange,1,1);
    ArrayMap* map = new ArrayMap();
    AreaCoveringAlgorithm alg(copter,map);
    alg.testCoverage();

}

