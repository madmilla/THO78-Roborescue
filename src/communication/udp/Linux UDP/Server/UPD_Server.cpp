
/**
 * Test mavconn library
 *
 * This test created for issue #72.
 * It is hand test, no build rules.
 *
 * Compile command:
 *     g++ -I /opt/ros/indigo/include -std=c++11 test/test_hang.cpp -o /tmp/hang \
 *     -L/opt/ros/indigo/lib -lroscpp -lrosconsole -lboost_system -lmavconn \
 *     -DMAVLINK_DIALECT=ardupilotmega
 */
#include "PracticalSocket.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


int main(int argc, char **argv)
{
	UDPSocket sock;
	SocketAddress localadr("127.0.0.1", 2222, SocketAddress::UDP_SOCKET);
	sock.bind(localadr);
	SocketAddress remoteadr;
	sock.setTimeOut(2);

	int count = 0;
	while(true){
		try{
			cout << "waiting" << endl;

			sock.recvFrom(&count, sizeof(int), remoteadr);

			cout << "recieved: " << count << endl;
			cout << "from: " << remoteadr.getAddress() << ":" << remoteadr.getPort() << endl;

			count++;
			sock.sendTo(&count, sizeof(int), remoteadr );

		}catch(SocketTimedOutException e){continue;}
	}
}
