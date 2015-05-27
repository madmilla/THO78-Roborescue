#include "TCPClient.h"
#include <thread>


int main()
{
	
	io_service ioService;
	TCPClient tcpClient{ ioService, "theboostcpplibraries.com", "80" };
	tcpClient.connect();
	std::thread t{ [&ioService](){ioService.run(); } };
	t.detach();
	while (true){
		std::string input;
		std::cin >> input;
		tcpClient.write(input);
	}
}
