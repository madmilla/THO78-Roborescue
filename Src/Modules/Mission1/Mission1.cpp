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
	lidarConnection = std::shared_ptr<TCPConnection>( new TCPConnection{ service } );
	std::cout << "Attempting to connect with the LIDAR on port: " + std::to_string( LIDAR_PORT ) << std::endl;
	lidarConnection->connect(LIDAR_PORT);
	std::cout << "Established connection with the LIDAR" << std::endl;
	lidarExchanger = std::shared_ptr<MAVLinkExchanger>(new MAVLinkExchanger{ lidarConnection.get() } );
	
	
	quadcopterConnection = std::shared_ptr<SerialConnection>( new SerialConnection{service} ); 
	std::cout << "Attempting to connect with the Quadcopter on COM port: " 
	<< QUADCOPTER_COM_PORT 
	<< " With a baudrate of: " 
	<< QUADCOPTER_BAUDRATE 
	<< std::to_string(QUADCOPTER_BAUDRATE) 
	<< std::endl; 
	quadcopterConnection->open(QUADCOPTER_COM_PORT, QUADCOPTER_BAUDRATE);
	std::cout << "Established connection with the Quadcopter" << std::endl;
	quadcopterExchanger = std::shared_ptr<MAVLinkExchanger>( new MAVLinkExchanger{ quadcopterConnection.get() } );
	
	
	isInitialized = true;
}

void Mission1::run()
{
	if(isInitialized)
	{
		
	}
}