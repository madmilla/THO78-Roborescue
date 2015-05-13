
#include "../../../communication/udp/UDPServer.hpp"
#include "../../../communication/udp/Windows-UDP/Client/client.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

int testcount = 5;
int main(int argc, char** argv){
	if (argc > 1){
		testcount = atoi(argv[1]);
	}

	std::stringstream filename;
	UDPServer server;
	Client client;
	
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	filename << "UDPservertest - " << now->tm_year + 1900 << "-" << now->tm_mon + 1 << "-" << now->tm_mday << ".txt";

	std::ofstream output(filename.str());
	for (int i = 0; i < testcount; i++){
		client.sendMessage();
		Sleep(1000);
	}
	server.stop();
	/*if (server.messages.size() == testcount){
//		std::cout << "Test was succesfull" << testcount << "/" << testcount << std::endl;
		output << "Test was succesfull" << testcount << "/" << testcount << std::endl;

	}else{
		std::cout << "Test was unsuccesfull" << server.messages.size() << "/" << testcount << std::endl;
		output << "Test was unsuccesfull" << server.messages.size() << "/" << testcount << std::endl;

	}*/
	delete now;
	output.close();
	exit(0);



}