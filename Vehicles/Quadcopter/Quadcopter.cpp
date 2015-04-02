#include "Quadcopter.h"
#include "TempMAVSender.h"

#define MEANVALUELEFTRIGHT 1487
#define SYSTEMID 255
#define QUADCOPTERID 1
#define MOTOR 250
#define SYSTEMCOMPONENTID 200

Quadcopter::Quadcopter(TempMAVSender& tempMAVSender) :
tempMAVSender( tempMAVSender )
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
	mavlink_message_t msg = mavlink_message_t();
	//mavlink_msg_rc_channels_override_pack(255, 200, &msg, 1, 250, 0, 0, 0, 0, 0, 0, 0, 0);
	mavlink_msg_command_long_pack(255, 0, &msg, 1, 250, 400, 0, 1, 0, 0, 0, 0, 0, 0);
	tempMAVSender.sendMessage(msg);
	//Sleep(10000);
	mavlink_msg_rc_channels_override_pack(255, 200, &msg, 1, 250, UINT16_MAX, 1800, 1100, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	//tempMAVSender.sendMessage(msg);
	int x = 100;
	while (x)
	{
		tempMAVSender.sendMessage(msg);
		--x;
	}
	//Sleep(1000);
	mavlink_msg_rc_channels_override_pack(255, 200, &msg, 1, 250, UINT16_MAX, 1000, 1000, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
	while (x)
	{
		tempMAVSender.sendMessage(msg);
		--x;
	}
	//Sleep(5000);
	mavlink_msg_command_long_pack(255, 0, &msg, 1, 250, 400, 0, 0, 0, 0, 0, 0, 0, 0);
	//x = 100;
	//while (x)
	//{
	tempMAVSender.sendMessage(msg);
	//--x;
	//}
	mavlink_msg_rc_channels_override_pack(255, 200, &msg, 1, 250, 0, 0, 0, 0, 0, 0, 0, 0);
	x = 100;
	while (x)
	{
		tempMAVSender.sendMessage(msg);
		--x;
	}
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