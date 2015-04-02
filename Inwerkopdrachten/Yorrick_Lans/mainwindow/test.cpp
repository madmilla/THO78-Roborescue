#include "test.h"
#include <iostream>
#include "map.h"
#include "cell.h"

Test::Test():
    errors(0)
    {
    }

void Test::assert(bool testSucceeded, const std::string& testName)
{
    std::cout << "TEST: " + testName << std::endl;
    if(!testSucceeded)
    {
        std::cout << "FAILED" << std::endl << std::endl;
        errors++;
        return;
    }
    std::cout << "Succeeded" << std::endl << std::endl;
}

int Test::runTests()
{
    std::cout << "########STARTING TEST########" << std::endl;
    std::cout << "########CELL CONSTRUCTORS########" << std::endl;
    cell* testCell = new cell();
    assert(testCell->surrounding == terrainType::none, "Cell terrain is empty");
    assert(testCell->quadPresent == false, "Cell has no quadcopter");
    assert(testCell->rosbeePresent == false, "Cell has no rosbee");
    assert(testCell->ATVPresent == false, "Cell has no ATV");

    std::cout << "########CELL METHODS########" << std::endl;
    testCell->changeTerrain(terrainType::grass);
    testCell->removeVehicle(vehicleType::quadCopter);
    testCell->removeVehicle(vehicleType::rosbee);
    testCell->removeVehicle(vehicleType::ATV);
    assert(testCell->surrounding == terrainType::grass, "Cell terrain is grass");
    assert(testCell->quadPresent == false, "Cell has no quadcopter");
    assert(testCell->rosbeePresent == false, "Cell has no rosbee");
    assert(testCell->ATVPresent == false, "Cell has no ATV");

    testCell->placeVehicle(vehicleType::quadCopter);
    testCell->placeVehicle(vehicleType::rosbee);
    testCell->placeVehicle(vehicleType::ATV);
    assert(testCell->quadPresent == true, "Cell has a quadcopter");
    assert(testCell->rosbeePresent == true, "Cell has a rosbee");
    assert(testCell->ATVPresent == true, "Cell has a ATV");


    if(errors > 0)
    {
        std::cout << "########TEST FAILED########" << std::endl <<
                     "FOUND " << errors << " ERRORS" << std::endl;
        return -1;
    }
    std::cout << "########TEST SUCCEEDED########" << std::endl;
    return 0;
}
