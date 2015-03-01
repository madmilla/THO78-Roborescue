#include <QFileDialog>
#include "fileloader.h"
#include <map>

FileLoader::FileLoader()
{
}


FileLoader::~FileLoader()
{
}

Map* FileLoader::openMap(QString fileName, Map* map)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        processLine(line, map);
        line = in.readLine();
    }

    return map;
}

void FileLoader::processLine(QString line, Map* map)
{
    std::map<QString, ObjectType> stringToTypeMap =
    {
        {QString("empty"), ObjectType::Empty},
        {QString("wall"), ObjectType::Wall},
        {QString("tree"), ObjectType::Tree},
        {QString("quad"), ObjectType::Quad},
        {QString("atv"), ObjectType::ATV}
    };
    QPoint position;
    ObjectType type;
    QStringList keyValuePairs = line.split(", ");
    for (auto kvp : keyValuePairs)
    {
        QStringList kvList = kvp.split(":");
        QString key = kvList[0], value = kvList[1];
        if (key == "x")
        {
            position.setX(value.toInt());
        }
        else if (key == "y")
        {
            position.setY(value.toInt());
        }
        else if (key == "type")
        {
            type = stringToTypeMap[value];
        }
    }
    map->addObject(Object(type, position));
}
