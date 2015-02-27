#include "ObjectMap.h"


ObjectMap::ObjectMap()
{
    load();
}

ObjectMap::~ObjectMap()
{
}

void ObjectMap::save(){
    QFile file(fileName);
    QJsonDocument saveDoc(json);
    file.open(QIODevice::WriteOnly);
    file.write(saveDoc.toJson());
}


void ObjectMap::load(){
    QFile file(fileName);
    if(file.exists()){
        file.open(QIODevice::ReadOnly);
        QJsonDocument jsonFile(QJsonDocument::fromJson(file.readAll()));
        json = jsonFile.object();
    }
    else{
        clear();
    }
}


void ObjectMap::clear(){
    for(int x = 0; x < maxX; ++x){
        QJsonObject yObjects;
        for(int y = 0; y < maxY; ++y){
            QJsonObject cell;
            cell["height"] = 0;
            cell["object"] = false;
            yObjects[QString::number(y)] = cell;
        }
        json[QString::number(x)] = yObjects;
    }
    QJsonObject vehicle;
    vehicle["isPlaced"] = false;
    vehicle["x"] = 0;
    vehicle["y"] = 0;
    json["vehicle"] = vehicle;
}


void ObjectMap::setHeight(int x, int y, int height)
{
    if(x < maxX && y < maxY){
        QJsonObject object = json[QString::number(x)].toObject()[QString::number(y)].toObject();
        QJsonObject xObject = json[QString::number(x)].toObject();

        object["height"] = height;
        xObject[QString::number(y)] = object;

        json[QString::number(x)] = xObject;
    }
}

void ObjectMap::setObject(int x, int y, bool object)
{
    if(x < maxX && y < maxY){
        QJsonObject o = json[QString::number(x)].toObject()[QString::number(y)].toObject();
        QJsonObject xObject = json[QString::number(x)].toObject();

        o["object"] = object;
        xObject[QString::number(y)] = o;

        json[QString::number(x)] = xObject;
    }
}


void ObjectMap::setVehicle(int x, int y)
{
    if(x < maxX && y < maxY){
        if(!isObject(x, y)){
            QJsonObject vehicle = json["vehicle"].toObject();
            vehicle["x"] = x;
            vehicle["y"] = y;
            vehicle["isPlaced"] = true;

            json["vehicle"] = vehicle;
        }
    }
}

bool ObjectMap::vehiclePlaced()
{
    return json["vehicle"].toObject()["isPlaced"].toBool();
}


bool ObjectMap::vehicleAt(int x, int y)
{
    return (x == json["vehicle"].toObject()["x"].toInt()) && (y == json["vehicle"].toObject()["y"].toInt());
}


ObjectMap::VehicleLocation ObjectMap::vehicleLocation()
{
    return ObjectMap::VehicleLocation(json["vehicle"].toObject()["x"].toInt(), json["vehicle"].toObject()["y"].toInt());
}


bool ObjectMap::isObject(int x, int y)
{
    return json[QString::number(x)].toObject()[QString::number(y)].toObject()["object"].toBool();
}


int ObjectMap::getHeight(int x, int y)
{
    return json[QString::number(x)].toObject()[QString::number(y)].toObject()["height"].toInt();
}
