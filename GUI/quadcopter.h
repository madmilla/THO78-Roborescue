#ifndef _QUADCOPTER_H
#define _QUADCOPTER_H
//#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"

class Quadcopter
{
private:
    bool flying, armed, manual;


public:
    Quadcopter();
    ~Quadcopter();
    void liftOff();
    void arm();
    void moveLeft();
    void moveRight();
    void moveForward();
    void moveBackward();
    void stop();
    void land();
    bool isFlying();
    bool isArmed();
    bool isManual();
    void setManual(bool);
    void changeFlightSpeed(int);
    void changeHeading(int);
};
#endif
