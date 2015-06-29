#define linux

#include <iostream>
#include "GlobalLocalisation.h"
#include <thread>
#include <boost/asio/io_service.hpp>
#include "TCPServer.h"
#include "Coordinate.h"
#include <cstdlib>
#define cimg_display 0
#include "CImg.h"
#include "PX4FlowWrapper.h"
#include "MAVLinkExchanger.h"
#include "SerialConnection.h"
#include "CImg.h"
#include <chrono>
#include "ARInterface.h"

boost::asio::io_service service;
TCPServer server{ service, 10033 };
GlobalLocalisation* globalLocalizer;
PX4FlowWrapper flowWrapper;
SerialConnection serialPort{service};
MAVLinkExchanger exchanger(&serialPort);
ARInterface* PX4FlowDetector;

const int 	TARGET_MARKER_ID = 954;
const int 	DEFAULT_TRESHOLD = 7;
const char* PX4FLOW_SERIAL_PORT = "/dev/ttyACM0";
const int 	PX4FLOW_SERIAL_BAUDRATE = 115200;
const int 	Y_MAX_AR_TAG_VALUE = 108;

void handlePX4Flow()
{
	unsigned char attempts = 10;
	while(1)
	{
		attempts --;
		std::this_thread::sleep_for (std::chrono::milliseconds(500));
		flowWrapper.setHeading(90);
		while (attempts <= 0 || (!flowWrapper.isImageRequested() && !flowWrapper.isImageReady()))
		{
			if (attempts <= 0)
			{
				std::cout << "rip\n";
			}
			mavlink_message_t* msg = flowWrapper.requestImage();
				
			if (msg != nullptr)
			{
				std::cout << "Sending message\n";
				attempts = 10;
				mavlink_message_t message(*msg);
				exchanger.enqueueMessage(message);
			}
		}
		if (flowWrapper.isImageReady())
		{
			cv::Mat* img = flowWrapper.getImage();
			if(img != nullptr)
			{
				attempts = 10;
				int detectedId = PX4FlowDetector->getIdFromImage(img);
				if(detectedId == TARGET_MARKER_ID)
				{				
					std::string message = 'V' + std::to_string(detectedId);				
					std::cout << message <<std::endl;
					server.broadcast(message);
				}
			}
		}
	}
}

/**
* \brief Handles commandline arguments
*
* Reads the command line arguments to determine if it needs to run with
* gui or without. Also has options to manually set treshold levels.
*
* At the end of this function the global position localizer and the PX4 AR
* detector will be created (based on the parameters)
*/
void handleArguments( int argc, char *argv[])
{	
	serialPort.open(PX4FLOW_SERIAL_PORT, PX4FLOW_SERIAL_BAUDRATE);
	bool gui = false;
	int tresh1 = DEFAULT_TRESHOLD;
	int tresh2 = DEFAULT_TRESHOLD;
	//Test for 1 or more extra arguments (1st argument is the current program)
	if(argc >= 2)
	{
		if(strcmp(argv[1],"gui")==0) //Compare if the 1st argument is "gui"
		{
			//Create the windows and set gui on true
			gui = true;			
			cv::namedWindow("PX4",1);
			cv::namedWindow("PX4T",1);
		}
	}
	//If there are 3 extra arguments (gui, and 2 tresh params), put those in the
	//treshold variables.
	if(argc == 4)
	{
		tresh1 = atoi(argv[2]);
		tresh2 = atoi(argv[3]);
	}
	
	//Create the GlobalLocalisation and the PX4FlowDetector
	globalLocalizer = new GlobalLocalisation(gui, tresh1, tresh2);
	PX4FlowDetector = new ARInterface(gui, tresh1, tresh2);
}

int main(int argc, char *argv[])
{
	//Open the PX4Flow serialport
	serialPort.open(PX4FLOW_SERIAL_PORT, PX4FLOW_SERIAL_BAUDRATE);
	//Handles commandline arguments and creates the AR detection parts
	handleArguments(argc, argv);
	
	//If there was an error in the initialisation, terminate
	if(globalLocalizer->isErrorOnInit())
	{
		std::cout << globalLocalizer->getErrorString() << std::endl;
		return 0;
	}	
	//Create the threads
	std::thread recogniserThread{ &GlobalLocalisation::run, globalLocalizer};
	std::thread mavLinkThread{ &MAVLinkExchanger::loop, std::ref(exchanger)};	
	//std::thread px4FlowThread{ handlePX4Flow};	
	std::thread mainThread{[&server, &exchanger]()
	{
		std::cout << "Starting mainfred\n";
		while(1)
		{
			//If there are mavlink messages, let the flowWrapper handle them.
			if (exchanger.receiveQueueSize())
			{
				mavlink_message_t message = exchanger.dequeueMessage();
				flowWrapper.ReceiveMAVLinkMessage(&message);
			}
			
			//If there is an error, display it and terminate
			if(globalLocalizer->isErrorInRun())
			{
				std::cout << globalLocalizer->getErrorString() << std::endl;
				return 0;
			}
			//If the global localizer finds a new position, calibrate the flow
			//localizer with those coordinates
			if(globalLocalizer->isNewCoordinate())
			{
				auto coordinate = globalLocalizer->getCoordinate();
				flowWrapper.calibrate(coordinate.getX(),Y_MAX_AR_TAG_VALUE-coordinate.getY());
			}
			
			std::string message = 
				'X' + std::to_string(flowWrapper.getX()) +
				'Y' + std::to_string(flowWrapper.getY());
			//std::cout << message <<std::endl;
			server.broadcast(message);
		}
	}};
	mavLinkThread.detach();
	recogniserThread.detach();
	//px4FlowThread.detach();
	mainThread.detach();
	service.run();	
	
	return 0;
}
