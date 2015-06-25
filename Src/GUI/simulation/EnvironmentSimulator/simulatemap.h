/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file SimulateMap.h
* @date Created: 22-04-2015
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

#ifndef SIMULATEMAP_H
#define SIMULATEMAP_H
#include "map.h"
#include "PointCloud.h"
#include "checkpoint.h"

class Map;

class SimulateMap
{
private:
    //! X Coordinates of the lidar.
    int lidarX = 0;
    //! Y Coordinates of the lidar.
    int lidarY = 0;
    //! Vector containing all checkpoints.
    std::vector<checkPoint> checkpoints;
    //! Pointer to a map object containing the information of the map.
    Map *map;
    //! PointCloud object where the results of the scan will be saved in.
    Pointcloud pC;
public:
    /*!
    *   The simulateMap constructor for an existing Map.
    *   \brief Create a simulateMap object from an existing map given a map pointer.
    *   @param map: the vector containing the map
    */
    SimulateMap(Map *map);
    /*!
    *   Perform a simulation on the given Map.
    *   \brief Detect all objects around the lidar and return a string containing the results.
    *    @return String containing the found objects for the GUI to display.
    */
    std::string simulate();
    /*!
    *   Set the scanpoint(the point where the lidar is located)
    *   \brief Set the scanpoint of the Lidar, the point from where the scan starts.
    *   @param x,y ints containing the x and y position for where you want the lidar to be at.
    */
    void setScanPoint(int y, int x);
    /*!
    *  Add checkpoints to the checkpoint vector.
    *  Add new checkpoints to the vector for simulation.
    *   @param x,y the x and y coordinates of the given checkpoint
    */
    void addCheckPoint(int x, int y);
    /*!
    *  Remove checkpoints from the checkpoint vector.
    *  Remove new checkpoints from the vector for simulation.
    *   @param x,y the x and y coordinates of the given checkpoint
    */
    void deleteCheckPoint(int x, int y);
    /*!
    *   Returns the pointcloud produced by the simulation.
    *   \brief Returns the pointcloud generated by the simulation this pointcloud contains x and y coordinates of found objects.
    *   @return Pointcloud object containing the detected objects.
    */
    Pointcloud getPointCloud();
    /*!
    *   Default destructor of simulate map
    *   \brief The default destructor of simulate map
    */
    ~SimulateMap();

    /*!
    *   Adds noise to a pointcloud
    *   \brief Returns the pointcloud with noise based on distance of the points and percentage
    *   @param Pointcloud that gets noise
    *   @return Pointcloud object containing
    */
    Pointcloud addNoise(Pointcloud pc);
};

#endif // SIMULATEMAP_H
