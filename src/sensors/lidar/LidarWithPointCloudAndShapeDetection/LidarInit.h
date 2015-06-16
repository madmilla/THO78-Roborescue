#ifndef LIDARINIT_H
#define LIDARINIT_H

#include "LidarInit.h"
#include "CPIConnector.h"

class LidarInit{

public:
	void start();
private:
	CPIConnector &CPI;
};
#endif