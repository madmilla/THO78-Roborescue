#include <boost/asio/io_service.hpp>
#include "TCPServer.h"

int main()
{
	boost::asio::io_service service;
	TCPServer server{ service, 10033 };
	service.run();
}