#ifndef _MISSION_1_H
#define _MISSION_1_H
#include <memory>

class MAVLinkExchanger;
class TCPConnection;
class Quadcopter;
class Rosbee;
class XYLocalisationModule;

const std::string LOCAL_IP{"145.89.118.25"};
const int LIDAR_PORT{ 8000 };
const std::string QUADCOPTER_IP{ "" };
const int QUADCOPTER_PORT{ 8001 } ;

class Mission1
{
public:
	void initialize();
	void run();
private:
	bool isInitialized;
	
	std::shared_ptr<MAVLinkExchanger> quadcopterExchanger;
	std::shared_ptr<TCPConnection> quadcopterConnection;
	std::shared_ptr<MAVLinkExchanger> lidarExchanger;
	std::shared_ptr<TCPConnection> lidarConnection;
	std::shared_ptr<MAVLinkExchanger> localisationExchanger;
	std::shared_ptr<TCPConnection> localisationConnection;
	
	std::shared_ptr<Quadcopter> quadcopter;
	std::shared_ptr<Rosbee> rosbee;
	std::shared_ptr<XYLocalisationModule> localisationModule;
};
#endif