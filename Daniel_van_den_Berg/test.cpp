#include <iostream>
#include "MapSystem/mapeditor.h"
#include <QStringList>
#include <QDebug>
#include <stdlib.h>
#include <string>
#include <time.h>

void assert(std::string string, bool success){
    std::cout << string;
    if (!success){
        std::cout << " failed.";
        exit(-1);
    }
    std::cout << " succeeded.\n"
}

int main(int argc, char *argv[])
{
    MapEditor *mapEditor = new MapEditor();
    qDebug() << "Showing all maps\n";
    qDebug() << mapEditor->getAvailableMaps().join("\n");
    srand(time(NULL));
    std::string mapname = ""+rand();
    while (mapEditor->getAvailableMaps().contains(mapname)){
        mapname = ""+rand();
    }
    mapEditor->createNewMap(mapname);
    assert("Creating map",mapEditor->getAvailableMaps().contains(mapname+".map"));
    mapEditor->removeMap(mapname);
    assert("Removing map",!mapEditor->getAvailableMaps().contains(mapname+".map"));

    delete mapEditor;
    return 0;
}
