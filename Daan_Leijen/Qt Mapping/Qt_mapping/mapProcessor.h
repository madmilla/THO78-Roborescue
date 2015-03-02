#ifndef MAPPROCESSOR_H
#define MAPPROCESSOR_H

#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QFile>
#include <QDebug>
#include <QVector>

class mapProcessor
{
public:
    mapProcessor();
    ~mapProcessor();
    bool processMap(QString mapFile, QGraphicsView* map, QGraphicsView* legend);
private:
    QPainterPath quadText, targetText, rosbeeText, uatvText, obstacleText;
    QGraphicsScene *mapScene, *legendScene;
    QVector < QVector <QGraphicsRectItem*> > rectangles;
};

#endif // MAPPROCESSOR_H
