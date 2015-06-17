#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "point.hpp"

class line
{
public:
    //! Constructor of the line
    //! @param The starting point of the line
    //! @param The ending point of the line
    line(point mP1, point mP2);
    ~line();

    //! Allows the line to be printed to the output stream
    //! @param The standard output stream
    //! @param The line to be printed
    //! @return A standard output stream
    friend std::ostream & operator<<(std::ostream & os, const line & l);

    //friend bool operator==(const line & lhs, const line & rhs);

    //! Compares the current line object with the line parameter
    //! @param The line to compare with
    //! @return The result of the comparison. True if equal, otherwise false.
    bool equals(const line & l);

    //! Returns starting or ending point of the line
    //! @param The starting point (0) or the ending point (1)
    //! @return Returns the ending point when parameter is 0, otherwise return starting point
    point getPoint(int n);

    //! Return both starting point and ending point as pair of the line object
    //! @return A pair of the starting and ending point
    std::pair<point, point> getPoints();

private:
    point p1{ 0, 0 };	//The starting point of the line
    point p2{ 0, 0 };	//The ending point of the line
};

#endif
