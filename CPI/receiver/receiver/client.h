#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib")

#define SERVER "192.168.137.12"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 8888 //The port on which to listen for incoming data


class client{
	public:
		void init();
		void createSocket();
		void sendMessage();
	

	private:

		struct sockaddr_in si_other;
		int s, slen = sizeof(si_other);
		char buf[BUFLEN];
		char message[BUFLEN];
		WSADATA wsa;

};