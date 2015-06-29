#ifndef _LIDAR_CONTROLLER_H
#define _LIDAR_CONTROLLER_H
#include <vector>
#include "roborescueV1/mavlink.h"

class Lidar;
class MAVLinkExchanger;

class LidarController
{
public:
	LidarController(Lidar& lidar, MAVLinkExchanger& exchanger);
	void loop();
private:
	Lidar& lidar;
	MAVLinkExchanger& exchanger;
	void handleIncomingMessage(mavlink_message_t incomingMessage);
	
	void sendLines(std::vector<Line>& lines);
};
#endif