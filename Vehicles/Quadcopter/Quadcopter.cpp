#include "Quadcopter.h"
#include "TempMAVSender.h"

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
	mavlink_msg_command_long_pack(255,0,&msg,1,250,400,0,1,0,0,0,0,0,0);
	tempMAVSender.sendMessage(msg);
}

void Quadcopter::moveLeft(signed int value)
{
	moveRight(-value);
}

void Quadcopter::moveRight(signed int value)
{
	auto msg = mavlink_message_t();
	mavlink_msg_rc_channels_override_pack(255,200,& msg,1,250,1487+value,UINT16_MAX, UINT16_MAX, UINT16_MAX,UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
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