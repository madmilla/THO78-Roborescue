#include <iostream>
#include "ARInterface.h"
#include <thread>
#include <boost/asio/io_service.hpp>
#include "headers/TCPServer.h"
#include "Coordinate.h"
#include <cstdlib>

boost::asio::io_service service;
TCPServer server{ service, 10033 };
ARInterface* arRecogniser;

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
		}
	}
	if(argc == 4)
	{
		tresh1 = atoi(argv[2]);
		tresh2 = atoi(argv[3]);
	}
	std::cout << "treshparams: " << tresh1 << ", " <<tresh2 <<std::endl;
	arRecogniser = new ARInterface(gui, tresh1, tresh2);
}

int main(int argc, char *argv[])
{
	handleArguments(argc, argv);
	
	if(arRecogniser->isErrorOnInit())
	{
		std::cout << arRecogniser->getErrorString() << std::endl;
		return 0;
	}
	std::thread recogniserThread{ &ARInterface::run, arRecogniser};
	std::thread mainThread{[&server, arRecogniser]()
	{
		while(1)
		{
			if(arRecogniser->isErrorInRun())
			{
				std::cout << arRecogniser->getErrorString() << std::endl;
				return 0;
			}
			if(arRecogniser->isNewCoordinate())
			{
				auto coordinate = arRecogniser->getCoordinate();
				std::string message = 'X' + std::to_string(coordinate.getX()) + 'Y' + std::to_string(coordinate.getY());
				std::cout << message <<std::endl;
				//std::cout << "Broadcasting" << std::endl;
				server.broadcast(message);
			}
		}
	}};
	
	recogniserThread.detach();
	mainThread.detach();
	service.run();	
	
	return 0;
}
