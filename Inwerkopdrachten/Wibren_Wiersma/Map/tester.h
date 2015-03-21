#ifndef TESTER_H
#define TESTER_H

#include "test.h"
#include <vector>

class Tester
{
public:
    Tester();
    ~Tester();

    int run();
private:
    std::vector<Test*> tests;
};

#endif // TESTER_H
