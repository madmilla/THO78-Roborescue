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
    const std::string & name;

public:
    Test(const std::string & name);
    ~Test();
    void start();
};

#endif // TEST_H
