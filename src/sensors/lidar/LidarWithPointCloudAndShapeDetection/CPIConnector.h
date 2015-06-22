#ifndef CPICONNECTOR_H_
#define CPICONNECTOR_H_


#include <cstdint>
#include <iostream>
#include "rplidar.h"
#include "Lidar.h"
#include "shapedetector.h"
#include "PointCloud.h"
#include "BaseRobot.h"
#include "../../../../deps/incl/mavlink/udp_mavlink_commands/mavlink.h"
//This is an example child class
class CPIConnector : public BaseRobot
{
public:
	CPIConnector();
	~CPIConnector();
	void onMessage(mavlink_message_t & function) override;
private:
	Lidar *lidar = nullptr;
};

#endif //CPICONNECTOR_H_

