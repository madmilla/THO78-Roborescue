#include "client.h"


client::client(){
   init();
   createSocket();
   clientthread = std::thread(&client::sendMessage, this);
}

void client::init(){
   printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0){
      printf("Failed. Error Code : %d", WSAGetLastError());
      exit(EXIT_FAILURE);
	}
   printf("Initialised.\n");
}

void client::createSocket(){
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

void client::sendMessage(){
   std::string letter = "1";
   while (1){
      std::this_thread::sleep_for(std::chrono::milliseconds(3000));
      if (sendto(s, letter.c_str(), strlen(letter.c_str()), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR){
         printf("sendto() failed with error code : %d", WSAGetLastError());
		}

      memset(buf, '\0', BUFLEN);
      if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR){
         printf("recvfrom() failed with error code : %d", WSAGetLastError());
      }
		
      puts(buf);
      i = atoi(buf) + 1;
      letter = std::to_string(i);
   }

   closesocket(s);
   WSACleanup();
}



