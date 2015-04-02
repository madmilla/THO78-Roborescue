#ifndef TEST_H
#define TEST_H

#include <string>

class Test
{
public:
    Test() {}

    virtual std::string name(){
        return "Default test name";
    }

    bool isSucceed(){
        return succeed;
    }

    virtual bool test(){
        return succeed;
    }

    virtual ~Test() {}

protected:
    bool succeed = true;
};

#endif // TEST_H
