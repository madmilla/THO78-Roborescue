#include "virtualLidar.h"

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

