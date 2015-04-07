#include "QRect"
#include "dimension.h"

#ifndef TESTATV
#define TESTATV
class testATV
{
public:
    testATV(Dimension atv, int x, int y);
    ~testATV();
    void goTo(int x, int y);
    Dimension atv;
    int x,y;
};





#endif // TESTATV

