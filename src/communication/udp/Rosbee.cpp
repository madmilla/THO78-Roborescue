#include "Rosbee.h"

Rosbee::Rosbee(UDPSocket * s) : sock(s){

		encoder = new RALCPEncoder(s, s->getId(), 0, 0, 0);
		outgoing = new MessageQueue<std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>>();
		start();
	}

void Rosbee::run(){

   running = true;
   while(running){
	  
      if(outgoing->size() > 0){
         auto pair = outgoing->pop();
         encoder->send(COMMAND_DESTINATION::ROSBEE, pair.first, pair.second);
         std::cout << "Send message!" <<std::endl;
      }
     if(sock->incomming->size() > 0){
		 //Do stuff with incomming messages
       }
      std::this_thread::sleep_for(std::chrono::seconds(2));
   }
    
}
void Rosbee::init(){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::ROSBEE_INIT, 0));
}

void Rosbee::getRequirementStatus(){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::GETEQUIPMENTSTATUS, 0));

}

void Rosbee::startMission(){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::STARTMISSION, 0));

}

void Rosbee::sendWaypoint(uint8_t x, uint8_t y){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::SENDWAYPOINT, uint64_t((x << 54 ) | (y << 46))));
}

void Rosbee::getRequest(){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::ROSBEE_GETREQUEST, 0));
}

void Rosbee::stopMission(){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::STOPMISSION, 0));
}

void Rosbee::abortMission(){
 outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::ABORTMISSION, 0));

}

void Rosbee::sonarInterrupt(){

}

void Rosbee::sendAck(){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE, 0));
}

void Rosbee::BatteryStatus(){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::BATTERYSTATUS, 0));
}


void Rosbee::getDevice(uint8_t dev){
   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::GETDEVICE, uint64_t(dev << 54)));
}

int Rosbee::getId(){
   return sock->getId();
}
void Rosbee::abort(){
   running = false;
}