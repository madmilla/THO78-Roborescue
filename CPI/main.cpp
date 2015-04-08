#include <string>
#include <cstdlib>
#include "include/SerialUDPSocket.h"
  #include <windows.h>
  #include <winsock2.h>
  #include <ws2tcpip.h>

int main(int argc, char * argv[]){
	
	std::string  addr = argv[1];
	SerialUDPSocket sock(atoi(argv[0]), addr);
	unsigned char x = 'x';
	while (1){

		sock.writeData(&x, sizeof(x));
	}

}