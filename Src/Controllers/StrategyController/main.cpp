#include "StrategyController.h"

int main(){
	map Map;
	QuadCopter copter(Dimension(1, 1), Dimension(3, 3), 1, 1);
	//ATV atv;
	virtualRosbee rosbee(5,5);
	virtualLidar virtuallidar;
	StrategyController controller(Map,copter,rosbee,virtuallidar);
	controller.scanArea();
	//controller.searchArea();
	while (1);
}