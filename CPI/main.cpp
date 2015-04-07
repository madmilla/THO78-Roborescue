#include <string>
#include <cstdlib>
#include "include/SerialUDPSocket.h"
int main(int argc, char * argv[]){
	
	std::string  addr = argv[1];
	SerialUDPSocket sock(atoi(argv[0]), addr);
	std::string message = "test";
	while (1){

		sock.writeData(&message.c_str(), sizeof(message));
	}

}