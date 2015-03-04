#include "test.h"

Test::Test(QString name):
    name { name }
{

}

Test::~Test()
{
    delete map;
}

void Test::start() {

    std::cout << "-----------start test-----------" << std::endl << std::endl;

    map = new Map{};


    if(!map->readFile(name)) {
        std::cout << "could not open file with path " << name.toStdString() << std::endl;
    }
    else {
        std::cout << "the map is succesfully opened" << std::endl;
    }

    if(map->hasData()) {
        std::cout << "the map contains data" << std::endl;
    }
    else {
        std::cout << "the map contains nothing" << std::endl;
        return;
    }

    if(!map->legit_size_checker()) {
        std::cout << "the map has no valid size for x && y" << std::endl;
    }
    else {
        std::cout << "valid x && y map size" << std::endl;
    }

    if(!map->legit_char_checker()) {
        std::cout << "the map contains bad characters" << std::endl;
    }
    else {
        std::cout << "the map contains valid characters" << std::endl;
    }
    std::cout << std::endl << "-----------stop test-----------" << std::endl;
}

