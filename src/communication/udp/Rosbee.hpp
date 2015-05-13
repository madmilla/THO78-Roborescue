
//Author Rene keijzer
// class Rosbee
// This class is used to initialize the rosbee and it contains the functions that the rosbee can recieve or send to the CPI
#ifndef __ROSBEE__
#define __ROSBEE__
#include "mingw.thread.h"
#include "CPIBoundaryObject.hpp"
#include "../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include "Socket.hpp"
#include "MessageQueue.h"
#include "RALCPEncoder.hpp"
class Rosbee : public CPIBoundaryObject
{
public:
	// constructor to make a Rosbee object (socket)
	// @param: Socket is used to listen to a specific socket
		Rosbee(Socket s) : CPIBoundaryObject(s, s.getId()){
		encoder = new RALCPEncoder(s, s.getId(), 0, 0, 0);
		rosbeeThread = std::thread(&Rosbee::run, this);
	}

	// initialize the Rosbee 
	void init();
	void run();

	// this function checks if all devices are ready or not
	void getRequirementStatus();

	// This function starts a mission for a Rosbee
	void startMission();

	// This function sends waypoints to the Rosbee so he can ride to his destination
	// @param: uint8_t x this parameter is used to send the x-axis of the new destination for the rosbee
	// @param: uint8_t y this parameter is used to send the y-axis of the new destination for the rosbee
	void sendWaypoint(uint8_t x, uint8_t y);

	// This function can ask for a request at the CPI ( for now it only asks for new waypoints )
	void getRequest();

	// This function stops the mission of a Rosbee
	void stopMission();

	// This function cancells a mission of a Rosbee
	void abortMission();

	// This function sends a sonar interrupt to the CPI 
	void sonarInterrupt();

	// This function is needed for tests
	void sendAck();

	// This function is not used for now (maybe in the future)
	void BatteryStatus();

	// This function can finc out who the device is
	// @param: uint8_t dev this is the device
    void getDevice(uint8_t dev);
    void abort();

	~Rosbee(){ delete encoder; }

private:


	friend class RobotManager;

	mavlink_message_t message;
	std::thread rosbeeThread;
	RALCPEncoder * encoder;
	bool running = false;
	MessageQueue<std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>> outgoing;
};
#endif