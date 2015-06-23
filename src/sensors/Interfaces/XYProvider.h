class XYProvider{
public:
	/**
	* Returns the X in the room according to this XYProvider.
	*
	* @return the X in the room.
	*/
	double getX();
	
	/**
	* Returns the Y in the room according to this XYProvider..
	*
	* @return the Y in the room.
	*/
	double getY();
	
	/**
	* @brief Sets the absolute position.
	*
	* This function is used to set the absolute position. The XYProvider will use this position to calculate the future positions. This function has to be called regularly to prevent value drift.
	*
	*@param x is the absolute x in the room.
	*@param y is the absolute y in the room.
	*/
	void calibrate(double x, double y);
	
	/**
	* @brief Sets the absolute X.
	*
	* This function is used to set the absolute X. The XYProvider will use this position to calculate the future positions. This function has to be called regularly to prevent value drift.
	*
	*@param x is the absolute x in the room.
	*/
	void calibrateX(double x);
	
	/**
	* @brief Sets the absolute Y.
	*
	* This function is used to set the absolute Y. The XYProvider will use this position to calculate the future positions. This function has to be called regularly to prevent value drift.
	*
	*@param y is the absolute y in the room.
	*/
	void calibrateY(double y);
protected:
	double x,y;
};