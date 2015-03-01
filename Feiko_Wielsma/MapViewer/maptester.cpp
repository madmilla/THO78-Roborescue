#include "maptester.h"
#include <iostream>

MapTester::MapTester(MapSystem* mapSystem)
    :
    mapSystem{mapSystem},
    testsSucceeded{true}
{

}

MapTester::~MapTester()
{

}

void MapTester::assert(bool boolean, std::string message)
{
    std::cout << message;
    if(boolean)
    {
        std::cout << " passed!\n";
    }
    else
    {
        std::cout << " FAILED!\n";
        testsSucceeded = false;
    }
}

bool MapTester::runTests()
{
    assert(mapSystem->canSave() == false, "Unable to save if no map is loaded");

    QString existingFileName("../MapViewer/building.map");
    Map * openedMap = mapSystem->openMap(existingFileName);
    auto& openedObjects = openedMap->getObjects();
    assert(openedObjects.size() == 166, "OpenedMap has 166 objects");

    Map * map = mapSystem->createNewMap();

    ObjectType quad {ObjectType::Quad};
    ObjectType atv {ObjectType::ATV};
    ObjectType wall {ObjectType::Wall};
    ObjectType empty {ObjectType::Empty};
    auto& objects = map->getObjects();
    assert(objects.size() == 0, "Map is empty");

    map->addObject(Object(quad, QPoint(1,1)));
    assert(objects.size() == 1, "Map has 1 object");

    assert(objects[0].type == quad, "Type of first object is quad");
    assert(map->getType(1,1) == quad, "GetType 1,1 returns quad");

    map->setType(1,1, atv);
    assert(objects[0].type == atv, "Type of first object is atv");
    assert(map->getType(1,1) == atv, "GetType 1,1 returns atv");

    assert(map->getType(2,2) == empty, "GetColor on empty space returns white");

    map->setType(2,2, wall);

    assert(objects.size() == 2, "Map has 2 objects");

    assert(objects[1].type == wall, "Type of second object is wall");
    assert(map->getType(2,2) == wall, "GetType 2,2 returns wall");


    assert(mapSystem->canSave() == true, "CanSave returns true because there is a map");

    QString fileName("saveMap.map");
    mapSystem->saveMap(fileName);

    std::cout << "Clearing the current map\n";
    Map* emptyMap = mapSystem->createNewMap();
    auto& emptyMapObjects = emptyMap->getObjects();
    assert(emptyMapObjects.size() == 0, "Empty has 0 objects");

    Map* openedSaveMap = mapSystem->openMap(fileName);
    auto& openedSaveMapObjects = openedSaveMap->getObjects();
    assert(openedSaveMapObjects.size() == 2, "OpenedSaveMap has 2 objects");

    assert(objects[1].type == wall, "Type of second object is wall");
    assert(map->getType(2,2) == wall, "GetType 2,2 returns wall");


    if(testsSucceeded)
    {
        std::cout << "####################################\n" <<
                     "All tests passed! Testing succesfull\n"
                     "####################################\n";
    }
    else
    {
        std::cout << "####################################\n" <<
                     "#!!!!!ONE ORE MORE TESTS FAILED!!!!#\n"
                     "####################################\n";
    }

    return testsSucceeded;

}
