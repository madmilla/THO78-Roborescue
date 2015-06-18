//!  commands mapping team
//!  Made by ThijsvanTiem Tom Verloop
/*!
    header file for commands between the CC and the mapping team
*/


#ifndef COMMANDSMAP_H_
#define COMMANDSMAP_H_



#include <iostream>
#include <vector>

class CommandsMap {
public:
    //! singleton class
    CommandsMap & getInstance();

    virtual ~CommandsMap();

    //! get the line from the mapping team and returns a vector with
    //!lines that cross  (x,y)
    Line getline(int x,int y);

    //! returns a vector of lines that will show the total map
    const vector<Line> & getMapTotal();

    //! get the location of the device in x and y
    //! int deviceType tells which device it is
    //! 1=Quad 2=Atv 3=Rosbee
	//! int deviceId tells which robot it is in case of multiple the same 
	//! robot.
    const point & getLocation(int deviceType,int deviceId)

    //! send an x and y axis for point 1 and point 2 to make the line.
    //! when all data has been recieved a true boolean value will be returned 
	//! otherwise it will return a false
    bool setLine(int x,int y, int x1, int y1);

    //! send the location of the device in x and y
    //! int deviceType tells which device it is
    //! 1=Quad 2=Atv 3=Rosbee
	//! int deviceId tells which robot it is in case of multiple the same 
	//! robot.
    bool setLocation(int x,int y, int deviceType,int deviceId);

    //! return the map in a certain range
    void getMapInRange(int x,int y,int height,int width);





private:
    CommandsMap();

};

#endif /* COMMANDSMAP_H_ */
