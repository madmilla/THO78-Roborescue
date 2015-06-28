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

void LidarController::handleIncomingMessage(PrioritisedMAVLinkMessage incomingMessage)
{
	switch (incomingMessage.msgid)
	{
		//Switch op alle lidar messages die er maar zijn (1 dus..........)
	}
}