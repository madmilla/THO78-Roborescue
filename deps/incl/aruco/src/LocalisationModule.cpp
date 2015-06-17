#include <iostream>
#include "ARInterface.h"
#include <thread>
#include <boost/asio/io_service.hpp>
#include "headers/TCPServer.h"
#include "Coordinate.h"
#include <cstdlib>

boost::asio::io_service service;
TCPServer server{ service, 10033 };
ARInterface arRecogniser;

int main()
{
	if(arRecogniser.isErrorOnInit())
	{
		std::cout << arRecogniser.getErrorString() << std::endl;
		return 0;
	}
	std::thread recogniserThread{ &ARInterface::run, &arRecogniser};
	//std::thread serviceThread{ [&service]()
	//{
	//	service.run();
	//}};
	
	recogniserThread.detach();
	//serviceThread.detach();
	
	while(1)
	{
		if(arRecogniser.isErrorInRun())
		{
			std::cout << arRecogniser.getErrorString() << std::endl;
			return 0;
		}
		if(arRecogniser.isNewCoordinate())
		{
			auto coordinate = arRecogniser.getCoordinate();
			std::string message = 'X' + std::to_string(coordinate.getX()) + 'Y' + std::to_string(coordinate.getY());
			std::cout << message <<std::endl;
			//server.broadcast(message);
		}
	}
	return 0;
}
