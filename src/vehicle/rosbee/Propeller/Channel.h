/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Channel.h
* @date Created: 16-4-2015
* @version 1.0
*
* @author Nathan Schaaphuizen
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

#ifndef _CHANNEL_H
#define _CHANNEL_H

/// @brief Class for passing data synchronously between cogs.
///
/// The Channel is a class to pass data synchronously between cogs.
/// It has a fixed size. The channel makes use of the FIFO principle.
template <typename T, int S>
class Channel{
private:
    T buffer[S];
    volatile int index;
public:

    /// @brief Creates new channel object.
    Channel():
      index{0}
    {}
    
    /// @brief Write data in channel.
    ///
    /// This function will block if channel is  full.
    void write(T t) volatile{
      //Spinlock the cog if channel is full.
      //We can't write in a full channel.
      while(index >= S);
      //Write new data in buffer and up the buffer index.   
      buffer[index++] = t;
    }

  
    /// @brief Read data from the channel.
    ///
    /// This function will block if channel is empty.
    T read() volatile{
      //Spinlock the cog if channel is empty.
      //we can't read from a empty channel.
      while(index <= 0);
      //Temporary item that we're going to return later.
      T tmp = buffer[0];
      //Lower the buffer index.
      index--;
      //Copy all data one to the left.
      //This array will go out of bounds. 
      //But that's ok, it will fill the channel with we junk data
      //that will be overwritten by the next write().
      for(int i=0;i<S;++i){
        //Copy one component to the left.
        buffer[i] = buffer[i+1];  
      }      
      //Return the item we saved before. 
      return tmp;  
    } 

};

#endif // _CHANNEL_H  