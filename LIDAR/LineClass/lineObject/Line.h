#ifndef LINE_H
#define LINE_H

//! Data structure for origins
/*!
The data structure for the origins X and Y
*/
struct Point {
	int x;
	int y;
};

class Line
{
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
};
#endif

