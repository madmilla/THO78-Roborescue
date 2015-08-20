#ifndef _MAP_IMPLEMENTATION_H
#define _MAP_IMPLEMENTATION_H

class mapImplementation{
public:
	virtual bool isAccessible(int x, int y) const = 0;
	virtual int getScaledWidth() const = 0;
	virtual int getScaledHeight() const = 0;
};

#endif //_MAP_IMPLEMENTATION_H
