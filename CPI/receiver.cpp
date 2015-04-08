#include "include/SerialUDPSocket.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char * argv[]){
	std::string adr = argv[1];
	SerialUDPSocket socket(atoi(argv[0]), adr);
	unsigned char* buffer;
	while (1){
		socket.readData(buffer, 255);
		std::cout << "hoi"
		
	}

}