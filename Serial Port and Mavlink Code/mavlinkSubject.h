#ifndef MAVLINKSUBJECT_H_INCLUDED
#define MAVLINKSUBJECT_H_INCLUDED

#include "mavlink/include/telemetryTest/mavlink.h"
#include "serial.h"
#include "ioDevice.h"
#include <map>
#include <vector>
#include "mavlinkListener.h"
#include <iostream>
class MavlinkSubject {

	public:
		MavlinkSubject();
		void start(std::string & portname);
		void stop();
		void addListener(MavlinkListener * ml);
		void update();
	
	private:
		std::vector <MavlinkListener *> list;
		IoDevice * SP;
};

#endif