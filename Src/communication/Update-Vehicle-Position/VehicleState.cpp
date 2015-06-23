#include "VehicleState.h"

VehicleState::VehicleState() : x(0), y(0), z(0), theta(0.0f)
{

}

VehicleState::VehicleState(int x, int y, int z, float theta) : x(x), y(y), z(z), theta(theta)
{

}

VehicleState::~VehicleState()
{

}
