#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include <vector>
#include <stdlib.h>
#include <ostream>
#include "iostream"
//! The pointcloud object
/*!
The object which will contain all the points of a scan
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

	//OPERATORS

	//! a operator to write a point struct to a ostream
	friend std::ostream & operator<<(std::ostream & output, const Pointcloud::Point & s);
	//! a operator to add a Pointcloud to another pointcloud
	Pointcloud operator+(Pointcloud &  b);
	//! a operator to add a Pointcloud to another pointcloud
	Pointcloud operator+=(Pointcloud & b);
private:
	std::vector<Point> pointCloud; //! the vector which contains all the poins of the pointcloud
	int orientation; //! the orientation of the pointcloud
};
#endif 
