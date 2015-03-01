#ifndef FILELOADER_H
#define FILELOADER_H

#include <QWidget>

#include "map.h"

class FileLoader
{
public:
    FileLoader();
    ~FileLoader();
    Map* openMap(QWidget* parent);
private:
    void processLine(QString line, Map* map);
};

#endif
