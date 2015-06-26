#include "virtualLidar.h"

virtualLidar::virtualLidar(){}
virtualLidar::virtualLidar(Lidar* actualLidar):
actualLidar{actualLidar}
{

}

virtualLidar::~virtualLidar()
{

}

int virtualLidar::getRange(){
	return range;
}

void virtualLidar::sendLidarLocationStatus(int rosbeeX, int rosbeeY, int degrees){
	actualLidar->sendRosbeePositie(rosbeeX);
	actualLidar->sendRosbeeFlank(degrees);
	


}
void virtualLidar::start(int x, int y,int angle){}