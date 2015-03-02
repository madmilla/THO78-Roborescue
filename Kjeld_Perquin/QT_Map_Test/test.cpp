#include "test.h"
#include <iostream>
#include "map.h"
#include "tile.h"

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
    std::cout << "########MAP CONSTRUCTORS########" << std::endl;
    Map* testMap = new Map();
    assert(testMap->getRows() == 0, "Zero rows");
    assert(testMap->getColumns() == 0, "Zero columns");

    testMap = new Map(1,0);
    assert(testMap->getRows() == 1, "One row");
    assert(testMap->getColumns() == 0, "Zero columns");

    testMap = new Map(0,1);
    assert(testMap->getRows() == 0, "Zero rows");
    assert(testMap->getColumns() == 1, "One column");

    testMap = new Map(20,20);
    assert(testMap->getRows() == 20, "Twenty rows");
    assert(testMap->getColumns() == 20, "Twenty columns");

    std::cout << "########TILE CONSTRUCTORS########" << std::endl;
    Tile* testTile = new Tile();
    assert(testTile->getTerrainType() == Tile::TERRAIN_TYPE::NONE, "Tile terrain is empty");
    assert(testTile->isQuadcopterPresent() == false, "Tile has no quadcopter");
    assert(testTile->isRosbeePresent() == false, "Tile has no rosbee");
    assert(testTile->isATVPresent() == false, "Tile has no ATV");

    testTile = new Tile(Tile::TERRAIN_TYPE::WATER, true, true, true);
    assert(testTile->getTerrainType() == Tile::TERRAIN_TYPE::WATER, "Tile terrain is water");
    assert(testTile->isQuadcopterPresent() == true, "Tile has a quadcopter");
    assert(testTile->isRosbeePresent() == true, "Tile has a rosbee");
    assert(testTile->isATVPresent() == true, "Tile has a ATV");

    std::cout << "########TILE METHODS########" << std::endl;
    testTile->setTerrainType(Tile::TERRAIN_TYPE::GRASS);
    testTile->removeVehicle(Tile::VEHICLE_TYPE::QUADCOPTER);
    testTile->removeVehicle(Tile::VEHICLE_TYPE::ROSBEE);
    testTile->removeVehicle(Tile::VEHICLE_TYPE::ATV);
    assert(testTile->getTerrainType() == Tile::TERRAIN_TYPE::GRASS, "Tile terrain is grass");
    assert(testTile->isQuadcopterPresent() == false, "Tile has no quadcopter");
    assert(testTile->isRosbeePresent() == false, "Tile has no rosbee");
    assert(testTile->isATVPresent() == false, "Tile has no ATV");

    testTile->addVehicle(Tile::VEHICLE_TYPE::QUADCOPTER);
    testTile->addVehicle(Tile::VEHICLE_TYPE::ROSBEE);
    testTile->addVehicle(Tile::VEHICLE_TYPE::ATV);
    assert(testTile->isQuadcopterPresent() == true, "Tile has a quadcopter");
    assert(testTile->isRosbeePresent() == true, "Tile has a rosbee");
    assert(testTile->isATVPresent() == true, "Tile has a ATV");

    testTile->clearTile();
    assert(testTile->getTerrainType() == Tile::TERRAIN_TYPE::NONE, "Tile terrain is empty");
    assert(testTile->isQuadcopterPresent() == false, "Tile has no quadcopter");
    assert(testTile->isRosbeePresent() == false, "Tile has no rosbee");
    assert(testTile->isATVPresent() == false, "Tile has no ATV");


    if(errors > 0)
    {
        std::cout << "########TEST FAILED########" << std::endl <<
                     "FOUND " << errors << " ERRORS" << std::endl;
        return -1;
    }
    std::cout << "########TEST SUCCEEDED########" << std::endl;
    return 0;
}
