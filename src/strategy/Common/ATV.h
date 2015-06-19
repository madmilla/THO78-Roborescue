#include "QRect"
#include "dimension.h"

#ifndef ATV_H
#define ATV_H

class ATV{
public:
    ATV(Dimension size, int x, int y);
    ~ATV();

    void goTo(int x, int y);

    // Getters
    Dimension getSize() { return size; }
    int getX() { return x; }
    int getY() { return y; }
private:
    Dimension size;
    int x;
    int y;
};

#endif //ATV_H
