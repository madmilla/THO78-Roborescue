#include <queue>
#include "CPIBoundaryObject.hpp"
#include "RosbeeCommand.hpp"
class Rosbee : public CPIBoundaryObject
{
public:
	Rosbee();
	void sendCommand(Command cmd) override;
	void receivedCommands(Command cmd);
	void init();
	Command getRequirementStatus();
	void startMission();
        void sendWaypoint(Command cmd);
	void getRequest();
	void stopMission();
	void abortMission();
        void sonarInterupt(Command cmd);
	void sendAck();
	void BatteryStatus();
        void sendInterrupt(Command cmd);
        Command getDevice();

	~Rosbee();
private:
	std::queue<uint64_t> receivedCommands;
	
};
