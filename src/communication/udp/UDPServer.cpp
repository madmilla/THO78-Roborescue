#include "UDPServer.h"


UDPServer::UDPServer(RobotManager & manager) : manager(manager){
	init();
   connectionThread = std::thread(&UDPServer::start, this);
   recv =0;
	}

void UDPServer::init(){
	sock = UDPSocket('127.0.0.1');
}

void UDPServer::start(){
	try {
		while (!stopped) {  // Run forever
			// Block until receive message from a client
			receive(&msg);
			addconnection(sourceAddress, sourcePort, &msg);
			handleMessage(sourceAddress, sourcePort, &msg); 	
		}
	}
	catch (SocketException &e) {
		cerr << e.what() << endl;
		exit(1);
	}
	
	
	/*while(!stopped){
      try{
      receive(&msg);
      addConnection(si_other, &msg);
      handleMessage(si_other, &msg);
      }catch(std::exception & ex){
         std::cout << ex.what();
      }
}*/

   std::this_thread::yield();
}

void UDPServer::printCon(){
   std::cout << "================= connections  "<< _connections.size() <<" ==========="<<std::endl;
   for(auto & sock : _connections){
      sock->print();
   }

   std::cout << "============== end - connections ==========="<<std::endl;
}


void UDPServer::broadcast(mavlink_message_t * message){
   for (auto & socket : _connections){
      send(socket, message);
	}
}

void UDPServer::send(UDPSocket * socket, mavlink_message_t * message){
	sock.sendTo(message, sizeof(mavlink_message_t), socket->sockaddr, socket_Port);
}

void UDPServer::receive(mavlink_message_t * message){
	sock.recvFrom(&msg, sizeof(mavlink_message_t), sourceAddress,sourcePort);
	
	recv++;
}

void UDPServer::handleMessage(std::string con,unsigned short port, mavlink_message_t * msg){
   for (auto & socket : _connections){
	   if (socket->sockaddr == con && socket->port == port){
         socket->receive(msg);
      }
   }
}

void UDPServer::addConnection(std::string con,unsigned short port, mavlink_message_t * msg){
   bool found = false;
   for (auto * socket : _connections){
	   if (socket->sockaddr == con && socket->port == port){
		   found = true;
		   return;
	   }
	}
   if (!found){
      mavlink_msg_ralcp_decode(msg, &packet);
      Connection connect = Connection(ConId, Connection::UNKNOWN, con,port);
      ConId++;
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

      //moved when lidar is intergrated	
	  connect.type = des;
	  UDPSocket * sock = new UDPSocket(connect, this);

	 manager.createUDPRobot(sock);

      _connections.push_back(sock);
      sock->receive(msg);printCon();
	}
}

void UDPServer::stop(){
   stopped = true;
}

UDPServer::~UDPServer(){
	for(auto * sock : _connections)
	{
		delete sock;
	}
   stop();
}