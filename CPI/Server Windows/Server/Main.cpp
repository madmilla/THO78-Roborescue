#include "UDPServer.hpp"
#include <iostream>
#include "../../receiver/receiver/client.h"
int main()
{
	UDPServer us;
	client client;

	for (;;){
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		us.broadcast("broadcast");
	}
	us.stop();
	return 0;
}