#include "map.h"

#include <QFile>
#include <QByteArray>
#include <QMessageBox>

#include <iostream>
#include <iomanip>
#include <typeinfo>


/**
 * @brief Map::Map
 *
 * Create empty map.
 */
Map::Map()
{

}

/**
 * @brief Map::Map
 * @param fileName
 *
 * Create map from file.
 */
Map::Map(const QString &fileName)
{
    load(fileName);
}

/**
 * @brief Map::Map
 * @param width
 * @param height
 *
 * Create empty map with the given dimensions.
 */
Map::Map(int width, int height)
{
    this->width = width;
    this->height = height;
    int length = width * height;
    for(int i = 0; i < length; i++)
        data.push_back(0);
}

/**
 * @brief Map::~Map
 *
 * Destructor.
 */
Map::~Map()
{

}

/**
 * @brief Map::load
 * @param fileName
 *
 * Load map from file.
 */
void Map::load(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;

    QByteArray fileContent = file.readAll();
    QByteArray mapIndex = fileContent.mid(0, 2);
    QByteArray mapData = fileContent.mid(2, (mapIndex[0] * mapIndex[1]));
    if(mapData.size() != (mapIndex[0] * mapIndex[1])) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error opening file.", "File corrupted.");
        messageBox.setFixedSize(500,200);
    }
    else {
        this->width = mapIndex[0];
        this->height = mapIndex[1];
        int length = width * height;
        data.clear();
        for(int i = 0; i < length; i++)
            data.push_back(mapData[i]);

    }

    file.close();
}

/**
 * @brief Map::save
 * @param fileName
 *
 * Save map to file.
 */
void Map::save(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
        return;

    QByteArray mapIndex;
    QByteArray mapData;

    mapIndex.append(width);
    mapIndex.append(height);

    int length = width * height;
    for(int i = 0; i < length; i++)
            mapData.append(data[i]);

    file.write(mapIndex);
    file.write(mapData);

    file.close();
}
