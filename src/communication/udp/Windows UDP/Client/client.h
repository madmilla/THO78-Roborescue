#include <stdio.h>
#include <winsock2.h>
#include <thread>
#include <string>
#include <iostream>
#include "../../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"

#pragma comment(lib,"ws2_32.lib")

#define SERVER "127.0.0.1"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 8888 //The port on which to listen for incoming data


class client{
   public:
      client();
		
      void init();
      void createSocket();
      void sendMessage();
	

   private:
      struct sockaddr_in si_other;
      int s,i, slen = sizeof(si_other);
      char buf[BUFLEN];
      char message[BUFLEN];
      WSADATA wsa;
      std::thread clientthread;

	  mavlink_message_t msg;
	  mavlink_ralcp_t packet;
};