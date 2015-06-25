/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Values.h
* @date Created: 22-04-2015
* @version 1.0
*
* @author Danny Horvath, Thomas Fink
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
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

#ifndef VALUES
#define VALUES
class Values
{
public:
    const static int LIDAR = 3;
    const static int CHECKPOINT = 2;
    const static int OBSTACLE = 1;
    const static int LINE = 4;
    const static int RECTANGLE = 5;
    const static int CIRCLE = 6;
    const static int EMPTY = 0;
    const static int DRAWWIDTH = 1920;
    const static int DRAWHEIGHT = 1080;
    const static int SCANRADIUS = 10;
    const static int NOISETHRESHOLD = 35;
    const static char EDIT = 0;
    const static char SIMULATE = 1;

    const static int FILEEXCEPTION = 1;
    const static int CONTENTEXCEPTION = 2;

    //! Int containing the new map begin size.
    static const int newMapBeignSize = 100;
    //! Int containing minimal map size.
    static const int newMapMinSize = 10;
    //! Int containing maximal map size.
    static const int newMapMaxSize = 4000;
    //! Int containing the map step size.
    static const int newMapStepSize = 10;
    //! Int containing the new map begin size.
    static const int SCALETHRESHHOLD {500};
};
#endif // VALUES

