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
    srand(time(NULL));
    std::string mapname = "testmap";
    mapname += to_string(rand());
    while (MapEditor::getInstance().getAvailableMaps().contains(QString::fromStdString(mapname+".map"))){
        mapname = "testmap";
        mapname += to_string(rand());
    }

    std::string s ("there is a subsequence in the string");
    std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

      // using string/c-string (3) version:
    std::string a = std::regex_replace (s,e,"sub-$2");
    succeeded &= assert("Regex",a,"there is a sub-sequence in the string");

    succeeded &= assert("Parsing map name",MapEditor::getInstance().parseMapName("test.map"),"test");
    MapEditor::getInstance().createNewMap(mapname);
    succeeded &= assert("Creating map "+mapname,MapEditor::getInstance().getAvailableMaps().contains(QString::fromStdString(mapname+".map")),true);

    MapEditor::getInstance().load(mapname);
    succeeded &= assert("Loading map "+mapname,MapEditor::getInstance().getLoadedMap() == mapname+".map",true);

    assert("Placing object in map",MapEditor::getInstance().placeObject(5,5,MapEditor::getInstance().WALL),true);
    assert("Placing object in map",MapEditor::getInstance().placeObject(1,1,MapEditor::getInstance().DRONE),true);
    assert("Placing object in map",MapEditor::getInstance().placeObject(1,2,MapEditor::getInstance().WALL),true);
    assert("Placing object in map",MapEditor::getInstance().placeObject(1,1,MapEditor::getInstance().WALL),true);
    assert("Placing outside of map gets rejected",MapEditor::getInstance().placeObject(1,21,MapEditor::getInstance().DRONE),false);

    QJsonArray objectsAtPosition = MapEditor::getInstance().getObjectsAt(1,1);
    succeeded &= assert("Getting objects at location",(objectsAtPosition.contains(MapEditor::getInstance().DRONE) && objectsAtPosition.contains(MapEditor::getInstance().WALL) && objectsAtPosition.size() == 2),true);

    succeeded &= assert("Removing object at location",MapEditor::getInstance().removeObject(1,1,MapEditor::getInstance().WALL),true);
    succeeded &= assert("Removing non-existing object at location gets rejected",MapEditor::getInstance().removeObject(1,1,MapEditor::getInstance().WALL),false);

    objectsAtPosition = MapEditor::getInstance().getObjectsAt(1,1);
    succeeded &= assert("Getting objects at location",(objectsAtPosition.contains(MapEditor::getInstance().DRONE) && objectsAtPosition.size() == 1),true);


    succeeded &= assert("Saving map "+mapname, MapEditor::getInstance().saveMap(),true);

    MapEditor::getInstance().removeMap(mapname);
    succeeded &= assert("Removing map "+mapname,MapEditor::getInstance().getAvailableMaps().contains(QString::fromStdString(mapname+".map")),false);

    return (succeeded == true)?0:1;
}
