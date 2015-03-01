#include <QFileDialog>
#include "fileloader.h"

FileLoader::FileLoader()
{
}


FileLoader::~FileLoader()
{
}

Map* FileLoader::openMap(QWidget* parent)
{
    Map* map = new Map();

    auto fileName = QFileDialog::getOpenFileName(parent,
        "Open Map", "/home/", "Map Files (*.map)");

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
    QPoint point;
    QColor color;
    QStringList keyValuePairs = line.split(", ");
    for (auto kvp : keyValuePairs)
    {
        QStringList kvList = kvp.split(":");
        QString key = kvList[0], value = kvList[1];
        if (key == "x")
        {
            qDebug() << "x=" << value;
            point.setX(value.toInt());
        }
        else if (key == "y")
        {
            qDebug() << "y=" << value;
            point.setY(value.toInt());
        }
        else if (key == "cr")
        {
            qDebug() << "red=" << value;
            color.setRed(value.toInt());
        }
        else if (key == "cg")
        {
            qDebug() << "green=" << value;
            color.setGreen(value.toInt());
        }
        else if (key == "cb")
        {
            qDebug() << "blue=" << value;
            color.setBlue(value.toInt());
        }
    }
    map->addObject(Object(color, point));
    qDebug() << line;
}
