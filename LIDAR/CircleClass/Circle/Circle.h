#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	//! Position X of the circle in the map
	int originX;

	//! Position Y of the circle in the map
	int originY;

	//! Radius of the circle
	int radius;
	
	//! Data structure for origins
	/*!
		The data structure for the origins X and Y
	*/
	struct circleData {
		int originX;
		int originY;
		int radius;
	};

public:
	//! The Contructor for the Lidar
	/*!
		Initialize the Circle with origins X, Y and the radius
		@param originX: Set the position X of the circle in the map
		@param originY: Set the position Y of the circle in the map
		@param radius: Set the radius of the circle
	*/
	Circle(int originX, int originY, int radius);
	~Circle();

	//! Setter for the circle object
	/*!
		Set new values for the circle object
		@param x: Set new position x
		@param y: Set new position y
		@param r: Set new radius for circle
	*/
	void setCircle(int x, int y, int r);

	//! Getter for the circle object
	/*!
		Return requested data of circle object in a struct
		@return struct circleData: With the circle data (originX, originY,
															radius)
	*/
	circleData getCircle();

};

#endif // CIRCLE_H
