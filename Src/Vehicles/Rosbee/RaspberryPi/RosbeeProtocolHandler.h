
#include "RosbeeClient.h"
#include "PositionController.h"
#include "RosbeeDriver.h"
#include <thread>

class RosbeeProtocolHandler {
private:
	RosbeeClient *rosClient;
	PositionController *posCont;
	RosbeeDriver *rosDriver;

	std::thread thread;

	void run();

public:
	RosbeeProtocolHandler(RosbeeClient &nRosClient, PositionController &nPosContr, RosbeeDriver &nRosDriver);

	void init();
	void driveToWaypoint(long long payload);



};
