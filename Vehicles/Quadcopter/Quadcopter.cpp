#include "Quadcopter.h"
#include "TempMAVSender.h"
#include <iostream>

Quadcopter::Quadcopter(TempMAVSender& tempMAVSender) :
tempMAVSender( tempMAVSender ),
armed{ false }
{
}

void Quadcopter::liftOff(int altitude)
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_NAV_TAKEOFF, 0, 0, 0, 0, 0, 0, 0, altitude);
	tempMAVSender.sendMessage(message);
}

void Quadcopter::arm()
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_COMPONENT_ARM_DISARM, 0, 1, 0, 0, 0, 0, 0, 0);
	tempMAVSender.sendMessage(message);
	while (1)
	{
		if (tempMAVSender.receiveMessage(message))
		{
			if (message.msgid == MAVLINK_MSG_ID_HEARTBEAT)
			{
				if ((mavlink_msg_heartbeat_get_base_mode(&message) >> 7) & 1)
				{
					armed = true;
				}
				break;
			}
		}
	}
}

void Quadcopter::disarm()
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_COMPONENT_ARM_DISARM, 0, 0, 0, 0, 0, 0, 0, 0);
	tempMAVSender.sendMessage(message);
	while (1)
	{
		if (tempMAVSender.receiveMessage(message))
		{
			if (message.msgid == MAVLINK_MSG_ID_HEARTBEAT)
			{
				if (!(mavlink_msg_heartbeat_get_base_mode(&message) >> 7) & 1)
				{
					armed = false;
				}
				break;
			}
		}
	}
}

void Quadcopter::moveLeft(signed int value)
{
}

void Quadcopter::moveRight(signed int value)
{
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
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_NAV_LAND, 0, 0, 0, 0, 0, 0, 0, 0);
	tempMAVSender.sendMessage(message);
}

void Quadcopter::changeFlightSpeed(int)
{

}

void Quadcopter::changeHeading(int)
{

}

void Quadcopter::changeAltitude(int altitude)
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_CONDITION_CHANGE_ALT, 0, 10, altitude, 0, 0, 0, 0, 0);
	tempMAVSender.sendMessage(message);
}

bool Quadcopter::isArmed()
{
	return armed;
}

void Quadcopter::shutdown()
{
	mavlink_msg_command_long_pack(255, 0, &message, 1, 1, MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN, 0, 1, 1, 0, 0, 0, 0, 0);
	tempMAVSender.sendMessage(message);
}

void Quadcopter::changeMode(int mode)
{
	mavlink_msg_set_mode_pack(255, 0, &message, 1, 1, mode);
	tempMAVSender.sendMessage(message);
}