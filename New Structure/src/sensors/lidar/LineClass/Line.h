/*!
* \brief Class containing line objects.
* \details This class is used to store found lines in.
* \author Patrick Schoonheym - 1639598
* \version 1.0
* \date 22-04-2015
*/

#ifndef LINE_H
#define LINE_H

#include <iostream>

class Line
{
public:	
	//! Data structure for origins
	/*!
	The data structure for the origins X and Y
	*/
	struct Point {
		int x;
		int y;
	};
private:
	//! Data structure for the line coordinates
	/*!
	The data structure for the origins X and Y
	*/
	struct LineData {
		Point begin_pos;
		Point end_pos;
	};
	LineData lineData;

public:
	//! The Contructor for the Lidar
	/*!
	Initialize the line with the struct Point begin position and the struct Point end position
	@param begin_pos: set the begin position of the line 
	@param end_pos: Set the end position of the line
	*/
	Line(const Point & begin_pos, const Point & end_pos);
	~Line();
	
	//! The setter for the line object
	/*!
	set new values for the line object
	@param begin_pos: set the new begin position of the line
	@param end_pos: set the new end position of the line 
	*/
	void setLine(const Point & begin_pos, const Point & end_pos);
	//! The getter for the line object
	/*!
	get the values of the line object
	@return struct lineData: With the line data (struct Point begin_pos, struct Point end_pos)
	*/
	LineData& getLine();

	//! operator for printing points
	/*!
	print a specifiek point to the console
	*/
	friend std::ostream& operator<<(std::ostream & stream, const Point & point);
	//! operator for printing all line information
	/*!
	print all the line information to the console
	*/
	friend std::ostream& operator<<(std::ostream & stream, const Line & line);
	//! operator for checking if 2 Points are the same
	/*!
	check if 2 Points are the same
	*/
	friend bool operator==(const Point & p1, const Point & p2);
};
#endif

