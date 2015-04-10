#include "UDPServer.hpp"
#include <iostream>
#include "../../receiver/receiver/client.h"
int main()
{
	UDPServer us;

	for (;;){
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
	us.stop();
	return 0;
}