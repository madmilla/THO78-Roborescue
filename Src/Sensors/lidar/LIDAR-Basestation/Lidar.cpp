#include "Lidar.h"

Lidar::Lidar(CPIUDPSocket * s) : UDPRobot(s){
   outgoing = new MessageQueue<std::tuple<int, int, int, int, int, int, int, LIDAR_COMMAND_FUNCTIONS, COMMAND_DESTINATION, int, int>>();
   start();
}

void Lidar::run(){

   running = true;
   while (running){

      if (outgoing->size() > 0){
         auto tuple = outgoing->pop();
         encoder->send(
            std::get<0>(tuple),
            std::get<1>(tuple),
            std::get<2>(tuple),
            std::get<3>(tuple),
            std::get<4>(tuple),
            std::get<5>(tuple),
            std::get<6>(tuple),
            std::get<7>(tuple),
            std::get<8>(tuple),
            std::get<9>(tuple),
            std::get<10>(tuple)
            );
      }
      if (sock->incomming->size() > 0){
         auto msg = sock->incomming->peek();
         mavlink_msg_command_long_decode(msg, &packet);
         if (packet.command = LIDAR_COMMAND_FUNCTIONS::LINEDATA){
        	 LineDataQueue->add(std::make_tuple(packet.param1, packet.param2, packet.param3, packet.param4));
         }
      }
      std::this_thread::sleep_for(std::chrono::seconds(2));
   }

}


void Lidar::init(){
   outgoing->add(std::make_tuple(0, 0, 0, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::LIDAR_INIT, COMMAND_DESTINATION::LIDAR, 0, 0));
}

void Lidar::recieveLine(){
   outgoing->add(std::make_tuple(0, 0, 0, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::LINEDATA, COMMAND_DESTINATION::LIDAR, 0, 0));
}

void Lidar::recieveRpm(){
   outgoing->add(std::make_tuple(0, 0, 0, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::RPM, COMMAND_DESTINATION::LIDAR, 0, 0));
}

void Lidar::Start(int x, int y, int degrees){
   outgoing->add(std::make_tuple(x, y, degrees, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::START, COMMAND_DESTINATION::LIDAR, 0, 0));
}

void Lidar::Stop(){
   outgoing->add(std::make_tuple(0, 0, 0, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::STOP, COMMAND_DESTINATION::LIDAR, 0, 0));
}

void Lidar::sendRosbeePositie(int position){
   outgoing->add(std::make_tuple(position, 0, 0, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::ROSBEEPOSITION, COMMAND_DESTINATION::LIDAR, 0, 0));
}

void Lidar::sendRosbeeFlank(int degrees){
   outgoing->add(std::make_tuple(degrees, 0, 0, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::ROSBEEFLANK, COMMAND_DESTINATION::LIDAR, 0, 0));
}

void Lidar::getDevice(uint8_t dev){
   outgoing->add(std::make_tuple(dev, 0, 0, 0, 0, 0, 0, LIDAR_COMMAND_FUNCTIONS::LIDAR_GETDEVICE, COMMAND_DESTINATION::LIDAR, 0, 0));
}

int Lidar::getId(){
	return sock->getId();
}

void Lidar::abort(){
	running = false;
}
