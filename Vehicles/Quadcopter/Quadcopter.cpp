#include "Quadcopter.h"
#include "TempMAVSender.h"

#define MEANVALUELEFTRIGHT 1487
#define SYSTEMID 255
#define QUADCOPTERID 1
#define MOTOR 250
#define SYSTEMCOMPONENTID 200

Quadcopter::Quadcopter(TempMAVSender& tempMAVSender) :
tempMAVSender{ tempMAVSender }
{
	
}

void Quadcopter::liftOff()
{

}

void Quadcopter::arm()
{
	auto msg = mavlink_message_t();
	mavlink_msg_command_long_pack(SYSTEMID,0,&msg,MOTOR,QUADCOPTERID,400,0,1,0,0,0,0,0,0);
	tempMAVSender.sendMessage(msg);
}

void Quadcopter::moveLeft(signed int value)
{
	moveRight(-value);
}

void Quadcopter::moveRight(signed int value)
{
	auto msg = mavlink_message_t();
	mavlink_msg_rc_channels_override_pack(SYSTEMID,SYSTEMCOMPONENTID,& msg,QUADCOPTERID,MOTOR,MEANVALUELEFTRIGHT+value,UINT16_MAX, UINT16_MAX, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	tempMAVSender.sendMessage(msg);
}

void Quadcopter::moveForward()
{

}

void Quadcopter::moveBackward()
{

}

void Quadcopter::stop()
{

}

void Quadcopter::land()
{

}

void Quadcopter::changeFlightSpeed(int)
{

}

void Quadcopter::changeHeading(int)
{

}