#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "otherstuff.h"

class Quadcopter
{
public:
    enum class ControlMode : unsigned int{
        Manually, Autonomous
    };

    struct dataPacket{
        DPoint currentLocation;
        unsigned char signalStrength;
        void * gyrodata;
    };

    Quadcopter();
    ~Quadcopter();

    ///
    /// \brief Init Quadcopter checks hardware
    /// \param maxAltitude maxAltitude for quadcopter
    /// \param controlMode controlMode for quadcopter
    /// \return 0 if Init succeeded and no problems in hardware
    ///
    unsigned int Init(unsigned int maxAltitude, ControlMode controlMode);

    ///
    /// \brief startMission start the mission for the quadcopter
    /// \param location start location of quadcopter on the mapData
    /// \param maximumTime maximumTime in minutes for quadcopter to compleete mission
    /// \param mapData map data the quadcopter need to know before starting the mission
    /// \return true if startMission succeeded
    ///
    bool startMission(DPoint location, unsigned int maximumTimeMin, Map mapData);

    ///
    /// \brief stopMission stopMission of quadcopter
    ///
    void stopMission();

    ///
    /// \brief abortMission abort the mission of quadcopter
    ///
    void abortMission();

    ///
    /// \brief batteryStatus ask for bettery status of quadcopter
    /// \return percentage 0% - 100%
    ///
    unsigned char batteryStatus();

    ///
    /// \brief setSteeringMode change steermode of quadcopter
    /// \param controlMode new control mode
    ///
    void setSteeringMode(ControlMode controlMode);

    ///
    /// \brief land the quadcopter
    ///
    void land();

    ///
    /// \brief stop quadcopter, shutdown motors etc. (when landed)
    ///
    void stop();

    ///
    /// \brief fixConnection try restore connection
    ///
    void fixConnection();

    ///
    /// \brief getAllData get some data from quadcopter
    /// \return dataPacket from quadcopter
    ///
    dataPacket getAllData();

};

#endif // QUADCOPTER_H
