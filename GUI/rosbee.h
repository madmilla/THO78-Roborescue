#ifndef ROSBEE_H
#define ROSBEE_H

#include "otherstuff.h"

/**
* @class  Rosbee
* @author Wibren Wiersma (wibrenwiersma@hotmail.com)
* @date   April, 2015
* @brief  WARNING THIS IS ONLY A TEST CLASS FOR THE UI!!!
*/
class Rosbee
{
public:
    Rosbee();
    ~Rosbee();

    ///
    /// \brief Init Rosbee checks hardware
    /// \return 0 if Init succeeded and no problems in hardware
    ///
    unsigned int init();

    ///
    /// \brief startMission The CC will calculate the way for the Rosbee.  And the Rosbee will navigate on the waypoint information it has recieved.
    /// \param waypoint the waypoint based on the starting map from the lidar
    ///
    void startMission();

    ///
    /// \brief abortMission aborts the mission will not shtudown the robot
    ///
    void abortMission();

    ///
    /// \brief batteryStatus ask for bettery status of Rosbee
    /// \return percentage 0% - 100%
    ///
    unsigned char batteryStatus();

    ///
    /// \brief stopMission stopMission of Rosbee
    ///
    void stopMission();

    ///
    /// \brief getStatus ask for the last status of te rosbee. Object detected whatever.
    /// \return a text representation of the status of de robot
    ///
    std::string getStatus();
};

#endif // ROSBEE_H
