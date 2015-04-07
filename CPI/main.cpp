#include <windows.h>
#include "SerialUDPSocket.h"
int main(int argc, char * argv[]){
	std::string  addr = argv[1];
	SerialUDPSocket sock(atoi(argv[0]), addr);
	while (1){
		sock.writeData("test", sizeof("test"));
		Sleep(3000);
	}

}