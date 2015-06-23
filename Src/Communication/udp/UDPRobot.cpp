#include "UDPRobot.h"
UDPRobot::UDPRobot(CPIUDPSocket * s) : sock(s){

		encoder = new RALCPEncoder(s, s->getId(), 0, 0, 0);
		
	}