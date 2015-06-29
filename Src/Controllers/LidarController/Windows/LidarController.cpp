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
			
		}
	}
}

std::vector<Line> LidarController::scanLines()
{
}