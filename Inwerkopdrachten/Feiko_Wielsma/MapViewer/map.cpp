#include "map.h"


Map::Map()
{
    qDebug() << "Creating map";
}


Map::~Map()
{
    qDebug() << "Deleting map";
}

ObjectType Map::getType(int x, int y)
{
    for (auto &object : objects)
    {
        if (object.position == QPoint(x, y))
        {
            //qDebug() << "Found object at x:" << x << " and y:" << y;
            return object.type;
        }
    }
    return ObjectType::Empty;
}

void Map::setType(int x, int y, ObjectType type)
{
    for (auto &object : objects)
    {
        if (object.position == QPoint(x, y))
        {
            //qDebug() << "Found object at x:" << x << " and y:" << y;
            object.type = type;
            return;
        }
    }
    //qDebug() << "Adding new object at x:" << x << " and y:" << y;
    addObject(Object(type, QPoint(x,y)));
}

void Map::addObject(Object object)
{
    objects.push_back(object);
    //qDebug() << "Objects: " << objects.size();
}

std::vector<Object>& Map::getObjects()
{
    return objects;
}
