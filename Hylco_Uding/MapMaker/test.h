#ifndef TEST_H
#define TEST_H
#include "map.h"

class Test
{
public:
    Test();
    void run();
    void assert(std::string string, bool success);
    ~Test();
private:
    Map * map;
};

#endif // TEST_H
