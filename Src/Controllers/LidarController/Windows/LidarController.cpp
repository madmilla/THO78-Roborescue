#include "LidarController.h"
#include "Lidar.h"
#include "MAVLinkExchanger.h"

LidarController::LidarController(Lidar& lidar, MAVLinkExchanger& exchanger):
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
			auto incomingMessage = exchanger.dequeueMessage();
			switch (incomingMessage.msgid)
			{
			case MAVLINK_MSG_ID_LIDAR_LINE:
				hasLines = true;
				Line line{ Point{ mavlink_msg_lidar_line_get_start_X(&incomingMessage), mavlink_msg_lidar_line_get_start_Y(&incomingMessage) },
					Point{ mavlink_msg_lidar_line_get_end_X(&incomingMessage), mavlink_msg_lidar_line_get_end_Y(&incomingMessage) } };
				lines.push_back(line);
				break;
		}
	}
}

void LidarController::scanLines(int startX, int startY, int orientation)
{
	mavlink_message_t message;
	mavlink_msg_command_long_pack(1, 1, &message, 1, 1, MAV_CMD_LIDAR_START_SCAN, 0, startX, startY, orientation, 0, 0, 0, 0);
	exchanger.enqueueMessage(message);
}

void LidarController::hasLines()
{
	return hasLines;
}

std::vector<Line> getLines()
{
	std::vector<Lines> tempLines = lines;
	lines.clear();
	hasLines = false;
	return lines;
}