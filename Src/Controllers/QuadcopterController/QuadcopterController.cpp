#include "QuadcopterController.h"
#include <iostream>

QuadcopterController::QuadcopterController(
	Quadcopter& quadcopter, XYLocalisationModule& locMod) :
registeredQuadcopter{quadcopter},
registeredLocationModule{locMod}
{
}

void QuadcopterController::setTarget(Coordinate<double> target, float tgtHeight)
{
	targetLocation = target;
	targetHeight = tgtHeight;
}

void QuadcopterController::setPosition()
{
	recentLocation = registeredLocationModule.getCoordinate();
}

Coordinate<double> QuadcopterController::getPosition()
{
	return recentLocation;
}

void QuadcopterController::setHeight(float currentHeight)
{
	recentHeight = currentHeight;
}

void QuadcopterController::moveTowardsTarget()
{
	/* TODO: Implement operator == on Coordinate template */
	/*if (targetLocation == Coordinate<double>{-1,-1} || targetHeight == -1)
	{
		std::cout << "Set a target first!";
		return;
	}*/

	if (abs(recentHeight - targetHeight) < allowedDeviation && 
		abs(targetLocation.getX() - recentLocation.getX()) < 
		allowedDeviation && abs(targetLocation.getY() - 
		recentLocation.getY()) < allowedDeviation)
	{
		std::cout << "Destination reached!";
		return;
	}

	if (recentHeight < targetHeight - allowedDeviation)
	{
		std::cout << "increase the quadcopter height by " << 
		(targetHeight - recentHeight) * 100 << " cm!";
		return;
	}
	else
	{
		if (recentHeight > targetHeight + allowedDeviation)
		{
		std::cout << "Decrease the quadcopter height by " << 
			(recentHeight - targetHeight) * 100 << " cm!";
			return;
		}
		else
		{
			if (abs(targetLocation.getX() - recentLocation.getX()) >=
				abs(targetLocation.getY() - recentLocation.getY()))
			{
				if (recentLocation.getX() < targetLocation.getX() - 
					allowedDeviation)
				{
					std::cout << "Move the quadcopter " << 
					targetLocation.getX() - recentLocation.getX() <<
					" m to the right!";
					return;
				}
				else
				{
					std::cout << "Move the quadcopter " << 
					recentLocation.getX() - targetLocation.getX() << 
					" m to the left!";
					return;
				}
			}
			else
			{
				if (recentLocation.getY() < targetLocation.getY() - 
					allowedDeviation)
				{
					std::cout << "Move the quadcopter forward " <<
					targetLocation.getY() - recentLocation.getY() <<
					" m!";
					return;
				}
				else
				{
					std::cout << "Move the quadcopter backwards " << 
					recentLocation.getY() - targetLocation.getY() <<
					" m!";
					return;
				}
			}
		}
	}
}

QuadcopterController::~QuadcopterController()
{
}
