#include <thread>
#include<stdio.h>
#include<winsock2.h>
#include <vector>
#include <iostream>
#include <string>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

const int bufferlen = 512;
const int port = 8888;

class UDPServer
{
public:
	UDPServer();
	~UDPServer();
	void broadcast(std::string message);
	void send(sockaddr_in connection, std::string message);
	void receive(char * buffer);

	void stop();
private:
	void init();
	void sockbind();
	void start();
	void addConnection(sockaddr_in con);
	std::thread connectionThread;

	bool stopped = false;
	SOCKET sock;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	char buf[bufferlen];
	WSADATA wsa;

	std::vector<sockaddr_in> _connections;
};
