#ifndef VEHICLESTATE_H
#define VEHICLESTATE_H

#include <ostream>

class VehicleState {
private:
	int x;
	int y;
	int z;
	float theta;
public:
	VehicleState();
	VehicleState(int x, int y, int z, float theta);
	~VehicleState();

	friend std::ostream& operator<<(std::ostream& os, const VehicleState& state);

	/* Getters */
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getZ() { return this->z; }
	int getTheta() { return this->theta; }

	/* Setters */
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setZ(int z) { this->z = z; }
	void setTheta(float theta) { this->theta = theta; }
};

#endif