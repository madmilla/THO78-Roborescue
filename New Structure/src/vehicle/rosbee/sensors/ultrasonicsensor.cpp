#include "ultrasonicsensor.h"
#include "simpletools.h"

UltraSonicSensor::UltraSonicSensor(int pin):
pin{pin},
temperature{22}
{
  low(pin);
}

int UltraSonicSensor::getDistance(){
  pulse_out(pin,10);
  int velocity = 331.5 + (0.6 * temperature);
  int travelTime = pulse_in(pin,1);  
  return (velocity * travelTime * 100)/(2 * 1000000);
}  

void UltraSonicSensor::setTemperature(float temp){
  temperature = temp;
}  