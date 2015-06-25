#include "Rosbee.h"

Rosbee::Rosbee(CPIUDPSocket * s) : UDPRobot(s){
      outgoing = new MessageQueue<std::tuple<int, int, int, int, int, int, int, ROSBEE_COMMAND_FUNCTIONS, COMMAND_DESTINATION, int, int>>();
		start();
	}

void Rosbee::run(){

   running = true;
   while(running){
	  
      if(outgoing->size() > 0){
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
     if(sock->incomming->size() > 0){
		    auto msg = sock->incomming->peek();
          mavlink_msg_command_long_decode(msg, &packet);
          if(packet.command = ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE){
            if (packet.param1 == 0){
               Ready = true;
            }
          }
       }
      std::this_thread::sleep_for(std::chrono::seconds(2));
   }
    
}
void Rosbee::init(){

   outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::ROSBEE_INIT,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::getRequirementStatus(){
   outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::GETEQUIPMENTSTATUS,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::startMission(){
   outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::STARTMISSION,COMMAND_DESTINATION::ROSBEE,0,0));

}

void Rosbee::sendWaypoint(int x, int y){
   outgoing->add(std::make_tuple(x,y,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::STARTMISSION,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::getRequest(){
    outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::ROSBEE_GETREQUEST,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::stopMission(){
    outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::STOPMISSION,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::abortMission(){
    outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::ABORTMISSION,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::sonarInterrupt(){

}

void Rosbee::sendAck(){
   outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::BatteryStatus(){
    outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::BATTERYSTATUS,COMMAND_DESTINATION::ROSBEE,0,0));
}


void Rosbee::getDevice(uint8_t dev){
   outgoing->add(std::make_tuple(dev,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::GETDEVICE,COMMAND_DESTINATION::ROSBEE,0,0));
}

int Rosbee::getId(){
   return sock->getId();
}
void Rosbee::abort(){
   running = false;
}

bool Rosbee::isReady(){
  return Ready;
}

    MessageQueue<mavlink_message_t *> * Rosbee::getMessageQueue(){
      return sock->incomming;
    }
    