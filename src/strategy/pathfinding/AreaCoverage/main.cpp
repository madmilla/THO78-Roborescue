#include <iostream>
#include "dimension.h"
#include "testcopter.h"
#include "arraymap.h"
#include "areacoveringalgorithm.h"
using namespace std;
void test(int i){
	// Geen whitespaces
    Dimension Sightrange(3,3);
    Dimension coptersize(1,1);
    TestCopter copter(coptersize,Sightrange,1,1);
    ArrayMap* map = new ArrayMap(i);

    AreaCoveringAlgorithm alg(copter,map);
    alg.testCoverage();


}

int main(int argc, char *argv[])
{
	// Uitlijnen en je cout ff professioneel maken
	if(!argc){std::cout<<"Dude je moet wel een getaletje invoeren (1 tot en met 4)";return 0;}
    test(argv[0]);
    return 0;

}

