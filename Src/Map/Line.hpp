/**
*                __
*    _________  / /_  ____  ________  ____________  _____
*   / ___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / /  / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/   \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file line.hpp
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

#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Point.hpp"

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
