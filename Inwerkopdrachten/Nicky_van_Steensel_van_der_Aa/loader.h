#ifndef LOADER_H
#define LOADER_H
#include"qstring.h"
#include "map.h"

class Loader
{
public:
    Loader();
    ~Loader();
    map getMap(QString maploc);
    Tile process_char(QChar lijn);
};

#endif // LOADER_H
