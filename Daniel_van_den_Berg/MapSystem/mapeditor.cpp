#include "mapeditor.h"
#include <QDir>
#include <iostream>

MapEditor::MapEditor()
{

}

void MapEditor::load(std::string mapName){
    std::string fileNameC = QDir::currentPath().toStdString() + "/maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    std::cout << "Loading "<<fileNameC<<"\n";
    std::flush(std::cout);
}

void MapEditor::createNewMap(std::string mapName){
    std::cout << "Creating "<<mapName<<"\n";
    std::flush(std::cout);
}

QStringList MapEditor::getAvailableMaps(){
    QStringList nameFilter("*.map");
    QDir directory(QDir::currentPath() + "/maps");
    if (!directory.exists()){
        std::cout << "Creating directory "<<directory.absolutePath().toStdString()<<"\n";
        std::flush(std::cout);
        directory.mkdir(directory.absolutePath());
    }
    return directory.entryList(nameFilter);
}

void MapEditor::saveMap(){
    std::cout << "Saving map\n";
    std::flush(std::cout);
}

MapEditor::~MapEditor()
{

}

