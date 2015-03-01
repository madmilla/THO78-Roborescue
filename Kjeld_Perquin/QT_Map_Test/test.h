#ifndef TEST_H
#define TEST_H
#include <string>

class Test
{
    void assert(bool testSucceeded, const std::string &testName);
    int errors;
public:
    int runTests();
};

#endif // TEST_H
