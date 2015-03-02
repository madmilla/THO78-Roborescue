#ifndef MAPPROCESSOR_H
#define MAPPROCESSOR_H

#include <QString>
#include <QGraphicsScene>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <QPainter>

#include "mapRectangle.h"
#include "drawArea.h"

class mapProcessor
{
public:
    mapProcessor();
    ~mapProcessor();
    bool processMap(QString mapFile, drawArea *map, drawArea *legend);
private:
    static const uint CHARS_PER_STRING = 20, TOTAL_STRINGS = 20;

    QPainterPath quadText, targetText, rosbeeText, uatvText, obstacleText;

    QGraphicsScene *mapScene, *legendScene;
};

#endif // MAPPROCESSOR_H
