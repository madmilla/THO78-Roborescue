#pragma once

#include <iostream>

class points
{
public:
    //! Constructor of the point
    //! @param The X-value of the point
    //! @param The Y-value of the point
    points(int mX, int mY);
    ~points();

    //! Allows the point to be printed to the output stream
    //! @param The standard output stream
    //! @param The point to be printed
    //! @return A standard output stream
    friend std::ostream & operator<<(std::ostream & os, const points & p);

    //friend bool operator==(const point & lhs, const point & rhs);

    //! Compares the current point object with the point parameter
    //! @param The point to compare with
    //! @return The result of the comparison. True if equal, otherwise false.
    bool equals(const points & p);

    //! Get the X-value of the point
    //! @return The X-Value of the point
    int getX() const;

    //! Get the Y-value of the point
    //! @return The Y-Value of the point
    int getY() const;

private:
    int x, y;
};
