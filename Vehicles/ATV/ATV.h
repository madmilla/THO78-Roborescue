#ifndef _ATV_H
#define _ATV_H

#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
#include "TempMAVSender.h"

class ATV
{
public:
	ATV(TempMAVSender & mavlinkSender);
	~ATV();
	void moveForward();
private:
	TempMAVSender & mavlinkSender;
};

#endif