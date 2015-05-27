#endif /* LIDAR_H_ */


//Author Rene keijzer
// class Lidar
// This class is used to initialize the Lidar and it contains the functions that the Lidar can recieve or send to the CPI
#ifndef __LIDAR__
#define __LIDAR__

#include <chrono>
#include "CPIBoundaryObject.hpp"
#include "../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include "UDPSocket.hpp"
#include "MessageQueue.h"
#include "RALCPEncoder.hpp"
class UDPSocket;
class Lidar : public CPIBoundaryObject
{
public:
	// constructor to make a Lidar object (socket)
	// @param: Socket is used to listen to a specific socket
	Lidar(UDPSocket * s);

	// initialize the Lidar 
	void init();
	void run() override;

	//! \brief Recieve line data from the lidar
	void recieveLine();

	//! \brief standard constructor
	//! \param[in] msg a reference to the mavlink message struct
	void recieveRpm();

	//! \brief standard constructor
	//! \param[in] rpm a reference to rpm to be set for the Lidar
	void sendRpm(int rpm);

	//! \brief start the lidar to scan
	void Start();

	//! \brief stops the lidar with scanning
	void Stop();

	//! \brief sends the last knwon positon of the rosbee
	//! \param[in] postion a reference to the positon of the rosbee
	void sendRosbeePositie(int postion);

	//! \brief sends the current flank of the rosbee
	//! \param[in] dagrees a reference to the flank of the rosbee
	void sendRosbeeFlank(int degrees);

	void getData();

	// This function can finc out who the device is
	// @param: uint8_t dev this is the device
	void getDevice(uint8_t dev);
	void abort();
	int getId() override;

	~Lidar(){ delete encoder; }

private:


	friend class RobotManager;
	UDPSocket * sock;
	mavlink_message_t message;
	mavlink_ralcp_t packet;
	RALCPEncoder * encoder;

	bool running = false;
	MessageQueue<std::pair<LIDAR_COMMAND_FUNCTIONS, uint64_t>> * outgoing;
};
#endif
