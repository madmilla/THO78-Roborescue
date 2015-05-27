#ifndef CPICONNECTOR_H_
#define CPICONNECTOR_H_


#include <cstdint>
#include <queue>
#include <iostream>
#include "../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
#include "SocketListener.h"

class CPIConnector : public SocketListener
{
public:
	CPIConnector(uint16_t id);
	void sendCommand(LIDAR_COMMAND_FUNCTIONS cmd, uint64_t payload);
	void onMessage(mavlink_ralcp_t & function) override;

private:
	uint16_t DeviceId;
};

#endif //CPICONNECTOR_H_
