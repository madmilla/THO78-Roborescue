#include <iostream>
#include "MapSystem/mapeditor.h"
#include <QStringList>
#include <QDebug>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <QString>
#include <regex>

#include<sstream>
    template <typename T>
    std::string to_string(T value)
    {
      //create an output string stream
      std::ostringstream os ;

      //throw the value into the string stream
      os << value ;

      //convert the string stream into a string and return
      return os.str() ;
    }

template <typename T, typename U>
bool assert(std::string string, T get, U shouldbe){
    std::cout << string;
    if (get != shouldbe){
        std::cout << " failed.\nGot [" << to_string(get) << "]\nShould be [" << to_string(shouldbe) << "]\n";
        //exit(-1);
        return false;
    }
    std::cout << " succeeded.\n";
    return true;
}

int main(int argc, char *argv[])
{
    bool succeeded = true;

    MapEditor *mapEditor = new MapEditor();
    srand(time(NULL));
    std::string mapname = "testmap";
    mapname += to_string(rand());
    while (mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map"))){
        mapname = "testmap";
        mapname += to_string(rand());
    }

    std::string s ("there is a subsequence in the string");
    std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

      // using string/c-string (3) version:
    std::string a = std::regex_replace (s,e,"sub-$2");
    succeeded &= assert("Regex",a,"there is a sub-sequence in the string");

    succeeded &= assert("Parsing map name",mapEditor->parseMapName("test.map"),"test");
    mapEditor->createNewMap(mapname);
    succeeded &= assert("Creating map "+mapname,mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map")),true);

    mapEditor->load(mapname);
    succeeded &= assert("Loading map "+mapname,mapEditor->getLoadedMap() == mapname+".map",true);

    assert("Placing object in map",mapEditor->placeObject(5,5,mapEditor->WALL),true);
    assert("Placing object in map",mapEditor->placeObject(1,1,mapEditor->DRONE),true);
    assert("Placing outside of map gets rejected",mapEditor->placeObject(1,21,mapEditor->DRONE),false);

    mapEditor->saveMap();

    mapEditor->removeMap(mapname);
    succeeded &= assert("Removing map "+mapname,mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map")),false);

    delete mapEditor;
    return (succeeded == true)?0:1;
}
