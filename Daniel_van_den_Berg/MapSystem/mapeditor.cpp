#include "mapeditor.h"
#include <QDir>
#include <iostream>
#include <regex>

MapEditor::MapEditor()
{

}

void MapEditor::load(std::string mapName){
    mapName = parseMapName(mapName);
    std::string fileNameC = QDir::currentPath().toStdString() + "/maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    std::cout << "Loading "<<fileNameC<<"\n";
    std::flush(std::cout);
}

void MapEditor::createNewMap(std::string mapName){
    mapName = parseMapName(mapName);
    std::cout << "Creating "<<mapName<<"\n";
    std::flush(std::cout);
    std::string fileNameC = QDir::currentPath().toStdString() + "/maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.close();
}

void MapEditor::removeMap(std::string mapName){
    mapName = parseMapName(mapName);
    std::string fileNameC = QDir::currentPath().toStdString() + "/maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    file.remove();
    file.close();
}

std::string MapEditor::parseMapName(std::string text){
    std::regex regex("\\.map$");
    std::cout << "Parsing [" << text << "] to [" << std::regex_replace(text,regex,std::string("")) << "]\n";
    std::flush(std::cout);
    return std::regex_replace(text,regex,std::string(""));
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

