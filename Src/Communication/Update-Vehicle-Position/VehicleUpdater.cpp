#include "VehicleUpdater.h"

VehicleUpdater::VehicleUpdater()
{

}

VehicleUpdater::~VehicleUpdater()
{

}

VehicleState VehicleUpdater::getRosbeePosition()
{
	return VehicleState(1, 2, 3, 4.0f);
}

VehicleState VehicleUpdater::getATVPosition()
{
	return VehicleState(5, 6, 7, 8.0f);
}

VehicleState VehicleUpdater::getQuadCopterPositon()
{
	return VehicleState(9, 10, 11, 12.0f);
}

std::ostream& operator<<(std::ostream& os, const VehicleState& state)
{
	os << "(" << state.x << ", " << state.y << ", " << state.z << ", " << state.theta << ")";
	return os;
}