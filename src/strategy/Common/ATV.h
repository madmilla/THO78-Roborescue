#include "QRect"
#include "dimension.h"

#ifndef ATV_H
#define ATV_H

class ATV{
public:
    ATV(Dimension atv, int x, int y);
    ~ATV();
    void goTo(int x, int y);
    Dimension atv;
    int x,y;
};





#endif //ATV_H

