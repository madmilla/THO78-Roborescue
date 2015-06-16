#ifndef LIDARINIT_H
#define LIDARINIT_H

#include "CPIConnector.h"
//class CPIConnector;
class LidarInit{
public:
LidarInit(CPIConnector *CPI);
	void start();
private:
	CPIConnector *CPI;
};
#endif
