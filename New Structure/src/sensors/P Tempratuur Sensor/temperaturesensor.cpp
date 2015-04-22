#include "temperaturesensor.h"

const static float Kelvin = 273.15;

TemperatureSensor::TemperatureSensor(){}

float TemperatureSensor::getTemperatureC(
      float ADCReading,
      float ADCMaxValue, 
      float ADCMinValue){
  if(0 > (ADCReading - ADCMinValue) || ADCReading > ADCMaxValue){
   return -1; 
  } 
  ADCReading -= ADCMinValue;
  ADCMaxValue -= ADCMinValue;   
  return ((((ADCReading - ADCMinValue) / (ADCMaxValue - ADCMinValue)) * 3300) / 10) - Kelvin;
}        

float TemperatureSensor::getTemperatureC(float volt){
  if(0 > volt || volt > 3.3){
    return -1;
  }   
  return ((volt * 1000) / 10) - Kelvin;
}  

float TemperatureSensor::getTemperatureK(
      float ADCReading,
      float ADCMaxValue, 
      float ADCMinValue){
  if(0 > (ADCReading - ADCMinValue) || ADCReading > ADCMaxValue){
   return -1; 
  }    
  ADCReading -= ADCMinValue;
  ADCMaxValue -= ADCMinValue;
  return (((ADCReading - ADCMinValue) / (ADCMaxValue - ADCMinValue)) * 3300) / 10;    
}        

float TemperatureSensor::getTemperatureK(float volt){
  if(0 > volt || volt > 3.3){
    return -1;
  }    
  return (volt * 1000) / 10;
}  

