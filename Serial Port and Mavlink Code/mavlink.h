#ifndef MAVLINK_H_INCLUDED
#define MAVLINK_H_INCLUDED

#include "mavlink/include/telemetryTest/mavlink.h"
#include "serial.h"
#include "ioDevice.h"
#include <map>
#include <vector>
#include "mavlinkListener.h"
class Mavlink {
	protected:
		Mavlink();
	public:
		static Mavlink * getInstance();
		
	void start(std::string & portname);
	void stop();
	void addListener(int id,MavlinkListener * ml);
	void update();
	
	private:
		std::map <int,std::vector <MavlinkListener *>*> map;
		static Mavlink * mavlink;
		IoDevice * SP;
};

#endif