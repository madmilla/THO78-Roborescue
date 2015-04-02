#ifndef _ATV_H
#define _ATV_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
class SerialPort;

class ATV
{
public:
	ATV(SerialPort & serialPort);
	~ATV();
	void moveForward();
private:
	SerialPort & serialPort;
};
#endif