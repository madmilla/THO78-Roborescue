#ifndef QuadCopter_H
#define QuadCopter_H

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

	// Setters
	void setSize(Dimension size) { this->size = size; };
	void setFov(Dimension fov) { this->fov = fov; };
	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; };
private:
    Dimension size;
    Dimension fov;
	int x;
    int y;
};

#endif // QuadCopter_H
