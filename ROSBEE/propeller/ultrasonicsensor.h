/**
* @autor	Edwin Koek
* @version	1.0
* @since	30-03-2015
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
 * UltraSonicSensor constructor that sets the pin value and also the temperature. Currently
 * the temperature defaults to 22 as we have no means of actually measuring it yet.
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
  
private:
  int m_pin;
  int m_temperature;
};

#endif  