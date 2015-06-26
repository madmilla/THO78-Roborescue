#include <boost/asio.hpp>
#include "XYLocalisationModule.h"
#include "VictimLocalisationModule.h"
#include <thread>
#include <iostream>

using namespace boost::asio;
using namespace ip;

io_service service;

int main()
{
	XYLocalisationModule xyLocalisationModule
		{ service, "192.168.137.39", "10033" };
	VictimLocalisationModule victimLocalisationModule
		{ service, "192.168.137.39", "10033" };
	std::thread inputThread{ [&xyLocalisationModule, &victimLocalisationModule]()
	{
		std::string message;
		while (1)
		{
			//std::cin >> message;
			//if (!message.empty())
			//{
			//}
		}
	} };
	inputThread.detach();
	service.run();
}
