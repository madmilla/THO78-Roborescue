#include "UDPServer.hpp"
#include <iostream>
int main()
{
	UDPServer us;
	for (int i = 0; i < 10000; i++){
		std::cout << "im doing different shit" << std::endl;
	}
	us.stop();
	return 0;
}