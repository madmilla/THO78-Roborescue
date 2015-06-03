#include <iostream>
#include "dimension.h"
#include "testcopter.h"
#include "arraymap.h"
#include "areacoveringalgorithm.h"
#include "databaseconnector.h"
#include "point.hpp"
using namespace std;
void test(int i){
    Dimension Sightrange(3,3);
    Dimension coptersize(1,1);
    TestCopter copter(coptersize,Sightrange,1,1);
    ArrayMap* map = new ArrayMap(i);
    AreaCoveringAlgorithm alg(copter,map);
    alg.testCoverage();
}

int main(int argc, char *argv[])
{
    //test(1);
    try{
    databaseConnector Connector("127.0.0.1:3306","root","","robodata");}
    catch(exception e){
        std::cout <<e.what();

    }
    //Connector.setMap(Connector.getMaps().at(0).id);
    //std::cout <<Connector.isAccessable(point(100,100));
    return 0;

}

