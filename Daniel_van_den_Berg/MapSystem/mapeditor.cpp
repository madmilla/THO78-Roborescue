#include "mapeditor.h"
#include <QDir>
#include <iostream>
#include <regex>

MapEditor::MapEditor()
{

}

void MapEditor::load(std::string mapName){
    mapName = parseMapName(mapName);
    std::string fileNameC = "maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    std::cout << "Loading "<<fileNameC<<"\n";
    std::flush(std::cout);
    QByteArray byteArray = file.readAll();
    jsonDocument = QJsonDocument::fromJson(byteArray);
    jsonObject = jsonDocument.object();
    loadedMap = mapName;
    file.close();
}

void MapEditor::createNewMap(std::string mapName, int width, int height){
    mapName = parseMapName(mapName);
    std::cout << "Creating "<<mapName<<"\n";
    std::flush(std::cout);
    std::string fileNameC = QDir::currentPath().toStdString() + "/maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    std::string arrayString = "{\"width\":";
    arrayString += std::to_string(width);
    arrayString += ",\"height\":";
    arrayString += std::to_string(height);
    arrayString += ",\"objects\":[]}";
    file.write(QByteArray::fromStdString(arrayString));
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

bool MapEditor::placeObject(int x, int y, Objects object){
    if (jsonObject.find("objects") == jsonObject.end()){
        jsonObject.insert("objects","[]");
    }
    QString objectString = "{\"type\":\"";
    objectString.append(QString::fromStdString(std::to_string(object)));
    objectString.append("\",\"x\":");
    objectString.append(QString::fromStdString(std::to_string(x)));
    objectString.append(",\"y\":");
    objectString.append(QString::fromStdString(std::to_string(y)));
    objectString.append("}");
    QJsonDocument obj = QJsonDocument::fromJson(objectString.toUtf8());
    QJsonArray array = jsonObject["objects"].toArray();
    array.append(obj.object());
    jsonObject["objects"] = array;
    return true;
}

std::string MapEditor::parseMapName(std::string text){
    std::regex regex("\\.map$");
    return std::regex_replace(text,regex,std::string(""));
}

std::string MapEditor::getLoadedMap(){
    return loadedMap+".map";
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
    std::flush(std::cout);

    std::string mapName = parseMapName(loadedMap);
    jsonDocument = QJsonDocument(jsonObject);
    std::string fileNameC = QDir::currentPath().toStdString() + "/maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(jsonDocument.toJson());
    file.close();
}

MapEditor::~MapEditor()
{

}

