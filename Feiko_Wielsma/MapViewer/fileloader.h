#ifndef FILELOADER_H
#define FILELOADER_H

#include <QWidget>

#include "map.h"

class FileLoader
{
public:
    FileLoader();
    ~FileLoader();
    Map* openMap(QString fileName, Map* map);
private:
    void processLine(QString line, Map* map);
};

#endif
