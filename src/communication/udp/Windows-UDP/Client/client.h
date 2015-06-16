#include <stdio.h>
#include <winsock2.h>
#include <string>
//#include "../../mingw.thread.h"
#include <iostream>
#include "../../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"

#pragma comment(lib,"ws2_32.lib")

#define SERVER "145.89.98.137"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 8888 //The port on which to listen for incoming data


class Client{
   public:
      Client();
		
      void init();
      void createSocket();
      void sendMessage();
	
	~Client();
   private:
      struct sockaddr_in si_other;
      int s,i, slen = sizeof(si_other);
      WSADATA wsa;
      //std::thread clientthread;

	  mavlink_message_t msg;
	  mavlink_ralcp_t packet;
};