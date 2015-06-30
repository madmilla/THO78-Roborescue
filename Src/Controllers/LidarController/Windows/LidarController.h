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
	/**
	* Constructor of the controller
	* /param lidar the lidar to use in the controller
	* /param exchanger the exchanger to be used in the controller
	*/
	LidarController(Lidar& lidar, MAVLinkExchanger& exchanger);

	/**
	* Send a message to the lidar to start scanning lines and get a vector of lines back
	* /param startX the starting x coordinate of the lidar
	* /param stratY the starting y coordinate if the lidar
	* /param orientation starting orientation of the lidar(e.g. 180 degrees)
	*/
	void scanLines(int startX, int startY, int orientation);

	/**
	* Keeps recieving lines in the lines vector. 
	* This uses an Infinite loop to check for lines from lidar
	*/
	void loop();

	/**
	* return wether there are lines in the vector lines. Returns true if there are any
	* /return bool true when there are lines that can be retrieved. False when there aren't any
	*/
	bool hasLines();

	/**
	* returns a vector of lines. It is the user's responsibility to check if the vector is empty or not
	* /return a vector of lines that where stored in the controller
	*/
	std::vector<Line> getLines();
private:
	Lidar& lidar;
	MAVLinkExchanger& exchanger;

	std::vector<Line> lines;
	bool hasLines = false;
};
#endif