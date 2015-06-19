#include <boost/asio.hpp>
#include "XYReceiver.h"
#include <thread>
#include <iostream>

using namespace boost::asio;
using namespace ip;

io_service service;

int main()
{
	XYReceiver client{ service, "192.168.137.34", "10033" };
	std::thread inputThread{ [&client]()
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
