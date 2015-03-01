#ifndef LOADER_H
#define LOADER_H
#include <string>
#include <QString>
#include "map.h"
class Loader
{
public:
    Loader();
    ~Loader();
    Map getMap(QString);

private:
    int lastX =0;
    int lastY =0;
    void processLine(QString);
    Map product;
};

#endif // LOADER_H
