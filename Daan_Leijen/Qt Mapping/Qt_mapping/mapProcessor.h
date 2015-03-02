#ifndef MAPPROCESSOR_H
#define MAPPROCESSOR_H

#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QDebug>
#include <QVector>

#include "mapRectangle.h"

class mapProcessor
{
public:
    mapProcessor();
    ~mapProcessor();
    bool processMap(QString mapFile, QGraphicsView *map);
    bool drawMap(QGraphicsView *map, QGraphicsView *legend);
private:
    static const uint CHARS_PER_STRING = 20, TOTAL_STRINGS = 20;

    QPainterPath quadText, targetText, rosbeeText, uatvText, obstacleText;

    QGraphicsScene *mapScene, *legendScene;

    QVector <mapRectangle> rectangles;

    int quadcopterCount = 0, targetCount = 0, obstacleCount = 0, uatvCount = 0, rosbeeCount = 0;
};

#endif // MAPPROCESSOR_H
