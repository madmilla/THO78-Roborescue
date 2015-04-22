#ifndef LIDAR_H_
#define LIDAR_H_

#include "lidar_commands/lidar_commands/mavlink.h"
#include "CPIBoundaryObject.hpp"

//! \file Lidar.h
//! \class Lidar
//! \brief A class that communicates with the lidar
//! \details A class that sends and receives commands and manages the communicttion with the lidar
//! \author    Hamza ait Messaoud
//! \version   1.0
//! \date      9-4-2015
//! \warning


class Lidar: public CPIBoundaryObject{

	//! \brief standard constructor
	Lidar(bool equipmentStatus);

	//! \brief standard constructor
	//! \param[in] m a reference to the CommandsMap class
	//! \param[in] s a reference to the CommandsStrategy class
	void sendCommand(mavlink_message_t * cmd) override;

	//! \brief standard constructor
	int * receiveLine();

	//! \brief standard constructor
	//! \param[in] msg a reference to the mavlink message struct
	int receiveRpm(mavlink_message_t & msg);

	//! \brief standard constructor
	//! \param[in] rpm a reference to rpm to be set for the Lidar
	void sendRpm(int rpm);

	//! \brief start the lidar to scan
	void Start();

	//! \brief stops the lidar with scanning
	void Stop();

	//! \brief sends the last knwon positon of the rosbee
	//! \param[in] postion a reference to the positon of the rosbee
	void sendRosbeePositie(int postion[]);

	//! \brief sends the current flank of the rosbee
	//! \param[in] dagrees a reference to the flank of the rosbee
	void sendRosbeeFlank(int degrees);

};


#endif /* LIDAR_H_ */
