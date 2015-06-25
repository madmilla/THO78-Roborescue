#ifndef CPICONNECTOR_H_
#define CPICONNECTOR_H_


#include <cstdint>
#include <iostream>

#include "BaseRobot.h"
#include "mavlink.h"

//This is an example child class
class CPIConnector : public BaseRobot
{
public:
	CPIConnector();
	void onMessage(mavlink_message_t & function) override;
};

#endif //CPICONNECTOR_H_
