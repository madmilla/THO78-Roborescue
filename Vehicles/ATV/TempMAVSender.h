#ifndef _TEMPMAVSENDER_H
#define _TEMPMAVSENDER_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
class SerialPort;

class TempMAVSender
{
public:
	explicit TempMAVSender(SerialPort& serialPort);
	void sendMessage(mavlink_message_t& message);
	bool receiveMessage(mavlink_message_t& message);
private:
	SerialPort& serialPort;
};
#endif