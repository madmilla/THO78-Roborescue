#include "Mission1.h"
#include "MAVLinkExchanger.h"
#include "TCPConnection.h"
#include "Quadcopter.h"
#include "Rosbee.h"
#include "XYLocalisationModule.h"
#include "SerialConnection.h"

Mission1::Mission1(boost::asio::io_service& service):
service{ service }
{	
}

void Mission1::initialize()
{
	lidarConnection = std::make_shared<TCPConnection>(TCPConnection{ service });
	lidarConnection->connect(LIDAR_PORT);
	lidarExchanger = std::make_shared<MAVLinkExchanger>(MAVLinkExchanger{ lidarConnection });
	
	quadcopterConnection = std::make_shared<SerialConnection>(SerialConnection{serivce}); 
	quadcopterConnection->open(QUADCOPTER_COM_PORT,QUADCOPTER_BAUDRATE); //TODO Check ComPort
	quadcopterExchanger = std::make_shared<MAVLinkExchanger>(MAVLinkExchanger{quadcopterConnection});
	
	isInitialized = true;
}

void Mission1::run()
{
	if(isInitialized)
	{
		
	}
}