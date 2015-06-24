/**
 * @file Rosbee.h
 * @author Coen Andriessen
 * @version 1.1
 */

#ifndef ROSBEE_H
#define ROSBEE_H
//#include "../../Vehicles/Rosbee/Rosbee.h"
#include <iostream>
//#include "../../Vehicles/Rosbee/Rosbee.h"
class VirutalRosbee
{
public:
    // Constructor of rosbee.
	VirutalRosbee();
    // Destructor of rosbee.
	~VirutalRosbee();
    // Function to check if the rosbee location is changed.
    bool isLocationChanged();
    // Function to get the rosbee location x.
    int getRosbeeLocationX();
    // Function to get the rosbee location y.
    int getRosbeeLocationY();
    // Function to get the old rosbee location x.
    int getOldRosbeeLocationX();
    // Function to get the old rosbee location y.
    int getOldRosbeeLocationY();
    // Function to set the rosbee location y.
    void setRosbeeLocationY(int y);
    // Function to set the rosbee location x.
    void setRosbeeLocationX(int x);
	void moveTo(int x, int y);
private:
    int rosbeeLocationX = 1;
    int oldRosbeeLocationX;
    int oldRosbeeLocationY;
    int rosbeeLocationY = 1;
};

#endif // ROSBEE_H
