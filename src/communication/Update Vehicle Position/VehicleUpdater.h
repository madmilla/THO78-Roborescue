#ifndef VEHICLEUPDATER_H
#define VEHICLEUPDATER_H

#include "VehicleState.h"

class VehicleUpdater {
private:

public:
	VehicleUpdater();
	~VehicleUpdater();

	static VehicleState getRosbeePosition();
	static VehicleState getATVPosition();
	static VehicleState getQuadCopterPositon();
};

#endif