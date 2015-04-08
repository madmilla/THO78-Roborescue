#include "client.h"
#include <iostream>

int main(void){
	client client;
	client.init();
	client.createSocket();
	
	while (1)
	{	
		std::cout << " hi=";
		client.sendMessage();
		
		
	}

	return 0;
}