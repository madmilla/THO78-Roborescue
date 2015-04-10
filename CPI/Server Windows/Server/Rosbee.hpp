#include <queue>
#include "CPIBoundaryObject.hpp"
#include "..\..\mavlink_commands\mavlink_commands\mavlink.h"
#include "Socket.hpp"
#include "RALCPEncoder.hpp"
class Rosbee : public CPIBoundaryObject
{
public:
	Rosbee(Socket s) : CPIBoundaryObject(s, s.getId()){
		encoder = new RALCPEncoder(s, s.getId(), 0, 0, 0);
	}
	void init();
	void getRequirementStatus();
	void startMission();
	void sendWaypoint(uint8_t x, uint8_t y);
	void getRequest();
	void stopMission();
	void abortMission();
	void sonarInterrupt();
	void sendAck();
	void BatteryStatus();
    void getDevice(uint8_t dev);

	~Rosbee(){ delete encoder; }
private:
	mavlink_message_t message;

	RALCPEncoder * encoder;

};
