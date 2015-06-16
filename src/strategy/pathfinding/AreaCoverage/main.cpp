#include <iostream>
#include "dimension.h"
#include "testcopter.h"
#include "areacoveringalgorithm.h"
#include "point.hpp"
using namespace std;
void test(int i){
    Dimension Sightrange(3,3);
    Dimension coptersize(1,1);
    TestCopter copter(coptersize,Sightrange,1,1);
	map map;
    AreaCoveringAlgorithm alg(copter,&map);
    //alg.testCoverage();
	std::cout << "\n";

	for (int i = 0; i < 70; i++){
		for (int ii = 0; ii < 70; ii++){
			std::cout << map.getLocationValue(i, ii);
			//std::cout << ii;
		}
		std::cout << "\n";
	}
}

int main(int argc, char *argv[])
{
    test(0);


	while (true);
    return 0;


}

