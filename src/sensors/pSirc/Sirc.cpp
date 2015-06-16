/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Sirc.cpp
* @date Created: 28-4-2015
* @version 1.1
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

#include "Sirc.h"
#include <simpletools.h>

Sirc::Sirc(int inputPin):
pin{inputPin},
timeout{0}    //Timeout disabled by default.
{}

int Sirc::getPulseWidth(){
   //Var we are using to count time.
   int count = 0;
   //Wait for incoming signal
   //Start waiting for the pin to get low.
   //This indicates the start of a transmission.
   while(true){
      //Check if the pin is low.
      if(input(pin) == 0){
        //Get out of the loop.
        break; 
      }
      //Increase the counter.
      //Each tick is 100 microseconds.        
      count++;
      //Check if the timeout is enabled.
      //Check if we need to time out already.
      if(timeout > 0 && count >= (timeout*10)){
        //Return the timeout value (-1).
        return TIMEOUT;  
      }
      //Wait for 100 microseconds.         
      waitcnt(CNT+100*us);  
   }  
   //Reset the counter.
   //We are going to use it to count the pulse width now.
   count = 0;
   //Run until the pin becomes high again.
   while(input(pin) == 0){
    //Increase the counter.
    //Each tick represents 100 us.
    count++;
    //Wait for 100 microseconds.  
    waitcnt(CNT+100*us);   
   }
   //Return the counted value.    
   return count; 
}  

int Sirc::getRawCode(){
  //Start with a empty sirc code.
  int sircCode = 0;    
  //Wait for start burst.
  //The start burst is +- 2400 us. 
  while(true){
    //Get the pulse width.
    int pulse = getPulseWidth();
    //Check if getting the pulse width has timed out.
    if(pulse == TIMEOUT){
      //Return the timeout value (-1).
      return TIMEOUT; 
    }
    //Check if the pulse width is the start burst. 
    //Due to background interference the start burst is not exactly 2400 us.
    //The length can swing in both directions.
    //To correct this error we also accept a burst of length 2300 us and anything higer.
    if (pulse >=23){
      //Get out of the loop.
      break;  
    }            
  } 
  //Read the next 12 bits.
  for(int i=0;i<12;++i){
      //We get the new pulse width.
      //We just assume at this point it will not longer time out.
      int pulse = getPulseWidth();  
      //We check if the pulse width is longer then 800 us.
      //0 = 600 us
      //1 = 1200 us
      //We have the same problem with background interference here.
      //So we ccept anything equal and below 800 us as a 0 and anthing above as a 1. 
      if(pulse > 8){
         //Write a 1 on the first bit.
         //Leave the other bits untouched.
         sircCode |= 0x01; 
      }
      //Shift the bits to the left.
      sircCode <<= 1;                                    
  }
  //We have shifted one to may times to the left in the above loop.
  //To fix this we shift all the bits back to the right.
  sircCode >>= 1;
  //Return the sirc code.
  return sircCode;
}

bool Sirc::getCode(int *command, int *address){
  //Get the raw code.
  int sircCode =  getRawCode();
  //Check if getting the raw code has timed out.  
  if( sircCode == TIMEOUT){
    //Return false indicating that we timed out.
    return false;
  }      
  //Var we are using to parse the codes.   
  int code = 0;
  //We first parse the 7 bits command code (key code).
  for(int i=0;i<7;++i){
    //The code is stored LSB so we have to read it from back to front.
    //We start with the last 12th bit and read back to the 6th.
    //Check if bit on position x is 1.
    if(sircCode & (0x01 << (11-i))){
      //Write a 1 on position y.
      //We write from the front to back here. So we place the correct bit at the correct place.
      code |= (0x01 << i);
    }                    
  }
  //Save the command code.
  *command = code;
  //Reset the var, we are going to use it again. 
  code = 0;
  //Next we read the 5 bits address code (device code).
  for(int i=0;i<5;++i){
    //This is the same idea as reading the command code.
    //We only this time we start at the 5th bit and read back to the 1st.
    //Check if bit on position x is 1.
    if(sircCode & (0x01 << (4-i))){
       //Write a 1 on position y.
       //We write from the front to back here. So we place the correct bit at the correct place.
       code |= (0x01 << i);
    }                    
  }
  //Save the address code.
  *address = code;
  //Return true indicating that everything went well.     
  return true;
}

void Sirc::setTimeout(int ms){
  //Set a new timeout value.
  timeout = ms;  
}    