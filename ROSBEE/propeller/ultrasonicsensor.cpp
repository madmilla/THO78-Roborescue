#include "ultrasonicsensor.h"
#include "simpletools.h"

UltraSonicSensor::UltraSonicSensor(int pin):
m_pin{pin},
m_temperature{22}
{
  low(pin);
}

int UltraSonicSensor::getDistance(){
  pulse_out(m_pin,10);
  int velocity = 331.5 + (0.6 * m_temperature);
  int travelTime = pulse_in(m_pin,1);  
  return (velocity * travelTime * 100)/(2 * 1000000);
}  