/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Uart.cpp
* @date Created: 13-5-2015
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

#include "Uart.h"
#include <simpletools.h>
#include "Channel.h"

Uart::Uart(){
  //Claim a cog.
  cogId = cogstart(&Uart::readBuffer, this, stack,  sizeof(stack)); 
}  

Uart::~Uart(){
  //Free the cog.
  cogstop(cogId); 
}

void Uart::readBuffer(void* obj){
  //Convert the obj to a Uart object.
  //Since the obj was originally a Uart obj this is legal.
  Uart* enc = reinterpret_cast<Uart*>(obj);
  //Run forever
  while(true){
    //Read the next incoming character and put it in the buffer.
    //getchar() will block if there is nothing to read.
    enc->readChannel.write(getchar());
  }     
}

char Uart::readChar(){
  //Read and return the next character from the buffer.
  return readChannel.read();  
}   
  
int Uart::readInt(){
  //The four character we're going to read and convert into a int.
  char intChar[4];
  //Read the four characters.
  for(int i =0; i<4; ++i){
     intChar[i] = readChannel.read();  
  }    
  //Cast the four read chars to a int.
  //This is faster and easier than bit shifting.
  int data = *(reinterpret_cast<int*>(intChar));
  //Return the int.
  return data;   
}

 void Uart::send(char data){
  //Send the character.
  putChar(data);
 }   
  
 void Uart::send(int data){
  //Cast the int to four chars.
  //This is faster and easier the bit shifting and copying.
  char *intChar = reinterpret_cast<char*>(&data);
  //Send all four bytes.
  for(int i =0; i<4; ++i){
     putChar(intChar[i]); 
  }
 }
      