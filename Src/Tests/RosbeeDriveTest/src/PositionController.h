/*
 * PositionController.h
 *
 *  Created on: 18 jun. 2015
 *      Author: Edwin
 */

#ifndef POSITIONCONTROLLER_H_
#define POSITIONCONTROLLER_H_

#include "EncoderInterface.h"
#include "PropCom.h"
#include <thread>

class PositionController {
public:
    explicit PositionController(PropCom* nPropCom);

	float getX();
	float getY();
	float getAngle();

	void reset();

	void updatePosition();
    void odometry(int dLeft, int dRight);

private:
    float m_angleOdometryEstimate;

	float m_posX;
	float m_posY;

    EncoderInterface m_eLeft;
    EncoderInterface m_eRight;

    std::thread thread;
};

#endif /* POSITIONCONTROLLER_H_ */
