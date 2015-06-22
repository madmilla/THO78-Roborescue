#include "QuadcopterController.h"
#include <iostream>

QuadcopterController::QuadcopterController(
	Quadcopter& quadcopter, LocalisationModule& locMod) :
registeredQuacopter(quadcopter),
registeredLocalisationSystem = locMod
{
}

void QuadcopterController::setTarget(coordinate target, float targetHeight)
{
	targetLocation = target;
	targetHeight = targetHeight;
}

void QuadcopterController::setPosition()
{
	recentPosition = registeredLocalisationSystem.getCoordinate();
}

void QuadcopterController::setHeight(float currentHeight)
{
	recentHeight = currentHeight;
}

void QuadcopterController::moveTowardsTarget()
{
	if (targetLocation = nullptr || targetHeight == -1)
	{
		std::cout << "Set a target first!";
		return;
	}

	if (abs(recentHeight - targetHeight) < allowedDeviation && 
		abs(targetLocation.getX() - recentPosition.getX()) < 
		allowedDeviation && abs(targetLocation.getY() - 
		recentPosition.getY()) < allowedDeviation)
	{
		std::cout << "Destination reached!";
		return;
	}

	if (recentHeight < targetHeight - allowedDeviation)
	{
	std:cout << "increase the quadcopter height by " << 
		(targetHeight - recentHeight) * 100 << " cm!";
		return;
	}
	else
	{
		if (recentHeight > targetHeight + allowedDeviation)
		{
		std:cout << "Decrease the quadcopter height by " << 
			(recentHeight - targetHeight) * 100 << " cm!";
			return;
		}
		else
		{
			if (abs(targetLocation.getX() - recentPosition.getX()) >=
				abs(targetLocation.getY() - recentPosition.getY()))
			{
				if (recentPosition.getX() < targetLocation.getX() - 
					allowedDeviation)
				{
					std:cout << "Move the quadcopter " << 
					targetLocation.getX() - recentPosition.getX() <<
					" m to the right!";
					return;
				}
				else
				{
					std:cout << "Move the quadcopter " << 
					recentPosition.getX() - targetLocation.getX() << 
					" m to the left!";
					return;
				}
			}
			else
			{
				if (recentPosition.getY() < targetLocation.getY() - 
					allowedDeviation)
				{
					std:cout << "Move the quadcopter forward " <<
					targetLocation.getY() - recentPosition.getY() <<
					" m!";
					return;
				}
				else
				{
					std:cout << "Move the quadcopter backwards " << 
					recentPosition.getY() - targetLocation.getY() <<
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
