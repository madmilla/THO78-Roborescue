#include "UDPServer.hpp"
#include <iostream>
int main()
{
	UDPServer us;
	for (;;){
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		us.broadcast("heeeey");
	}
	us.stop();
	return 0;
}