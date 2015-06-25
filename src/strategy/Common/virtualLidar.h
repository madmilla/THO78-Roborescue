#ifndef VIRTUALLIDAR_H
#define VIRTUALLIDAR_H
#include "Lidar.h"

class virtualLidar
{
public:
	virtualLidar();
	virtualLidar(Lidar* actualLidar);
	~virtualLidar();
	Lidar* actualLidar;
	int getRange();
private:
	int range = 7;
};

#endif // VIRTUALLIDAR_H
