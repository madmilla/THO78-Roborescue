#ifndef CPICONNECTOR_H_
#define CPICONNECTOR_H_


#include <cstdint>
#include <iostream>
#include "Lidar.h"
#include "BaseRobot.h"
#include "mavlink.h"

//This is an example child class
class CPIConnector : public BaseRobot
{
public:
	CPIConnector();
	void onMessage(mavlink_message_t & function) override;
private:
	Lidar *lidar = nullptr;
};

#endif //CPICONNECTOR_H_
