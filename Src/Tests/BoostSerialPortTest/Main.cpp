#include <thread>
#include "SerialPort.h"
#include <iostream>

int main()
{
	asio::io_service service;
	SerialPort p{ service };
	p.open("COM3", 115600);
	std::thread serviceThread{ [&service]()
	{
		service.run();
	}};
	serviceThread.detach();
	unsigned char buffer[256];
	while (1)
	{
		auto readBytes = p.readData(buffer, 256);
		if (readBytes)
		{
			for (auto i = 0; i < readBytes; ++i)
			{
				std::cout << (char)buffer[i];
			}
		}
	}
}