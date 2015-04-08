#ifndef _ATV_H
#define _ATV_H

#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
#include "MAVLinkExchanger.h"
#include "ExtendedMAVLinkMessage.h"

class ATV
{
public:
	ATV(MAVLinkExchanger & mavlinkSender);
	~ATV();
	void moveForward(int);
	void moveBackward(int);
	void moveBackward(int);
	void turnLeft(int);
	void turnRight(int);
	void emergencyStop();
	void returnControlToRc();
	void loop();
private:
	MAVLinkExchanger & mavlinkSender;
	ExtendedMAVLinkMessage message;

	void handleIncomingMessage(ExtendedMAVLinkMessage incomingMessage);
};

#endif

/*DEBUG
use this method to get the servo output, this used for steering
auto msg = mavlink_message_t();
int msgid;
while (1)
{
mavlinkSender.receiveMessage(msg);
msgid = (int)msg.msgid;
if (msgid == MAVLINK_MSG_ID_SERVO_OUTPUT_RAW)
{
std::cout << mavlink_msg_servo_output_raw_get_servo1_raw(&msg) << '\n';
}
}
*/
