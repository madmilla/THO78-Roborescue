
/// \Author Rene keijzer
/// \class Rosbee
/// \This class is used to initialize the rosbee and it contains the functions that the rosbee can recieve or send to the CPI
#ifndef __ROSBEE__
#define __ROSBEE__

#include <chrono>
#include "CPIBoundaryObject.hpp"
#include "../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include "UDPSocket.hpp"
#include "MessageQueue.h"
#include "RALCPEncoder.hpp"
class UDPSocket;
class Rosbee : public CPIBoundaryObject
{
public:
	/// \brief constructor to make a Rosbee object (socket)
	/// \param: Socket is used to listen to a specific socket
	Rosbee(UDPSocket * s);

	/// \brief initialize the Rosbee 
	void init();

	/// \brief Run method of the rosbee boundary, this run reads it's queue's and handles it messsages
	void run() override;

	/// \brief this method checks if all devices are ready or not
	void getRequirementStatus();

	/// \brief This method starts a mission for a Rosbee
	void startMission();

	/// \brief This method sends waypoints to the Rosbee so he can ride to his destination
	/// \param: uint8_t x this parameter is used to send the x-axis of the new destination for the rosbee
	/// \param: uint8_t y this parameter is used to send the y-axis of the new destination for the rosbee
	void sendWaypoint(uint8_t x, uint8_t y);

	/// \brief This method can ask for a request at the CPI ( for now it only asks for new waypoints )
	void getRequest();

	/// \brief This method stops the mission of a Rosbee
	void stopMission();

	/// \brief This method cancells a mission of a Rosbee
	void abortMission();

	/// \brief This method sends a sonar interrupt to the CPI 
	void sonarInterrupt();

	/// \brief This method is needed for tests
	void sendAck();

	/// \brief This method is not used for now (maybe in the future)
	void BatteryStatus();

	/// \brief This method can finc out who the device is
	/// \param: uint8_t dev this is the device
    void getDevice(uint8_t dev);
    
    /// \brief aborts rosbee
    void abort();

    /// \brief returns unique identifier
    int getId() override;

	~Rosbee(){ delete encoder;  }

private:


	friend class RobotManager;
	UDPSocket * sock;
	mavlink_message_t message;
	mavlink_ralcp_t packet;
	RALCPEncoder * encoder;

	bool running = false;
	MessageQueue<std::pair<ROSBEE_COMMAND_FUNCTIONS, uint64_t>> * outgoing;
};
#endif
