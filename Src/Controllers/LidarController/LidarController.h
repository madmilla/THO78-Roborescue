#ifndef _LIDAR_CONTROLLER_H
#define _LIDAR_CONTROLLER_H
#include 

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
	handleIncomingMessage(PrioritisedMAVLinkMessage incomingMessage);
};
#endif