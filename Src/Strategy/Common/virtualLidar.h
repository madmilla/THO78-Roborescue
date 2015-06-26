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
	void start(int x, int y,int angle);
	void sendLidarLocationStatus(int rosbeeX, int rosbeeY, int degrees);
private:
	int range = 7;
};

#endif // VIRTUALLIDAR_H
