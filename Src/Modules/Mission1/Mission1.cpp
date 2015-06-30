#include "Mission1.h"
#include "MAVLinkExchanger.h"
#include "TCPConnection.h"
#include "Quadcopter.h"
#include "Rosbee.h"
#include "XYLocalisationModule.h"

Mission1::Mission1(boost::asio::io_service& service):
service{ service }
{	
}

void Mission1::initialize()
{
	lidarConnection = std::make_shared<TCPConnection>(TCPConnection{ service });
	lidarConnection->connect(LIDAR_PORT);
	lidarExchanger = std::make_shared<MAVLinkExchanger>(MAVLinkExchanger{ lidarConnection });
}

void Mission1::run()
{
	if(isInitialized)
	{
		
	}
}