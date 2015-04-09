#include <queue>
#include "CPIBoundaryObject.hpp"
#include "RosbeeCommand.hpp"
#include "..\mavlink_commands\mavlink_commands\mavlink.h"
#include "Socket.hpp"
class Rosbee : public CPIBoundaryObject
{
public:
	Rosbee(Socket s) : CPIBoundaryObject(s){}
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

	~Rosbee();
private:
	mavlink_message_t message;

	const int SYSTEMID{ 3 };
	const int COMPONENTID{ 0 };
	const int TARGET_SYSTEMID{ 1 };
	const int TARGET_COMPONENTID{ 1 };
	
};
