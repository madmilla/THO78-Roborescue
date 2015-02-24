#include "test.h"
#include <iostream>
#include <string>
using namespace std;


Test::Test()
{

}
void Test::assert(std::string string, bool success){
    std::cout << string;
    if (!success){
        std::cout << " failed.\n" << __FILE__ << ":."<<__LINE__ << "\n";
        exit(-1);
    }
    std::cout << " succeeded.\n";
}
void Test::run(){
    cout << "========New Map  Test========" << endl;
    map = new Map(20,20);
    assert("Map Pixel Empty",map->getPixel(1,1).isEmpty());
    assert("Map Height",map->getWidth() == 20);
    assert("Map Width",map->getHeight() == 20);
    map->saveFile("testRun");
    QFile file("maps/testRun.map");
    assert("File saved",file.exists());
    cout << "========Edit Map Test========" << endl;
    map = new Map("testRun.map");
    assert("Map Pixel Empty",map->getPixel(1,1).isEmpty());
    assert("Map Height",map->getWidth() == 20);
    assert("Map Width",map->getHeight() == 20);
    QJsonObject typeObject;
    typeObject["type"] = "wood";
    map->setPixel(24,24,typeObject);
    assert("Map Pixel Shouldn't be empty",!map->getPixel(1,1).isEmpty());
    assert("Map pixel should contain wood",map->getPixel(1,1)[0].toObject()["type"].toString() ==  "wood");
    map->deletePixel(24,24);
    assert("Map pixel should be empty",map->getPixel(1,1).isEmpty());
    cout << "========All The Tests Have Succeeded========" << endl;
    cout << "========Ending the program now      ========" << endl;
}

Test::~Test()
{

}

