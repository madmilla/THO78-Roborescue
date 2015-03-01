#include "map.h"


Map::Map()
{
}


Map::~Map()
{
}

QColor Map::getColor(int x, int y)
{
    for (auto &object : objects)
    {
        if (object.location == QPoint(x, y))
        {
            qDebug() << "Found object at x:" << x << " and y:" << y;
            return object.color;
        }
    }
    return QColor(255, 255, 255);
}

void Map::setColor(int x, int y, QColor color)
{
    for (auto &object : objects)
    {
        if (object.location == QPoint(x, y))
        {
            qDebug() << "Found object at x:" << x << " and y:" << y;
            object.color = color;
            return;
        }
    }
    qDebug() << "Adding new object at x:" << x << " and y:" << y;
    addObject(Object(color, QPoint(x,y)));
}

void Map::addObject(Object object)
{
    objects.push_back(object);
    qDebug() << "Objects: " << objects.size();
}

std::vector<Object>& Map::getObjects()
{
    return objects;
}
