/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file Rosbee.cpp
* @date Created: 16-3-2015
* @version 2.0
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

#include <simpletools.h>
#include "Qik.h"
#include "ultrasonicsensor.h"
#include "Encoder.h"
#include "ParallaxPropellerProtocol.h"
#include "Uart.h"

/// Entry point of application.
int main(){
  //Pin connected to the rx pin of the Qik motor controller.
  int qTx = 25;
  //Pin connected to the tx pin of the Qik motor controller.
  int qRx = 26;
  //Baud rate used to communicate with the Qik motor controller.
  int qBaud = 115200;
  
  //Pin connected to the photointerrupter of the encoder on the left motor.
  int ePin1 = 10;
  //Pin connected to the photointerrupter of the encoder on the right motor.
  int ePin2 = 11;
  
  //Pin connected to the ultrasonic sensor at the front of the rosbee on the left side.
  int ussPin1 = 5;
  //Pin connected to the ultrasonic sensor at the front of the rosbee in the middle.
  int ussPin2 = 6;
  //Pin connected to the ultrasonic sensor at the front of the rosbee on the right side.
  int ussPin3 = 7;
  //Pin connected to the ultrasonic sensor at the back of the rosbee on the left side.
  int ussPin4 = 8;
  //Pin connected to the ultrasonic sensor at the back of the rosbee on the right side.
  int ussPin5 = 4;
  //Pin connected to the ultrasonic sensor at the back of hte rosbee int the middle.
  int ussPin6 = 9;
  
  //If you wish to send debug information to the console you need to make the propeller wait a sec.
  //The propeller is faster then the startup of the console. This will result in data being missed. 
  //Uncomment while debugging.
  //sleep(1);
  
  //Uart object for communication.
  Uart uart;
  //Qik object for motor control.
  Qik qik{qTx,qRx,qBaud};
  //Stop  motor 1.
  //This is done so the rosbee won't drive away and/or stop while the 
  //program is rebooted.
  qik.setMotorSpeed(Qik::Motor::M0,0);
 
  //Stop  motor 2.
  //This is done so the rosbee won't drive away and/or stop while the 
  //program is rebooted.
  qik.setMotorSpeed(Qik::Motor::M1,0);
  
  //Encoder object for the left motor.
  Encoder enc1{ePin1};
  //Encoder object fot the right motor.
  Encoder enc2{ePin2};
  
  //Ultrasonic sensor object for the sensor front left. 
  UltraSonicSensor uss1(ussPin1);
  //Ultrasonic sensor object for the sensor front middle.
  UltraSonicSensor uss2(ussPin2);
  //Ultrasonic sensor object for the sensor front right.
  UltraSonicSensor uss3(ussPin3);
  //Ultrasonic sensor object for the sensor back left.
  UltraSonicSensor uss4(ussPin4);
  //Ultrasonic sensor object for the sensor front right.
  UltraSonicSensor uss5(ussPin5);
  
  //Variables used for communcation.
  //cmd = command byte received.
  //value = follow byte received.
  //rtn = byte to be send.
  //intRtn = int(4 bytes) to be send.
  //speed = motor speed (can be negative).
  char cmd, value, rtn;
  int intRtn;
  signed char speed;
  
  //Run forever.
  //The rosbee is expected to work as long as it has power.
  //Therefore  this loop never needs to end.
  while(true){
    //Get the command byte.
    //This will block if no byte is available.
    cmd = uart.readChar();
    
    //Check which command to execute.
    //This is just a epic long switch case.
    //There was honestly no better way to do this that does
    //not require making infinite classes.
    switch(cmd){
      //Motors
      //Commands regarding the motor controllers.
      case PPP::SET_SPEED_M0:
        speed = uart.readChar();
        qik.setMotorSpeed(Qik::Motor::M0,speed);
        break;
      case PPP::SET_SPEED_M1:
        speed = uart.readChar();
        qik.setMotorSpeed(Qik::Motor::M1,speed);
        break;
      case PPP::SET_BRAKE_SPEED_M0:
        value = uart.readChar();
        qik.setBrakePower(Qik::Motor::M0,value);
        break;
      case PPP::SET_BRAKE_SPEED_M1:
        value = uart.readChar();
        qik.setBrakePower(Qik::Motor::M1,value);
        break;
      case PPP::GET_FIRMWARE_VERSION:
        rtn = static_cast<char>(qik.getFirmwareVersion());
        uart.send(rtn);
        break;
      case PPP::GET_ERROR:
        rtn = static_cast<char>(qik.getError());
        uart.send(rtn);
        break;
        
      //Encoders
      //Commands regarding the encoders.
      case PPP::GET_PULSE_COUNT_M0:
        intRtn = enc1.getPulseCount();
        uart.send(intRtn);
        break;
      case PPP::GET_PULSE_COUNT_M1:
        intRtn = enc2.getPulseCount();
        uart.send(intRtn);
        break;
      case PPP::GET_PULSE_SPEED_M0:
        rtn = enc1.getSpeed();
        uart.send(rtn);
        break;
      case PPP::GET_PULSE_SPEED_M1:
        rtn = enc2.getSpeed();
        uart.send(rtn);
        break;  
        
      //Ultrasonic Sensors
      //Commands regarding the ultrasonic sensors.
      case PPP::GET_DISTANCE_S0:
        intRtn = uss1.getDistance();
        uart.send(intRtn);
        break;
      case PPP::GET_DISTANCE_S1:
        intRtn = uss2.getDistance();
        uart.send(intRtn);
        break;
      case PPP::GET_DISTANCE_S2:
        intRtn = uss3.getDistance();
        uart.send(intRtn);
        break;
      case PPP::GET_DISTANCE_S3:
        intRtn = uss4.getDistance();
        uart.send(intRtn);
        break;
      case PPP::GET_DISTANCE_S4:
        intRtn = uss5.getDistance();
        uart.send(intRtn);
        break;
      case PPP::GET_DISTANCE_S5:
        intRtn = 0;
        uart.send(intRtn);
        break;
      
      //Debug
      //Commands regarding debugging.
      case 'i':
        break;
      
    } // End switch.             
  } // End while.
  //The program should never come here, but it's required by the compiler.
  return 0;
}  