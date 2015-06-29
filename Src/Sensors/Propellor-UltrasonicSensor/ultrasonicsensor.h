/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file UltrasonicSensor.h
* @date Created: 25-4-2015
* @version 2.1
*
* @author Edwin Koek
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

#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

/**
 * @brief The UltraSonicSensor class
 * This class creates objects that can be used to read data from a ultrasonic sensor.
 */
class UltraSonicSensor{
public:
   /**
   * @brief UltraSonicSensor constructor
   * @param pin The pin that wil communicate with an ultrasonic sensor.
   */
  UltraSonicSensor(int pin);

  /**
   * @brief getDistance
   * getDistance calculates and returns a distance based on the reading of an ultrasonic sensor.
   * More explanation on how the distance is calculated can be found on the roborescue wiki page.
   * @return Distance in centimeters. The reading wil be seen as invalid and return -1 if the
   * calculated distance is not between 2 and 330 centimeters.
   */
  int getDistance();
  
  /**
   * @brief setTemperature
   * setTemperature sets the temperature that is used by the distance calculations to the
   * temperature that is passed to the function. The temperature is in Celcius.
   * @param temp Temperature in Celcius
   */
  void setTemperature(float temp);
  
private:
  //! The pin on the propeller that communicates with the sensor.
  int pin;
  //! The temperature that is used in the distance calculations.
  float temperature;
};

#endif  
