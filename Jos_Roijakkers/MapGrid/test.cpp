#include "test.h"
#include <iostream>
#include "map.h"
#include "cell.h"
#include "mapwindow.h"

Test::Test():
    errDetect(0)
{
}

Test::~Test()
{

}

void Test::assert(bool testSuccess, const std::string& testName)
{
    std::cout << "TEST: " + testName << std::endl;
    if(!testSuccess)
    {
        std::cout << "FAILED" << std::endl << std::endl;
        errDetect++;
        return;
    }
    std::cout << "Success" << std::endl << std::endl;
}

int Test::run()
{
    std::cout << "Start Testing\n";
    std::cout << "Testing cells\n";
    Cell* testCell = new Cell();
    assert(testCell->getTerrainType() == Cell::TERRAINTYPE::EMPTY, "Terrain is empty");
    assert(testCell->isQuadcopterPresent() == false, "no Quadcopter present");
    assert(testCell->isATVPresent() == false, "no ATV present");
    assert(testCell->isRosbeePresent() == false, "no Rosbee present");

    if(errDetect > 0)
    {
        std::cout << "TEST FAILED" << std::endl << "I Found : " << errDetect << " Errors.. " << std::endl;
        return -1;
    }
    std::cout << "TEST SUCCESS" << std::endl;
    return 0;
}
