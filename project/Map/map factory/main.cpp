#include <iostream>
#include <map.hpp>
#include <mapFactory.h>
#include <Rosbee.h>

int main(){
	mapFactory mF = mapFactory();
	std::vector<line> test = mF.loadMapFromFile("map.map");

	std::cout << "Lines from the objects:" << std::endl;;
	for (const line & l : test){
		std::cout << l << std::endl;
	}

	// Vehicle Storage Test
	Dimension d(50, 50);
	ATV* atv = new ATV(d, 50, 50);
	Rosbee* rosbee = new Rosbee();
	QuadCopter* quadcopter = new QuadCopter(d, d, 20, 20);

	map* theMap = new map();
	theMap->setATVPosition(atv);
	theMap->setRosbeePosition(rosbee);
	theMap->setQuadCopterPositon(quadcopter);
	ATV* newATV = theMap->getATVPosition();
	Rosbee* newRosbee = theMap->getRosbeePosition();
	QuadCopter* newQuadCopter = theMap->getQuadCopterPositon();
	if (rosbee->getRosbeeLocationX() == newRosbee->getRosbeeLocationX()
		&& rosbee->getRosbeeLocationY() == newRosbee->getRosbeeLocationY()
		&& rosbee->getOldRosbeeLocationX() == newRosbee->getOldRosbeeLocationX()
		&& rosbee->getOldRosbeeLocationY() == newRosbee->getOldRosbeeLocationY()
		) {
		std::cout << "Rosbee storage test Pass" << std::endl;
	}
	if (atv->getSize() == newATV->getSize()
		&& atv->getX() == newATV->getX()
		&& atv->getY() == newATV->getY()
		) {
		std::cout << "ATV storage test Pass" << std::endl;
	}
	if (quadcopter->getSize() == newQuadCopter->getSize()
		&& quadcopter->getFov() == newQuadCopter->getFov()
		&& quadcopter->getX() == newQuadCopter->getX()
		&& quadcopter->getY() == newQuadCopter->getY()
		) {
		std::cout << "QuadCopter storage test Pass" << std::endl;
	}


	

	(void)getchar();
	return 0;
}