/**
* @autor	Floris Rijker, Casper Wolf
* @version	1.0
* @since	22-04-2015
*/

#include "simpletools.h"   
#include "ultrasonicsensor.h" 
#include <propeller.h>
#include <stdio.h>           

int main(){
  UltraSonicSensor USS1(4);
  UltraSonicSensor USS2(5);
  UltraSonicSensor USS3(6);
  UltraSonicSensor USS4(7);
  UltraSonicSensor USS5(9);
  int metingNr = 1;
  int sensor1, sensor2, sensor3, sensor4, sensor5;
  
  while(1){
    print("%c",CLS);
    printf("\nMeting %d\n",metingNr);
    for (int i = 1; i<6;i++){
      switch(i){
        case 1:
        sensor1 = USS1.getDistance();
        if(sensor1 < 372){ 
          printf("Sensor links achter meet %d centimeter \n",sensor1);
        }
        else{
          printf("Sensor links achter ziet niks dichter bij dan 371 centimeter\n");
        }                    
        break;
        case 2:
        sensor2 = USS2.getDistance();
        if(sensor2 < 372){ 
          printf("Sensor links voor meet %d centimeter \n",sensor2);
        }
        else{
          printf("Sensor links voor ziet niks dichter bij dan 371 centimeter\n");
        }  
        break;
        case 3: 
        sensor3 = USS3.getDistance();
        if(sensor3 < 372){ 
          printf("Sensor midden voor meet %d centimeter \n",sensor3);
        }
        else{
          printf("Sensor midden voor ziet niks dichter bij dan 371 centimeter\n");
        }  
        break;
        case 4:
        sensor4 = USS4.getDistance();
        if(sensor4 < 372){ 
          printf("Sensor rechts voor meet %d centimeter \n",sensor4);
        }
        else{
          printf("Sensor rechts voor ziet niks dichter bij dan 371 centimeter \n");
        }  
        break;
        case 5: 
        sensor5 = USS5.getDistance();
        if(sensor5 < 372){ 
          printf("Sensor rechts achter meet %d centimeter \n",sensor5);
        }
        else{
          printf("Sensor rechs achter ziet niks dichter bij dan 371 centimeter\n");
        }  
        break;
        default:
        printf("Error, dit is geen sensor\n");
        break;
      }      
      //waitcnt(CNT + 16000000);
    }
    waitcnt(CNT + 60000000);
    metingNr ++;
  }  
  return 0;
}
