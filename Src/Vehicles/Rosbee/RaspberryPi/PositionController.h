/*
 * PositionController.h
 *
 *  Created on: 18 jun. 2015
 *      Author: Edwin
 */

#ifndef POSITIONCONTROLLER_H_
#define POSITIONCONTROLLER_H_

#include "encoderinterface.h"
#include "propcom.h"
#include <thread>

class PositionController {
public:
    explicit PositionController(PropCom* nPropCom);

	float getX();
	float getY();
	float getAngle();

	void setMotorDirection(int motorNr, int direction);

	void reset();

	void updatePosition();
    void odometry(int dLeft, int dRight);

private:
    float m_angleOdometryEstimate;
    float m_dDistance;

	float m_posX;
	float m_posY;

    int lMotorDirection;
    int rMotorDirection;

    EncoderInterface m_eLeft;
    EncoderInterface m_eRight;

    std::thread thread;
};

#endif /* POSITIONCONTROLLER_H_ */
