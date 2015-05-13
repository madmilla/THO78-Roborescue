#include "UDPServer.hpp"


UDPServer::UDPServer(){
	id = 0;
	init();
	sockbind();
   connectionThread = std::thread(&UDPServer::start, this);
	}

void UDPServer::init(){
   printf("\nInitialising Winsock...");
   if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0){
      printf("Failed. Error Code : %d", WSAGetLastError());
      exit(EXIT_FAILURE);
	}
   printf("UDPServer Initialised.\n");
   slen = sizeof(si_other);

   if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET){
      printf("Could not create socket : %d", WSAGetLastError());
   }
   printf("Socket created.\n");

   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons(port);
}

void UDPServer::sockbind(){
   if (bind(sock, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR){
      printf("Bind failed with error code : %d\n", WSAGetLastError());
      exit(EXIT_FAILURE);
   }
   std::cout << "Bind done!" << std::endl;
}

void UDPServer::start(){
   while(!stopped){
      receive(&msg);
      addConnection(si_other, &msg);
      handleMessage(si_other, &msg);
   }
   std::this_thread::yield();
}


void UDPServer::startTest(){
   while (!stopped){
      printf("Waiting for data...\r\n");
      fflush(stdout);

      receive(&msg);

      addConnection(si_other, &msg);


      mavlink_msg_ralcp_encode(1, 1, &msg, &packet);
		
	   std::cout << packet.Payload << std::endl;
      packet.Payload = packet.Payload + packet.Payload;
      mavlink_msg_ralcp_encode(1, 1, &msg, &packet);

      send(_connections[0], &msg);
	}
   std::this_thread::yield();
}

void UDPServer::broadcast(mavlink_message_t * message){
   for (auto socket : _connections){
      send(socket, message);
	}
}

void UDPServer::send(UDPSocket & socket, mavlink_message_t * message){
   if (sendto(sock, (char*)&msg, sizeof(mavlink_message_t), 0, (struct sockaddr*) &socket.con.sockaddr, slen) == SOCKET_ERROR){
      printf("sendto() failed with error code : %d\r\n", WSAGetLastError());
   }
}

void UDPServer::receive(mavlink_message_t * message){
   if ((recv_len = recvfrom(sock, (char*)&msg, sizeof(mavlink_message_t), 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR){
      printf("recvfrom() failed with error code : %d\r\n", WSAGetLastError());
      }
   
  
}

void UDPServer::handleMessage(sockaddr_in con, mavlink_message_t * msg){
   for (auto socket : _connections){
      if (inet_ntoa(socket.con.sockaddr.sin_addr) == inet_ntoa(con.sin_addr) && (socket.con.sockaddr.sin_port) == con.sin_port){
         socket.receive(*msg);
      }
   }
}

void UDPServer::addConnection(sockaddr_in con, mavlink_message_t * msg){
   bool found = false;
   for (auto socket : _connections){
      if (inet_ntoa(socket.con.sockaddr.sin_addr) == inet_ntoa(con.sin_addr) && (socket.con.sockaddr.sin_port) == con.sin_port){
         found = true;
         break;
		}
	}
   if (!found){
      mavlink_msg_ralcp_decode(msg, &packet);
      Connection connect = Connection(id++, Connection::UNKNOWN, con);
      Connection::Identifier des = Connection::UNKNOWN;
      switch(packet.Destination){
         case COMMAND_DESTINATION::ROSBEE:
            des = Connection::ROSBEE;
            break;
         case COMMAND_DESTINATION::LIDAR:
			   des = Connection::LIDAR;
			   break;
		   default:
			   std::cerr << "UNKNOWN DEVICE CONNECTION NOT HANDLED\r\n";
			return;
		}
		
      connect.type = des;
      UDPSocket sock(connect, this);
      RobotManager::get()->createRosbee(sock);

      _connections.push_back(sock);
      printf("New connection from %s:%d\r\n", inet_ntoa(con.sin_addr), ntohs(con.sin_port));
      std::cout << "packet function was:" << packet.Function << std::endl;
      std::cout << "Packet data was: " << packet.Payload << std::endl;
	}
}

void UDPServer::stop(){
   stopped = true;
}

UDPServer::~UDPServer(){
   stop();
}