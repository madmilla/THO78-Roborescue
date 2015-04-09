#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	int originX;
	int originY;
	int radius;

	struct origins{
		int originX;
		int originY;
	};

public:
	Circle(int originX, int originY, int radius);
	~Circle();

	void setCircle(int x, int y, int r);
	origins getOrigin();
	int getRadius();
};

#endif // CIRCLE_H
