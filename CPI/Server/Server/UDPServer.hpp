#include <thread>
#include<stdio.h>
#include<winsock2.h>
#include <iostream>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

const int bufferlen = 512;
const int port = 8888;

class UDPServer
{
public:
	UDPServer();
	~UDPServer();
	void stop();
private:
	void init();
	void sockbind();
	void start();
	std::thread connectionThread;

	bool stopped = false;
	SOCKET s;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	char buf[bufferlen];
	WSADATA wsa;
};
