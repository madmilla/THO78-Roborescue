#include "mapLogicVSLAM.h"

mapLogicVSLAM::mapLogicVSLAM(map * Map, Rosbee * rosbee)
{
	this->Map = Map;
	this->rosbee = rosbee;
}

mapLogicVSLAM::~mapLogicVSLAM()
{

}

void mapLogicVSLAM::setTilesInRangeLidar(){
	int x = rosbee->getRosbeeLocationX() - 2;
	int y = rosbee->getRosbeeLocationY() - 2;
	for (int i = 0; i < 5; i++){
		for (int ii = 0; ii < 5; ii++){
			if ((x + i) >= 1 && (x + i) <= (Map->getScaledHeight()-1) && (y + ii) >= 1 && (y + ii) <= (Map->getScaledWidth()-1)){
				Map->setScaledLocationValue((x + i), (y + ii), 2);
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
				return tileLocation;
			}
		}
	}
}
