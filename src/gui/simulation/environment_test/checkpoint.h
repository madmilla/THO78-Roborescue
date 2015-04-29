/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Checkpoint.h
* @date Created: 15-04-2015
* @version 1.0
*
* @author Danny Horvath, Thomas Fink
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

#ifndef CHECKPOINT_H
#define CHECKPOINT_H


class checkPoint
{
private:
    int checkPointx = 0;
    int checkPointy = 0;
public:
    /*!
    *   Default constructor of checkPoint class.
    *   \brief Default constructor of checkPoint class.
    */
    checkPoint();
    /*!
    *   Constructor of checkPoint class containing x and y coordinates.
    *   \brief Custom constructor of checkPoint class containing an x and y coordinate where the checkpoint will be put.
    *   @param x,y coordinates of the checkpoint inside the 2D-map.
    */
    checkPoint(int x, int y);
    /*!
    *   setCoordinate method sets the coordinates of a checkPoint object.
    *   \brief Sets the coordinates of a checkPoint object to the desired x and y coordinates.
    *   @param x,y coordinates the checkpoints needs to be set to inside the 2D-map.
    */
    void setCoordinates(int x, int y);
    /*!
    *   Sets the x coordinate.
    *   \brief Sets the x coordinate of a given checkPoint object to the desired x coordinate.
    *   @param x x-coordinate the checkpoint needs to be set to inside the 2D-map.
    */
    void setX(int x);
    /*!
    *   Sets the y coordinate.
    *   \brief Sets the y coordinate of a given checkPoint object to the desired y coordinate.
    *   @param y y-coordinate the checkpoint needs to be set to inside the 2D-map.
    */
    void setY(int y);
    /*!
    *   Gets the x coordinate.
    *   \brief Gets and returns the current x coordinate of the checkPoint.
    *   @return returns an int containing the current x coordinates of the checkPoint object.
    */
    int getX();
    /*!
    *   Gets the y coordinate.
    *   \brief Gets and returns the current y coordinate of the checkPoint.
    *   @return returns an int containing the current y coordinates of the checkPoint object.
    */
    int getY();
    /*!
    *   Default destructor.
    *   \brief Default destructor of the checkPoint class.
    */
    ~checkPoint();
};

#endif // CHECKPOINT_H
