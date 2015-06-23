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
#include "SerialPort.h"
#include "CImg.h"
#include <chrono>
#include "ARInterface.h"

boost::asio::io_service service;
TCPServer server{ service, 10033 };
GlobalLocalisation* globalLocalizer;
PX4FlowWrapper flowWrapper;
SerialPort serialPort{"/dev/ttyACM0"};
MAVLinkExchanger exchanger(serialPort);
ARInterface* PX4FlowDetector;

const int TARGET_MARKER_ID = 954;

void handlePX4Flow()
{
	while(1)
	{
		std::this_thread::sleep_for (std::chrono::seconds(3));
		//std::cout << "Request message\n";
		flowWrapper.setHeading(90);
		mavlink_message_t* msg = flowWrapper.requestImage();
		if (msg != nullptr){
			PrioritisedMAVLinkMessage message(*msg);
			exchanger.enqueueMessage(message);
		}
		delete msg;
		cimg_library::CImg<unsigned char>* img = nullptr;
		while (img == nullptr){
			img = flowWrapper.getImage();
		}
		img->save("image.BMP");		
		std::this_thread::sleep_for (std::chrono::seconds(1));

		if(img->size())
		{
			int detectedId = PX4FlowDetector->getIdFromImage("image.BMP");
			if(detectedId == TARGET_MARKER_ID)
			{				
				std::string message = 'V' + std::to_string(detectedId);				
				std::cout << message <<std::endl;
				server.broadcast(message);
			}
		}
		
		delete img;
		
		
		//std::cout << "end of loop, back to start.\n";
		std::cout 
			<< "FlowX: " << flowWrapper.getX() 
			<< " \nFlowY: " << flowWrapper.getY() <<std::endl;
	}
}

void handleArguments( int argc, char *argv[])
{
	std::cout << "Number of args: " << argc << std::endl;
	bool gui = false;
	int tresh1 = 7, tresh2 = 7;
	if(argc >= 2)
	{
		if(strcmp(argv[1],"gui")==0)
		{
			gui = true;			
			cv::namedWindow("PX4",1);
			cv::namedWindow("PX4T",1);
		}
	}
	if(argc == 4)
	{
		tresh1 = atoi(argv[2]);
		tresh2 = atoi(argv[3]);
	}
	std::cout << "treshparams: " << tresh1 << ", " <<tresh2 <<std::endl;
	globalLocalizer = new GlobalLocalisation(gui, tresh1, tresh2);
	PX4FlowDetector = new ARInterface(gui, tresh1, tresh2);
}

int main(int argc, char *argv[])
{
	handleArguments(argc, argv);
	
	if(globalLocalizer->isErrorOnInit())
	{
		std::cout << globalLocalizer->getErrorString() << std::endl;
		return 0;
	}	
	std::thread recogniserThread{ &GlobalLocalisation::run, globalLocalizer};
	std::thread mavLinkThread{ &MAVLinkExchanger::loop, &exchanger};	
	std::thread px4FlowThread{ handlePX4Flow};	
	std::thread mainThread{[&server, &exchanger]()
	{
		std::cout << "Starting mainfred\n";
		while(1)
		{
			if (exchanger.receiveQueueSize())
			{
				PrioritisedMAVLinkMessage message = exchanger.dequeueMessage();
				flowWrapper.ReceiveMAVLinkMessage(&message);
			}
			
			if(globalLocalizer->isErrorInRun())
			{
				std::cout << globalLocalizer->getErrorString() << std::endl;
				return 0;
			}
			if(globalLocalizer->isNewCoordinate())
			{
				auto coordinate = globalLocalizer->getCoordinate();
				flowWrapper.calibrate(coordinate.getX(),108-coordinate.getY());
			}
			
			std::string message = 
				'X' + std::to_string(flowWrapper.getX()) +
				'Y' + std::to_string(flowWrapper.getY());
			std::cout << message <<std::endl;
			server.broadcast(message);
			
			/*char c;
			std::cin >> c;
			if(c == 'v')
			{
				int detectedId = 954;
				std::string message = 'V' + std::to_string(detectedId);				
				std::cout << message <<std::endl;
				server.broadcast(message);
			}
			else if (c=='l')
			{
			
				Coordinate<int> currentCoordinate = Coordinate<int>{32,75};
				std::string message = 'X' + std::to_string(currentCoordinate.getX()) + 'Y' + std::to_string(108-currentCoordinate.getY());		
				std::cout << message <<std::endl;
				server.broadcast(message);
			}*/
		}
	}};
	mavLinkThread.detach();
	recogniserThread.detach();
	px4FlowThread.detach();
	mainThread.detach();
	service.run();	
	
	return 0;
}
