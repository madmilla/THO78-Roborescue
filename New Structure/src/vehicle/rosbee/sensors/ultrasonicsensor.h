/**
* @autor	Edwin Koek
* @version	2.0
* @since	19-04-2015
*/

#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

/**
 * UltraSonicSensor class. 
 * @brief This class creates objects that can be used to read data from a ultrasonic sensor.
 */
class UltraSonicSensor{
public:
/**
 * UltraSonicSensor constructor that sets the pin value and also the temperature.
 * The temperature defaults to 22.
 * 
 * @param int pin specifies the pin that the sensor is connected to.
 */
  UltraSonicSensor(int pin);

/**
 * The getDistance function wil return the distance between the ultrasonic sensor
 * and a detected object in centimeters as a integer.
 * The distance calculation uses cm as distance unit and us as time unit therefor the standard
 * function is multiplied by 100 / 1000000
 *
 * @return Distance in cm
 */ 
  int getDistance();
  
/**
 * The setTemperature function allows you to set the temperature that is used in the distance
 * calculations.
 *
 * @param float temperature
 */
  void setTemperature(float temp);
  
private:
  int pin;
  float temperature;
};

#endif  
