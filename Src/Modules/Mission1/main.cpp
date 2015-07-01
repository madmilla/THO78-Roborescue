#include "MAVLinkExchanger.h"
#include "TCPConnection.h"
#include "Quadcopter.h"
#include "XYLocalisationModule.h"
#include "VictimLocalisationModule.h"
#include "QuadcopterController.h"
#include "SerialConnection.h"
#include <thread>

const std::string LOCAL_IP{"145.89.118.25"};
void runLocalisationModule();
void runLidar();

int main(int argc, char *argv[])
{
	runLocalisationModule();
    return 0;
}


const int LIDAR_PORT{ 8000 };
void runLidar()
{
	boost::asio::io_service service;
	TCPConnection c{ service };
	MAVLinkExchanger exchanger{ &c };
	c.connect(8000);
	
	std::thread exchangerThread{ &MAVLinkExchanger::loop, std::ref(exchanger) };
	std::thread lineReceiveThread{ [&exchanger]()
	{
		while(1)
		{
			while (exchanger.receiveQueueSize())
			{
				auto line = exchanger.dequeueMessage();
				std::cout << "Line: " 
				<< mavlink_msg_lidar_line_get_start_X(&line) << ','
				<< mavlink_msg_lidar_line_get_start_Y(&line) << " tot " 
				<< mavlink_msg_lidar_line_get_end_X(&line) << ','
				<< mavlink_msg_lidar_line_get_end_Y(&line) << std::endl;
			}
		}
	}};
	std::thread startInputThread { [&exchanger]()
	{
		mavlink_message_t message;
		mavlink_msg_command_long_pack(1, 1, &message, 1,1, MAV_CMD_LIDAR_START_SCAN, 0,1, 0,0,0,0,0,0);
		while(1)
		{
			char c;
			std::cin >> c;
			if(c != ' ')
			{
				std::cout << "Sent message" << std::endl;
				exchanger.enqueueMessage(message);
			}
		}
	}};
	exchangerThread.detach();
	lineReceiveThread.detach();
	startInputThread.detach();
	service.run();
}


const std::string QUADCOPTER_COM_PORT{ "COM4" };
const int QUADCOPTER_BAUDRATE{ 57600};
const std::string LOCALISATION_MODULE_PORT{ "8001" } ;
const std::string LOCALISATION_MODULE_IP{ "192.168.137.39" };
void runLocalisationModule()
{
	boost::asio::io_service service;
	SerialConnection quadcopterConnection{ service };
	quadcopterConnection.open(QUADCOPTER_COM_PORT, QUADCOPTER_BAUDRATE );
	XYLocalisationModule xyLocalisationModule{ service, LOCALISATION_MODULE_IP, LOCALISATION_MODULE_PORT };
	VictimLocalisationModule victimLocalisationModule{ service, LOCALISATION_MODULE_IP, LOCALISATION_MODULE_PORT };
	
	MAVLinkExchanger quadcopterExchanger{ &quadcopterConnection };;
	Quadcopter quadcopter{ quadcopterExchanger };
	QuadcopterController quadcopterController {quadcopter, xyLocalisationModule};
	
	std::cout << "Setting new target:\nInput X coord:\n";
	int x, y;
	std::cin >> x;
	std::cout << "Input Y coord:\n";
	std::cin >> y;
	
	std::cout << "Setting target (" << x << "," << y << "), height: 1.\n";
	quadcopterController.setTarget(Coordinate<double>{
		(double)x,(double)y}, 1);					
					
	std::cout << "Setting current height on 1.\n";
	quadcopterController.setHeight(1);
	
	
	std::thread xyThread{ [&xyLocalisationModule, &quadcopterController]()
	{
		std::string message;
		while (1)
		{
			std::this_thread::sleep_for (std::chrono::seconds(1));
			
			quadcopterController.setPosition();
			
			auto coord = quadcopterController.getPosition();
			std::cout << "Current position: " << coord.getX() << ", " << coord.getY() << "\n";
			
			quadcopterController.moveTowardsTarget();
			std::cout << std::endl << std::endl;
		}
	} };
	std::thread victimThread{ [&victimLocalisationModule]()
	{	
		bool victimFound = false;

		while(1)
		{
			if(victimLocalisationModule.isVictimFound() && !victimFound)
			{
				std::cout <<"Victim found!" << std::endl; 
				std::cout << "Victim id is " << 
					victimLocalisationModule.getVictimId() << std::endl;
				victimFound = true;
			}	
		}
	}};
	victimThread.detach();
	xyThread.detach();
	service.run();
}