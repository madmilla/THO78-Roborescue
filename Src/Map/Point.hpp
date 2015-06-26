/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file point.hpp
* @date Created: 06/24/2015
* @brief A class that contains the Map and has the functions for adding objects to the Map
*
* @author Jos Bijlenga, Jasper Stas
*
* @version 1.0
*
* @section LICENSE
* License: newBSD
*
* Copyright   2015, HU University of Applied Sciences Utrecht.
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
**/

#ifndef POINT_H
#define POINT_H

#include <iostream>

class point {
public:
    //! Constructor of the point
    //! @param The X-value of the point
    //! @param The Y-value of the point
    point ( int mX, int mY );
    ~point();

    //! Allows the point to be printed to the output stream
    //! @param The standard output stream
    //! @param The point to be printed
    //! @return A standard output stream
    friend std::ostream& operator<< ( std::ostream& os, const point& p );

    //friend bool operator==(const point & lhs, const point & rhs);

    //! Compares the current point object with the point parameter
    //! @param The point to compare with
    //! @return The result of the comparison. True if equal, otherwise false.
    bool equals ( const point& p );

    //! Get the X-value of the point
    //! @return The X-Value of the point
    int getX() const;

    //! Get the Y-value of the point
    //! @return The Y-Value of the point
    int getY() const;

private:
    int x, y;
};

#endif
