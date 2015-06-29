/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file WayPoint.h
* @date Created: 23-06-2015
*
* @author Stefan Dijkman, Nathan Schaaphuizen
* @version 1.1
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/
#ifndef WAYPOINTMOVEMENT_H
#define WAYPOINTMOVEMENT_H

/// @brief Class to make waypoints from a offset.
///
/// The waypoint is relative to the origin. That is to say, it always assumes that the current
/// position is (0,0).
class Waypoint{
private:
	double angle;
	double distance;
	//Helper function to convert radians to degrees.
	double toDegrees(double radian);

public:
	/// @brief Create new Waypoint object.
	///
	/// The unit in which the offsets are given is undefined and can be anything as long as
	/// the're the same for both parameters.
	/// Note that all the other functions will return in the same unit as given here.
	/// @param x Offset on the x-axis.
	/// @param y Offset on the y-axis.
	Waypoint(double x, double y);
	
	/// @brief Get the distance to the waypoint.
	///
	/// The distance is the distance between the origin and the waypoint in a strait line.
	/// @return The distance in the same unit as given in the constructor.
	double getDistance();
	
	/// @brief Get the angle to  the waypoint.
	///
	/// The angle that needs to be straight in order to face strait to the waypoint.
	/// @return The angel in degrees.
	double getAngle();
};
#endif // WAYPOINTMOVEMENT_H
