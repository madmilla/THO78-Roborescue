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
	
	std::cout << alg.getRoute();
	std::cout << alg.getRoute().scale;
	map.print();
	getchar();
}

int main(int argc, char *argv[])
{
    test(0);


	//while (true);
    return 0;


}

