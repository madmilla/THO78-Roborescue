/*
 * Lidar.h
 *
 *  Created on: Mar 31, 2015
 *      Author: hamza
 */

#ifndef LIDAR_H_
#define LIDAR_H_

#include <string>
#include "CPIBoundaryObject.hpp"

using namespace std;

class Lidar : public CPIBoundaryObject{

public:
	Lidar(bool equipmentStatus);
        void sendCommand(Command cmd) override;
	virtual ~Lidar();

        void init();
	string getData();

	int getRpm();
	// Change the RPM on the LIDAR after it has started

	void sendRpm(int rpm);
	// Change the RPM on the LIDAR after it has started

	void Start(int rpm);
	// set the start rpm and start the LIDAR.

	void Stop();
	// stop the LIDAR.

	void sendRosbeePositie();

	void sendRosbeeFlank();

private:

};


#endif /* LIDAR_H_ */
