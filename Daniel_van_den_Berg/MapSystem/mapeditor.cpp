#include "mapeditor.h"
#include <QDir>
#include <iostream>
#include <regex>
#include <QByteArray>

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
    file.write(QString::fromStdString(arrayString).toUtf8());
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

bool MapEditor::placeObject(int x, int y, Objects object){/*
    if (jsonObject.find("objects") == jsonObject.end()){
        jsonObject.insert("objects","[]");
    }*/
    if (x < 0 || y < 0 || x > jsonObject.value("width").toInt(20) || y > jsonObject.value("height").toInt(20)){
        return false;
    }
    QJsonObject obj = jsonObject["objects"].toObject();
    QJsonObject xObj;
    QString xString = QString::fromStdString(std::to_string(x));
    QString yString = QString::fromStdString(std::to_string(y));
    if (obj.contains(xString)){
        xObj = obj[xString].toObject();
    }else{
        xObj = QJsonObject();
        obj[xString]=xObj;
    }
    QJsonObject yObj;
    if (xObj.contains(yString)){
        yObj = xObj[yString].toObject();
    }else{
        yObj = QJsonObject();
        xObj[yString]=yObj;
    }

    QJsonArray objectList;
    if (yObj.contains("objects")){
        objectList = yObj["objects"].toArray();
    }else{
        objectList = QJsonArray();
        yObj.insert("objects",objectList);
    }

    objectList.append(object);

    yObj["objects"] = objectList;
    xObj[yString] = yObj;
    obj[xString]=xObj;
    jsonObject["objects"] = obj;
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

QJsonArray MapEditor::getObjectsAt(int x, int y){
    QJsonObject obj = jsonObject["objects"].toObject();
    QString xString = QString::fromStdString(std::to_string(x));
    QString yString = QString::fromStdString(std::to_string(y));

    if (!obj.contains(xString)){
        return QJsonArray();
    }
    QJsonObject xObj = obj[xString].toObject();

    if (!xObj.contains(yString)){
        return QJsonArray();
    }
    QJsonObject yObj = xObj[yString].toObject();

    return yObj["objects"].toArray();
}

bool MapEditor::removeObject(int x, int y,Objects object){
    if (!getObjectsAt(x,y).contains(object)){
        return false;
    }

    QJsonObject obj = jsonObject["objects"].toObject();
    QString xString = QString::fromStdString(std::to_string(x));
    QString yString = QString::fromStdString(std::to_string(y));

    QJsonObject xObj = obj[xString].toObject();
    QJsonObject yObj = xObj[yString].toObject();

    QJsonArray objArray = yObj["objects"].toArray();
    int i = 0;
    for (; i < objArray.size(); i++){
        if (objArray[i] == object){
            break;
        }
    }
    objArray.removeAt(i);
    yObj["objects"] = objArray;
    xObj[yString] = yObj;
    obj[xString]=xObj;
    jsonObject["objects"] = obj;
    return true;
}

bool MapEditor::saveMap(){
    std::flush(std::cout);

    std::string mapName = parseMapName(loadedMap);
    jsonDocument = QJsonDocument(jsonObject);
    std::string fileNameC = QDir::currentPath().toStdString() + "/maps/" + mapName + ".map";
    QString fileName = QString::fromUtf8(fileNameC.c_str());
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    bool succeeded = (jsonDocument.toJson().length() == file.write(jsonDocument.toJson()));
    file.close();
    return succeeded;
}

MapEditor::~MapEditor()
{

}

