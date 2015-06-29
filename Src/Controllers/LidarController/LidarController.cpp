#include "LidarController.h"
#include "Lidar.h"
#include "MAVLinkExchanger.h"

LidarController(Lidar& lidar, MAVLinkExchanger& exchanger):
lidar{ lidar },
exchanger{ exchanger }
{
}

void LidarController::loop()
{
	while(1)
	{
		if (exchanger.receiveQueueSize())
		{
			handleIncomingMessage(exchanger.dequeueMessage());
		}
	}
}

void LidarController::handleIncomingMessage(mavlink_message_t incomingMessage)
{
	switch (incomingMessage.msgid)
	{
		case MAVLINK_MSG_ID_COMMAND_LONG:
			std::cout << "RECEIVED COMMAND: ";
			if(mavlink_msg_command_long_get_command(*incomingMessage) == MAV_CMD_LIDAR_START_SCAN)
			{
				std::cout << "LIDAR START COMMAND" << std::endl;
				auto startX = mavlink_msg_command_long_get_param1(*incomingMessage);
				auto startY = mavlink_msg_command_long_get_param2(*incomingMessage);
				auto orientation = mavlink_msg_command_long_get_param3(*incomingMessage);
				lidar.start(startX, startY, orientation);
			}
			break;
	}
}