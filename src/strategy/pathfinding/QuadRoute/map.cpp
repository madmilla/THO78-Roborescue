/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file map.cpp
* @date Created: 4/7/2015
*
* @author Jasper Stas
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

#include "map.h"
#include <iostream>
#include <fstream>

/**
 * Basic constructor, creates a clear map.
 * */
Map::Map()
{
    for(int x = 0; x < MAP_WIDTH; x++){
        for (int y = 0; y < MAP_HEIGHT; y++){
            objectMatrix[x][y] = 0;
        }
    }
}

/**
 * Basic deconstructor.
 * */
Map::~Map()
{

}

/**
 * This method returns the value of a point on the map.
 * */
int Map::get(int x, int y)
{
    return objectMatrix[x][y];
}

/**
 * This method sets the value of a point on the map.
 * */
void Map::set(int x, int y, int value)
{
    objectMatrix[x][y] = value;
}

/**
 * This method returns a map loaded from a existing file.
 * */
Map * Map::loadFromFile(const char * filename)
{
    Map * map = new Map();
    std::ifstream is(filename);
    char c;
    int x = 0, y = 0;
    while(is.get(c)){
        if(c == CHAR_FREE){
            map->set(x, y, 0);
        }
        else if(c == CHAR_BLOCK){
            map->set(x, y, 1);
        }
        else if(c == CHAR_QUAD){
            map->set(x, y, 2);
        }
        else if(c == CHAR_FINISH){
            map->set(x, y, 0);
        }
        else if(c == CHAR_ROUTE){
            map->set(x, y, 0);
        }
        else{
            x -= 1;
        }
        x+=1;
        if(x >= MAP_WIDTH){
            y += 1;
            x = 0;
        }
        if(y >= MAP_HEIGHT){
            break;
        }
    }
    is.close();
    map->setFinish();
    return map;
}

typedef int (*pointer_to_arrays)[20];

/**
 * This method returns the objectMatrix, this are the values of the map.
 * */
pointer_to_arrays Map::getObjectMatrix(){
    return objectMatrix;
}

/**
 * This method saves the map to a file.
 * */
void Map::saveToFile(const char * filename)
{
    std::ofstream os(filename, std::ofstream::out);
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
           if(get(x, y) == FREE){
               os << CHAR_FREE;
           }
           else if(get(x, y) == BLOCK){
               os << CHAR_BLOCK;
           }
           else if(get(x, y) == QUAD){
               os << CHAR_QUAD;
           }
           else if(get(x, y) == FINISH){
               os << CHAR_FINISH;
           }
           else if(get(x, y) == ROUTE){
               os << CHAR_ROUTE;
           }
        }
        os << '\n';
    }
    os.close();
}

/**
 * This method sets a random finish on the map, for testing perposes.
 * */
void Map::setFinish(){
    srand (time(NULL));
    int randomMatrixPointX = rand() % MAP_WIDTH;
    int randomMatrixPointY = rand() % MAP_HEIGHT;

    while(objectMatrix[randomMatrixPointX][randomMatrixPointY]!=FREE){
        randomMatrixPointX = rand() % MAP_WIDTH;
        randomMatrixPointY = rand() % MAP_HEIGHT;
    }
    objectMatrix[randomMatrixPointX][randomMatrixPointY] = FINISH;
    set(randomMatrixPointX, randomMatrixPointY, FINISH);
    /**/
    //set(6,14,FINISH);
}
