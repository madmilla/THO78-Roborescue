#include "UDPServer.h"


UDPServer::UDPServer(RobotManager & manager) : manager(manager){
	recv = 0;
	sourceAddress = "";
	sourcePort = 0;
	std::cout << "Created server instance" << std::endl;
	init();
   connectionThread = std::thread(&UDPServer::start, this);

	}

void UDPServer::init(){
	udpsock = new UDPSocket(8888);
	std::cout << "Initialized socket at: \t 8888" << std::endl;
}

void UDPServer::start(){
	try {
		while (!stopped) {
			try{
				//std::cout << "Waiting for message..." << std::endl;
				receive(&msg);
				addConnection(sourceAddress, sourcePort, &msg);
				handleMessage(sourceAddress, sourcePort, &msg);
			}
			catch (SocketException ex){
				std::cout << "Nothing received : " << ex.what() << std::endl;
			}
		}
	}
	catch (SocketException &e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}

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

void UDPServer::send(CPIUDPSocket * socket, mavlink_message_t * message){
	udpsock->sendTo(message, sizeof(mavlink_message_t), socket->con.sockaddr, socket->con.port);
}

void UDPServer::receive(mavlink_message_t * message){
	std::cout << "receiving message "<< std::endl;
	auto data = udpsock->recvFrom(&msg, sizeof(mavlink_message_t), sourceAddress, sourcePort);
	recv++;
}

void UDPServer::handleMessage(std::string con,unsigned short port, mavlink_message_t * msg){
   for (auto & socket : _connections){
	   if (socket->con.sockaddr == con && socket->con.port == port){
		socket->receive(msg);
      }
   }
}

void UDPServer::addConnection(std::string con,unsigned short port, mavlink_message_t * msg){
   bool found = false;
   for (auto * socket : _connections){
	   if (socket->con.sockaddr == con && socket->con.port == port){
		   found = true;
		   return;
	   }
	}
   if (!found){
   	  
   	  mavlink_msg_command_long_decode(msg, &packet);
      Connection connect = Connection(ConId, Connection::UNKNOWN, con,port);
      ConId++;
      Connection::Identifier des = Connection::UNKNOWN;

      switch((int)packet.target_system){
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
	  CPIUDPSocket * sock = new CPIUDPSocket(connect, this);

	 manager.createUDPRobot(sock);

      _connections.push_back(sock);
      sock->receive(msg);
      printCon();
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