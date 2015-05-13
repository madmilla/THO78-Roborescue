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

#include <QVector>
#include <QTableWidget>
#include "simulatemap.h"

using namespace std;

class Map
{
public:
    /*!
    *   Map constructor with a given file.
    *   \brief Given a filename this constructor will read and convert a .map file to a map object.
    *   @param fileName the name of a .map file containing map information.
    */
    Map(string fileName);
    /*!
    *   Map constructor with given file, height and width.
    *   \brief This constructor is used for making a new map with a standard height & width.
    *   @param fileName the name of a .map file containing map information
    *   @param height the height of the map
    *   @param width the width of the map
    */
    Map(string fileName, int height, int width);
    /*!
    *   getMapContent gets all the information of a map.
    *   \brief This function gets and returns all information of a map object in a 2D-vector.
    *   @return std::vector<vector< int > > a 2D-vector containing all the map information.
    */
    vector<vector< int > > getMapContent();
    /*!
    *   setMapContent is used to set a map to the content of a given 2D-vector.
    *   \brief Sets al the data in the map to the data in a given 2D-vector containing ints.
    *   @param newMapLayout is a 2D-Vector containing ints with information about the map.
    */
    void setMapContent(vector<vector< int > > newMapLayout);
    /*!
    *   setMapObject sets a object at a given position.
    *   \brief Sets a spot at a given x and y position to the desired object.
    *   @param object is an int representing the desired object.
    *   @param x,y ints containg the x and y coordinates.
    */
    void setMapObject(int object, int y, int x);
    /*!
    *   getMapObject Gets the value of an object at a given position in the map.
    *   \brief Gets an object at the given x and y position and returns the value of this object.
    *   @param x,y are ints containing the x and y coordinates.
    *   @return returns an int containing the value of the found object return -1 if object not found.
    */
    int getMapObject(int y, int x);
    /*!
     * saveMap saves the map to a file.
     * \brief Saves all the content of a map to a .map file.
    */
    void saveMap();
    /*!
      * Default constructor of map.
      * \brief Default constructor of map, clearing memory etc.
    */
    ~Map();
    //! the filename
    string fileName;
    //! the width of the map from 1 to x
    int height;
    //! the width of the map from 1 to x
    int width;


private:
    //! The vector which contains all the data of the map by this template mapLayout[y][x].
    vector<vector< int > > mapLayout;
    //! Creates a new map given a fileName.
    void createNewMap(string fileName);
    //! Loads the map with the given filename.
    void loadMap(string fileName);
};

#endif // MAP_H
