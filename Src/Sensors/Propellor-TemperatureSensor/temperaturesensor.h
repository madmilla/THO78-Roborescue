/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file TemperatureSensor.h
* @date Created: 25-4-2015
* @version 1.3
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

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

/**
 * @brief The TemperatureSensor class
 * This class creates objects that can be used to convert
 * ADC readings from the LM335 temperature sensor into degrees celcius.
 */
class TemperatureSensor{
public:

  /**
   * @brief TemperatureSensor constructor
   */
  TemperatureSensor();
  
  /**
   * @brief getTemperatureC
   *
   * getTemperatureC returns a temperature in Celcius based on values
   * from a Sigma-Delta conversion. Further explanation on how the function calculates
   * the temperature can be found on the roborescue wiki page.
   * @param ADCReading The reading that the ADC returns
   * @param ADCMaxValue The maximum reading that the ADC can give
   * @param ADCMinValue The minimum reading that the ADC gives. This is needed for calibration purposes.
   * @return This function returns a temperature in Celcius based on an ADCReading
   * that is passed to the function. If the function returns -1 the reading is invalid
   */
  float getTemperatureC(
      float ADCReading,
      float ADCMaxValue, 
      float ADCMinValue = 0);

  /**
   * @brief getTemperatureC
   * getTemperatureC returns a temperature in Celcius based on given voltage.
   * further explanation on how the temperature is calculated can be found
   * on the roborescue wiki page.
   * @param volt - the voltage that is to be converted to a temperature
   * @return This function returns a temperature in Celcius based on the voltage
   * that is passed to the function. If the function returns -1 then an invalid
   * voltage has been given.
   */
  float getTemperatureC(float volt);
  
  /**
   * @brief getTemperatureK
   * getTemperatureK returns a temperature in Kelvin based on values
   * from a Sigma-Delta conversion. Further explanation on how the function calculates
   * the temperature can be found on the roborescue wiki page.
   * @param ADCReading The reading that the ADC returns
   * @param ADCMaxValue The maximum reading that the ADC can give
   * @param ADCMinValue The minimum reading that the ADC gives. This is needed for calibration purposes.
   * @return This function returns a temperature in Kelvin based on an ADCReading
   * that is passed to the function. If the function returns -1 the reading is invalid
   */
  float getTemperatureK(
      float ADCReading,
      float ADCMaxValue, 
      float ADCMinValue = 0);
      
  /**
   * @brief getTemperatureK
   * getTemperatureK returns a temperature in Kelvin based on given voltage.
   * further explanation on how the temperature is calculated can be found
   * on the roborescue wiki page.
   * @param volt - the voltage that is to be converted to a temperature
   * @return This function returns a temperature in Kelvin based on the voltage
   * that is passed to the function. If the function returns -1 then an invalid
   * voltage has been given.
   */
  float getTemperatureK(float volt);
  
};
  

#endif
