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
         //encoder->send(COMMAND_DESTINATION::ROSBEE, pair.first, pair.second);
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
         //std::cout << "Send message!" <<std::endl;
      }
     if(sock->incomming->size() > 0){
		 //Do stuff with incomming messages
       }
      std::this_thread::sleep_for(std::chrono::seconds(2));
   }
    
}
void Rosbee::init(){

   outgoing->add(std::make_tuple(0,0,0,0,0,0,0,ROSBEE_COMMAND_FUNCTIONS::ROSBEE_INIT,COMMAND_DESTINATION::ROSBEE,0,0));
}

void Rosbee::getRequirementStatus(){
  // memset(data, 0, 4 * sizeof(data[0]));
  // outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::GETEQUIPMENTSTATUS, data));

}

void Rosbee::startMission(){
 //  memset(data, 0, 4 * sizeof(data[0]));
//   outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::STARTMISSION, data));

}

void Rosbee::sendWaypoint(int x, int y){
   //memset(data, 0, 4 * sizeof(data[0]));
   //data[0] = x;
   //data[1] = y;
   //outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::SENDWAYPOINT, data));
}

void Rosbee::getRequest(){
   //memset(data, 0, 4 * sizeof(data[0]));
   //outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::ROSBEE_GETREQUEST, data));
}

void Rosbee::stopMission(){
   //memset(data, 0, 4 * sizeof(data[0]));
   //outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::STOPMISSION, data));
}

void Rosbee::abortMission(){
 //  memset(data, 0, 4 * sizeof(data[0]));
// outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::ABORTMISSION, data));

}

void Rosbee::sonarInterrupt(){

}

void Rosbee::sendAck(){
  // memset(data, 0, 4 * sizeof(data[0]));
  // outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::ACKNOWLEDGE, data));
}

void Rosbee::BatteryStatus(){
  // memset(data, 0, 4 * sizeof(data[0]));
  // outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, int*>(ROSBEE_COMMAND_FUNCTIONS::BATTERYSTATUS, data));
}


void Rosbee::getDevice(uint8_t dev){

  // outgoing->add(std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>(ROSBEE_COMMAND_FUNCTIONS::GETDEVICE, uint64_t(dev << 54)));
}

int Rosbee::getId(){
   return sock->getId();
}
void Rosbee::abort(){
   running = false;
}


    MessageQueue<mavlink_message_t *> * Rosbee::getMessageQueue(){
      return sock->incomming;
    }
    