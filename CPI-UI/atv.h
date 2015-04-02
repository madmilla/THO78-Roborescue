#ifndef ATV_H
#define ATV_H

#include "otherstuff.h"

class ATV
{
public:
    enum class ControlMode : unsigned int{
        Manually, Autonomous
    };

    ATV();
    ~ATV();

    ///
    /// \brief Init ATV checks hardware
    /// \param maxAltitude maxAltitude for quadcopter
    /// \param controlMode controlMode for quadcopter
    /// \return 0 if Init succeeded and no problems in hardware
    ///
    unsigned int Init(ControlMode mode);

    ///
    /// \brief startMission start the mission for the atv
    /// \param location start location of atv on the mapData
    /// \param maximumTime maximumTime in minutes for atv to compleete mission
    /// \param mapData map data the atv need to know before starting the mission
    /// \return true if startMission succeeded
    ///
    bool startMission(DPoint location, unsigned int maximumTimeMin, Map mapData);

    ///
    /// \brief stopMission stopMission of atv
    ///
    void stopMission();

    ///
    /// \brief abortMission abort the mission of atv
    ///
    void abortMission();

    ///
    /// \brief batteryStatus ask for bettery status of atv
    /// \return percentage 0% - 100%
    ///
    unsigned char batteryStatus();

    ///
    /// \brief setSteeringMode change steermode of atv
    /// \param controlMode new control mode
    ///
    void setSteeringMode(ControlMode controlMode);

    ///
    /// \brief stop atv, shutdown motors etc.
    ///
    void stop();

    ///
    /// \brief fixConnection try restore connection
    ///
    void fixConnection();
};

#endif // ATV_H
