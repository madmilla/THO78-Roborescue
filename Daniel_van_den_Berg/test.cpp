#include <iostream>
#include "MapSystem/mapeditor.h"
#include <QStringList>
#include <QDebug>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <QString>

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

void assert(std::string string, bool success){
    std::cout << string;
    if (!success){
        std::cout << " failed.";
        exit(-1);
    }
    std::cout << " succeeded.\n";
}

int main(int argc, char *argv[])
{
    MapEditor *mapEditor = new MapEditor();
    srand(time(NULL));
    std::string mapname = "testmap";
    mapname += to_string(rand());
    while (mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map"))){
        std::string mapname = "testmap";
        mapname += to_string(rand());
    }
    assert("Parsing map name",mapEditor->parseMapName("test.map") == "test");
    mapEditor->createNewMap(mapname);
    assert("Creating map "+mapname,mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map")));
    mapEditor->removeMap(mapname);
    assert("Removing map "+mapname,!mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map")));

    delete mapEditor;
    return 0;
}
