/**
* __
* _________ / /_ ____ ________ ____________ _____
* /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
* / / / /_/ / /_/ / /_/ / / / __(__ ) /__/ /_/ / __/
* /_/ \____/_.___/\____/_/ \___/____/\___/\__,_/\___/
*
*
* @file storage.h
* @date Created: 06/16/2015
* @brief A class that stores polygon shapes and square objects
*
* @author Jos Bijlenga
*
* @version 4.0
*
* @section LICENSE
* License: newBSD
*
* Copyright � 2015, HU University of Applied Sciences Utrecht.
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

#ifndef STORAGE_H
#define STORAGE_H

#include "polyobject.h"
#include <vector>
#include "square.h"

class storage
{
public:
    //! Constructor
    storage();

    //! Get all the polygon objects
    //! @return All polygon objects
    std::vector<polyObject> getPolyObjects();

    //! Get all the square objects
    //! @return All the square objects
    std::vector<square> getObjects();

    //! Add a polygon object to the storage
    //! @param The polygon object to be added to the storage
    void addPolyObject(polyObject obj);

    //! Add a square object to the storage
    //! @param The square object to be added to the storage
    void addObject(point p, int width, int height, char type);

    //! Delete a polygon object from the storage
    //! @param The polygon object to be deleted
    void deletePolyObject(polyObject p);

    //! Delete a square object from the storage
    //! @param The point of the square
    //! @param The width of the square
    //! @param The height of the square
    //! @param The type of the square object
    void deleteObject(point p, int width, int height, char type);

private:
    std::vector<polyObject> polyObjects;
    std::vector<square> objects;
};

#endif // STORAGE_H
