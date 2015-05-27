#include "TCPClient.h"
#include <thread>


int main()
{
	
	io_service ioService;
	TCPClient tcpClient{ ioService, "localhost", "10033" };
	
	tcpClient.connect();
	ioService.run();
	
	for (;;){}
	//std::thread t{ [&ioService](){ioService.run(); } };
	//t.detach();
	//tcpClient.write("GET / HTTP/1.1\r\nHost: theboostcpplibraries.com\r\n\r\n");
	//while (true){
	//	std::string input;
	//	std::cin >> input;
	//	tcpClient.write(input);
	//}
}
