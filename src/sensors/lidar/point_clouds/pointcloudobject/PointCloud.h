
/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file PointCloud.h
* @date Created: 22-04-15
*
* @version 1.1
* @author Tijmen Bruggeman
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


#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include <vector>
#include <stdlib.h>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
//! The pointcloud object
/*!
The object which will contain all the points of a scan
@author Tijmen Bruggeman
*/
class Pointcloud{ //! a struct which will contain a single point
public:
	//!The Contructor for the pointcloud
	Pointcloud();
	//! A object which will contain a single point
	struct Point{
		int X; //! The x value of a single point
		int Y; //! the Y-value of a single point
	};
	//! Set a point in the pointcloud
	/*!
	Add a single point to the pointcloud
	@param point: the point object which will be added to the pointcloud
	*/
	void setPoint(Point point);
	//! Set a point in the pointcloud
	/*!
	Add a single point to the pointcloud
	@param x: the x value of the point to be added to the pointcloud
	@param y: the y value of the point to be added to the pointcloud
	*/
	void setPoint(int x, int y);
	//! get all the points of the pointcloud
	/*!
	get all the points of a pointcloud returned in a vector
	@return std::vector<point>: the vector which will contain all the points of the pointcloud

	*/
	std::vector<Point> getPoints();
	//! remove a point from the pointcloud
	/*!
	remove a single point from the pointcloud
	@param x: the x value of the point to be removed from the pointcloud
	@param y: the y value of the point to be removed from the pointcloud
	*/
	void removePoint(Point p);
	//! remove a point from the pointcloud
	/*!
	remove a single point from the pointcloud
	@param p: the point to be removed from the pointcloud
	*/
	void removePoint(int x, int y);
	//! get the width of the pointcloud
	/*!
	get the max width of the poincloud, this equals the max negative value + the max positive value
	@return int: the integer with the max width

	*/
	int getCloudWidth();
	//! get the height of the pointcloud
	/*!
	get the max height of the poincloud, this equals the max negative value + the max positive value
	@return int: the integer with the max height

	*/
	int getCloudHeight();

	//! set the orientation of the poincloud
	/*!
	set the orientation of the poincloud
	@param int: the integer with the orientation in degrees
	*/
	void setOrientation(int degrees);
	//! get the orientation of the pointcloud
	/*!
	get the orientation of the pointcloud in degrees
	@return int: the integer with the orientation of the pointcloud in degrees

	*/
	int getOrientation();
	//! set the offset of the pointcloud
	/*!
	set the ofsset of the pointcloud according to the 0.0 point
	@param Point: the point with x and y to be set as offset
	*/
	void setOffset(Point newOffset);
	//! get the offset of the pointcloud
	/*!
	get the ofsset of the pointcloud according to the 0.0 point
	@return Point: returns a point with X and Y value
	*/
	Point getOffset();

	//! save all the points to a file
	/*!
	Save all the points tot a file, the offset and the orientation to a file
	@param filename: the filename of the file where the points will be written
	*/
    void savePointsToFile(std::string filename);
	//! load all the points from a file
	/*!
	load all the points, the offset and the orientation from a file
	@param filename: the filename of the file with the points.
	*/
    void loadPointsFromFile(std::string filename);

    //! print all points in given cloud    
	void printPoints();
	//OPERATORS

	//! a operator to write a point struct to a ostream
	friend std::ostream & operator<<(std::ostream & output, const Pointcloud::Point & s);
	//! a operator to add a Pointcloud to another pointcloud
	Pointcloud operator+(Pointcloud &  b);
	//! a operator to add a Pointcloud to another pointcloud
	Pointcloud operator+=(Pointcloud & b);
private:
	Point offset;
	std::vector<Point> pointCloud; //! the vector which contains all the poins of the pointcloud
	int orientation; //! the orientation of the pointcloud
};
#endif 
