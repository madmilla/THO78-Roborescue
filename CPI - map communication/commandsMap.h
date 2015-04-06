//!  commands mapping team
//!  Made by ThijsvanTiem
/*!
    header file for commands between the CC and the mapping team
*/


#ifndef COMMANDSMAP_H_
#define COMMANDSMAP_H_

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#elif __linux__
#define DLLEXPORT
#else
#define DLLEXPORT
#endif


#include <iostream>
#include <vector>

class DLLEXPORT CommandsMap {
public:
    //! singleton class
    CommandsMap & getInstance();

    virtual ~CommandsMap();

    //! get the line from the mapping team and returns a vector with
    //!lines that cross  (x,y)
    std::vector<int> getline(int x,int y);

    //! returns a vector of lines that will show the total map
    std::vector<int> getMapTotal();

    //! get the location of the device in x and y
    //! int device tells which device it is
    //! 1=Quad 2=Atv 3=Rosbee
    std::vector<int> getLocation(int x,int y,int device)

    //! send an x and y axis for point 1 and point 2 to make the line.
    //! when all data has been recieved a true boolean value will be returned otherwise it will return a false
    bool setLine(int x,int y, int x1, int y1);

    //! send the location of the device in x and y
    //! int device tells which device it is
    //! 1=Quad 2=Atv 3=Rosbee
    bool setLocation(int x,int y, int device);

    //! return the map in a certain range
    void getMapInRange(int x,int y,int height,int width);





private:
    CommandsMap();

};

#endif /* COMMANDSMAP_H_ */
