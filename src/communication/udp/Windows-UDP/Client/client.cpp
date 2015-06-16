#include "client.h"


Client::Client(){
   init();
   createSocket();
  // clientthread = std::thread(&client::sendMessage, this);
}

void Client::init(){
   printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0){
      printf("Failed. Error Code : %d", WSAGetLastError());
      exit(EXIT_FAILURE);
	}

	packet.Payload = 2;
	packet.Destination = COMMAND_DESTINATION::ROSBEE;
	packet.Function = ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE;
	mavlink_msg_ralcp_encode(1, 1, &msg, &packet);
   printf("Initialised.\n");
}

void Client::createSocket(){
   //create socket
   if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR){
      printf("socket() failed with error code : %d", WSAGetLastError());
      exit(EXIT_FAILURE);
	}

	//setup address structure
   memset((char *)&si_other, 0, sizeof(si_other));
   si_other.sin_family = AF_INET;
   si_other.sin_port = htons(PORT);
   si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
}

void Client::sendMessage(){
  // while (1){
 //    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
      if (sendto(s, (char*)&msg, sizeof(mavlink_message_t), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR){
         printf("sendto() failed with error code : %d", WSAGetLastError());
		}
     
 if (recvfrom(s, (char*)&msg, sizeof(mavlink_message_t), 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR){
        printf("recvfrom() failed with error code : %d", WSAGetLastError());
    }
		
   }



Client::~Client(){
   closesocket(s);
   WSACleanup();

}



