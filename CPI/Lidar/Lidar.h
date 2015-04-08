/*
 * Lidar.h
 *
 *  Created on: Mar 31, 2015
 *      Author: hamza
 */

#include <string>
#include "test/test_command/mavlink.h"
#include <ros/ros.h>

#ifndef LIDAR_H_
#define LIDAR_H_
using namespace std;

class Lidar{
	Lidar(bool equipmentStatus);
	virtual ~Lidar();

	int * getData();

	int getRpm();
	// Change the RPM on the LIDAR after it has started

	void sendRpm(int rpm);
	// Change the RPM on the LIDAR after it has started

	void Start(int rpm);
	// set the start rpm and start the LIDAR.

	void Stop();
	// stop the LIDAR.

	void sendRosbeePositie(int postion[]);

	void sendRosbeeFlank(int degrees);

};


#endif /* LIDAR_H_ */
