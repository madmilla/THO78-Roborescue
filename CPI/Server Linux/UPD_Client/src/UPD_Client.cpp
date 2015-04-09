//============================================================================
// Name        : NP_Week5.cpp
// Author      : Hamza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "PracticalSocket.h"
#include <iostream>
#include <inttypes.h>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
	UDPSocket sock;
	SocketAddress to_adr("127.0.0.1", 2222, SocketAddress::UDP_SOCKET);
	clock_t start = clock()+ (CLOCKS_PER_SEC*2);

	int count = 0;
	while(true){
		try{
			while(start > clock()){}

			sock.sendTo(&count, sizeof(count), to_adr );

			cout << "recieved: " << count << endl;
			cout << "from: " << to_adr.getAddress() << ":" << to_adr.getPort() << endl;

			count++;
			sock.recvFrom(&count, sizeof(count), to_adr);

			start = clock()+ (CLOCKS_PER_SEC*2);

		}catch(SocketTimedOutException e){continue;}
	}
}
