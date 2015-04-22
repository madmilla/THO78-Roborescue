/**
 * @author    Edwin Koek
 * @version   1.2
 * @since     19-4-2015
 */

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

/**
 * TemperatureSensor class.
 * @brief This class creates objects that can be used to convert
 * ADC readings from the LM335 temperature sensor into degrees celcius.
 */
class TemperatureSensor{
public:
  /**
   * TemperatureSensor constructor.
   */
  TemperatureSensor();
  
  /**
   * getTemperatureC returns a temperature in Celcius based on values
   * from a Sigma-Delta conversion. If the parameters contain invalid values
   * the function wil return -1.
   *
   * @param float ADCReading
   * @param float ADCMaxValue
   * @param float ADCMinValue
   */
  float getTemperatureC(
      float ADCReading,
      float ADCMaxValue, 
      float ADCMinValue = 0);
  /**
   * getTemperatureC returns a temperature in Celcius based on given voltage.
   * If a invalid voltage is given the function wil return -1.
   *
   * @param float volt
   */
  float getTemperatureC(float volt);
  
  /**
   * getTemperatureK returns a temperature in Kelvin based on values
   * from a Sigma-Delta conversion. If the parameters contain invalid values
   * the function wil return -1.
   *
   * @param float ADCReading
   * @param float ADCMaxValue
   * @param float ADCMinValue
   */
  float getTemperatureK(
      float ADCReading,
      float ADCMaxValue, 
      float ADCMinValue = 0);
      
  /**
   * getTemperatureK returns a temperature in Kelvin based on given voltage.
   * If a invalid voltage is given the function wil return -1.
   *
   * @param float volt
   */
  float getTemperatureK(float volt);
  
};
  

#endif