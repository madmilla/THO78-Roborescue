#ifndef MAPPROCESSOR_H
#define MAPPROCESSOR_H

#include <QString>
#include <QFrame>
#include <QFile>
#include <QDebug>

class mapProcessor
{
public:
    mapProcessor();
    ~mapProcessor();
    bool processMap(QString mapFile, QFrame* frame);
};

#endif // MAPPROCESSOR_H
