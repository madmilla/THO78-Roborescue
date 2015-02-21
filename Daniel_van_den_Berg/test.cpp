#include <iostream>
#include "MapSystem/mapeditor.h"
#include <QStringList>
#include <QDebug>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <QString>

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
    qDebug() << "Showing all maps";
    qDebug() << mapEditor->getAvailableMaps().join("\n");
    srand(time(NULL));
    std::string mapname = "testmap";
    mapname += std::to_string(rand());
    while (mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map"))){
        std::string mapname = "testmap";
        mapname += std::to_string(rand());
    }
    mapEditor->createNewMap(mapname);
    assert("Creating map "+mapname,mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map")));
    qDebug() << "Showing all maps";
    qDebug() << mapEditor->getAvailableMaps().join("\n");
    mapEditor->removeMap(mapname);
    assert("Removing map "+mapname,!mapEditor->getAvailableMaps().contains(QString::fromStdString(mapname+".map")));
    qDebug() << "Showing all maps";
    qDebug() << mapEditor->getAvailableMaps().join("\n");

    delete mapEditor;
    return 0;
}
