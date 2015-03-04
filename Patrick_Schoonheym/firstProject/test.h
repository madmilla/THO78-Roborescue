#ifndef TEST_H
#define TEST_H

#include <vector>
#include <QString>
#include "map.h"
#include <QString>
#include <iostream>

class Test
{
private:
    Map* map;
    QString name;

public:
    Test(QString name);
    ~Test();
    bool start();
};

#endif // TEST_H
