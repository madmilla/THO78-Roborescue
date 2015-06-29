/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Map.h
* @date Created: 12-04-2015
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
#ifndef MAP_H
#define MAP_H

#include "simulatemap.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PointCloud.h"
#include "values.h"

class Map
{
public:
    //! A object which will contain a x, y and id.
    struct Object{
        int X; //! The x value of a single object
        int Y; //! the Y-value of a single object
        int id;//! the id-value of a single object
        //! a operator to look if an object is equal to an object
        bool operator==(const Object& rhs) const{
             return (X == rhs.X && Y == rhs.Y && id == rhs.id);
        }
        //! a operator to look if an object is smaller then an object. Sorted by x first then y
        bool operator<(const Object& rhs) const{
             if(X != rhs.X) return X < rhs.X;
             return Y < rhs.Y;
         }
    };
    /*!
    *   Map constructor with a given file.
    *   \brief Given a filename this constructor will read and convert a .map file to a map object.
    *   @param fileName the name of a .map file containing map information.
    */
    Map(std::string fileName);
    /*!
    *   Map constructor with a given file.
    *   \brief Given a pointcloud pointer this constructor will convert a pointcloud object to a map object.
    *   @param pcl the pointer of the pointcloud. The pointcloud containing point information.
    */
    Map(std::string fileName, Pointcloud *pcl);
    /*!
    *   Map constructor with given file, height and width.
    *   \brief This constructor is used for making a new map with a standard height & width.
    *   @param fileName the name of a .map file containing map information
    *   @param height the height of the map
    *   @param width the width of the map
    */
    Map(std::string fileName, int height, int width);
    /*!
    *   getMapContent gets all the information of a map.
    *   \brief This function gets and returns all information of a map object in a 2D-vector.
    *   @return std::vector< Object > a 2D-vector containing all the map information.
    */
    std::vector< Object > getMapContent();
    /*!
    *   setMapContent is used to set a map to the content of a given 2D-vector.
    *   \brief Sets al the data in the map to the data in a given 2D-vector containing ints.
    *   @param newMapLayout is a 2D-Vector containing ints with information about the map.
    */
    //void setMapContent(std::vector<std::vector< int > > newMapLayout);
    /*!
    *   setMapObject sets a object at a given position.
    *   \brief Sets a spot at a given x and y position to the desired object.
    *   @param object is an int representing the desired object.
    *   @param x,y ints containg the x and y coordinates.
    */
    void setMapObject(int object, int y, int x);
    /*!
    *   setMapObject sets a object at a given position.
    *   \brief Sets a object at a given x and y position.
    *   @param object is an struct contianing x,y and id.
    */
    void setMapObject(Object obj);
    /*!
    *   getMapObject Gets the value of an object at a given position in the map.
    *   \brief Gets an object at the given x and y position and returns the value of this object.
    *   @param x,y are ints containing the x and y coordinates.
    *   @return returns an int containing the value of the found object return -1 if object not found.
    */
    int getMapObject(int y, int x);
    /*!
     * saveMap saves the map to a .map file.
     * \brief Saves all the content of a map to a .map file.
     * @param filename: the name of the saved file
    */
    void saveMap(std::string filename);
    /*!
     * savePcl saves the map to a .pcl file.
     * \brief Saves all the content of a map to a .pcl file.
     * @param filename: the name of the saved file
    */
    void savePcl(std::string filename);
    /*!
    remove a single point from the vector
    @param x: the x value of the point to be removed from the vector
    @param y: the y value of the point to be removed from the vector
    */
    void removePoint(int x, int y);
    //! remove a point from the vector
    /*!
    remove a single point from the vector
    @param obj: the point to be removed from the vector
    */
    void removePoint(Object obj);
    /*!
      * Default constructor of map.
      * \brief Default constructor of map, clearing memory etc.
    */
    ~Map();
    //! the filename
    std::string fileName;
    //! the width of the map from 1 to x
    int height;
    //! the width of the map from 1 to x
    int width;


private:
    //! The vector which contains all the data of the map by this template mapLayout[y][x].
    std::vector< Object > mapLayout;
    //! Creates a new map given a fileName.
    void createNewMap(std::string fileName);
    //! Loads the map with the given filename.
    void loadMap(std::string fileName);
};

#endif // MAP_H
