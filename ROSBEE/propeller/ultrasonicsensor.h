#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltraSonicSensor{
public:
/**
 * UltraSonicSensor constructor that sets the pin value and also the temperature. Currently
 * the temperature defaults to 22 as we have no means of actually measuring it yet.
 * 
 * @param int pin
 */
  UltraSonicSensor(int pin);

/**
 * The getDistance function wil return the distance between the ultrasonic sensor
 * and a detected object in centimeters as a integer.
 * The distance calculation uses cm as distance unit and us as time unit therefor the standard
 * function is multiplied by 100 / 1000000
 */ 
  int getDistance();
  
private:
  int m_pin;
  int m_temperature;
};

#endif  