#ifndef TEST_H
#define TEST_H

#include <iostream>


class Test
{
private:
    void assert(bool testSuccess, const std::string &testName);
    int errDetect;

public:
    Test();
    ~Test();
    int run();
};

#endif // TEST_H
