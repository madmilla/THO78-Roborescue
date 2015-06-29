#ifndef _LIDAR_CONTROLLER_H
#define _LIDAR_CONTROLLER_H
#include <vector>
#include "roborescueV1/mavlink.h"
#include "Line.h"

class Lidar;
class MAVLinkExchanger;

class LidarController
{
public:
	LidarController(Lidar& lidar, MAVLinkExchanger& exchanger);
	std::vector<Line> scanLines(int startX, int startY, int orientation);
	void loop();
private:
	Lidar& lidar;
	MAVLinkExchanger& exchanger;
};
#endif