#include <stdint>
#include "Command.hpp"
/// \Author: 	Hamza ait Messaoud<hamza.aitmessaoud@student.hu.nl>
/// \since:  	2/4/2015
/// \brief:		This document holds all the enum's and command struct for communication with the rosbee


enum CommandDestination{
	ROSBEE,
	LIDAR
};


/// \brief		This Enum holds all possible rosbee commands currently avaible for an 
/// \brief		detailed explanation visit: <a href="http://roborescue.nl/wiki/index.php/Rosbee_Communication_protocol_(RCP)">RCP</a>
enum CommandFunction{
    INIT,
    GETDATA,
    GETRPM,
    SENDROM,
    START,
    STOP,
    SENDROSBEEPOSITION,
    SENDROSBEEFLANK
};



struct LidarCommand : public Command
{
public:
        void setDestination(CommandDestination dest){ dest_id = dest; }
        void setFunction(CommandFunction cf){ function_id = cf; }
        void setPayload(uint64_t load){	payload = load; }

        CommandDestination getDestination(){ return dest_id; }
        CommandFunction getFunction(){	return function_id; }
        uint64_t getPayload(){ return payload;	}
private:
	uint8_t dest_id;
	uint8_t function_id;
	uint64_t payload; 
};
