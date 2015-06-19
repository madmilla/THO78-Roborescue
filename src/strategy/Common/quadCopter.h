#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "dimension.h"

class QuadCopter
{
public:
    QuadCopter(Dimension size, Dimension fov, int x, int y);
    ~QuadCopter();

    void goTo(int x, int y);
    bool inView(int x, int y);

    // Getters
    Dimension getSize() { return size; };
    Dimension getFov() { return fov; };
    int getX() { return x; };
    int getY() { return y; };
private:
    Dimension size;
    Dimension fov;
<<<<<<< HEAD
	int x;
=======
    int x;
>>>>>>> dac2d9b94fe678359bdf8fd564ce903533a05067
    int y;
};

#endif // QUADCOPTER_H
