#ifndef MAPPROCESSOR_H
#define MAPPROCESSOR_H

#include <QString>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QFile>
#include <QDebug>

class mapProcessor
{
public:
    mapProcessor();
    ~mapProcessor();
    bool processMap(QString mapFile, QGraphicsView* map, QGraphicsView* legend);
};

#endif // MAPPROCESSOR_H
