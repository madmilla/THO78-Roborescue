#include "StrategyController.h"
int main(){
	map Map;
	QuadCopter copter(Dimension(1, 1), Dimension(3, 3), 1, 1);
	//ATV atv;
	Rosbee rosbee;
	Lidar lidar;
	StrategyController controller(Map,copter,rosbee,lidar);
	controller.scanArea();
	controller.searchArea();

}