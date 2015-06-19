#include "mapLogicVSLAM.h"

mapLogicVSLAM::mapLogicVSLAM(map * Map, Rosbee * rosbee, Lidar * lidar)
{
	this->Map = Map;
	this->rosbee = rosbee;
	this->lidar = lidar;
}

mapLogicVSLAM::~mapLogicVSLAM()
{

}

void mapLogicVSLAM::setTilesInRangeLidar(){
	int x = rosbee->getRosbeeLocationX() - lidar->getRange();
	int y = rosbee->getRosbeeLocationY() - lidar->getRange();
	for (int i = 0; i < ((lidar->getRange() * 2) + 1); i++){
		for (int ii = 0; ii < ((lidar->getRange() * 2) + 1); ii++){
			if ((x + ii) >= 1 && (x + ii) <= (Map->getScaledWidth()-1) && (y + i) >= 1 && (y + i) <= (Map->getScaledHeight()-1)){
				if (Map->getScaledLocationValue((x + ii), (y + i)) == 0){
					Map->setScaledLocationValue((x + ii), (y + i), 2);
				}				
			}
		}
	}
}

int * mapLogicVSLAM::getUnscannedTile(){
	static int tileLocation[1];
	for (int iiy = 0; iiy < Map->getScaledHeight(); iiy++){
		for (int iix = 0; iix < Map->getScaledWidth(); iix++){
			if (Map->getScaledLocationValue(iix, iiy) == 0){
				tileLocation[0] = iix;
				tileLocation[1] = iiy;
				std::cout << tileLocation[0] << tileLocation[1] << std::endl;
				return tileLocation;
			}
		}
	}
	tileLocation[0] = -1;
	tileLocation[1] = -1;
	return tileLocation;
}

bool mapLogicVSLAM::isMapFullyScanned(){
	for (int iiy = 0; iiy < Map->getScaledHeight(); iiy++){
		for (int iix = 0; iix < Map->getScaledWidth(); iix++){
			if (Map->getScaledLocationValue(iix, iiy) == 0){
				return false;
			}
		}
	}
	return true;
}