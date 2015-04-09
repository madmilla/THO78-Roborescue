#include "UDPServer.hpp"

uint8_t UDPServer::currentid = 0;
UDPServer::UDPServer(){
	init();
	sockbind();
	connectionThread = std::thread(&UDPServer::start, this);
}

void UDPServer::init(){
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("UDPServer Initialised.\n");
	slen = sizeof(si_other);

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	printf("Socket created.\n");

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
}

void UDPServer::sockbind(){
	if (bind(sock, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	std::cout << "Bind done!" << std::endl;
}


void UDPServer::start(){
	stopped = false;
	while (!stopped)
	{
		printf("Waiting for data...");
		fflush(stdout);

		memset(buf, '\0', bufferlen);

		receive(buf);
		addConnection(si_other);
		printf("Data: %s\n", buf);
		
		int number = atoi(buf);
		number = number * number;
		std::string data = std::to_string(number);
		std::cout << data << std::endl;

		send(si_other, data);
	}
	std::this_thread::yield();
}

void UDPServer::broadcast(std::string message){
	for each (auto socket in _connections)
	{
		send(socket.con.sockaddr, message);
	}
}


void UDPServer::send(Connection connection, std::string message){
	if (sendto(sock, message.c_str(), strlen(message.c_str()), 0, (struct sockaddr*) &connection.sockaddr, slen) == SOCKET_ERROR)
	{
		printf("sendto() failed with error code : %d", WSAGetLastError());
	}
}

void UDPServer::receive(char * buffer){
	if ((recv_len = recvfrom(sock, buffer, bufferlen, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
	{
		printf("recvfrom() failed with error code : %d", WSAGetLastError());
	}

}

void UDPServer::addConnection(sockaddr_in con){
	bool found = false;
	for (auto socket : _connections){
		if (inet_ntoa(socket.con.sockaddr.sin_addr) == inet_ntoa(con.sin_addr) && (socket.con.sockaddr.sin_port) == con.sin_port){
			found = true;
			break;
		}
	}
	if (!found){
		//Request device id via mavlink here
		//_connections.push_back(con);
		printf("New connection from %s:%d\r\n", inet_ntoa(con.sin_addr), ntohs(con.sin_port));
	}
}

void UDPServer::stop(){
	stopped = true;
}

UDPServer::~UDPServer(){
	stop();
}