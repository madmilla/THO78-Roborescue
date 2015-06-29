// slowly rotate a servo connected to pin GP1_4
//

#include "LPC11xx.h"
#include "timer.h"

void servo_low( void ){
   LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ 0x10;
}

void servo_high( void ){
   LPC_GPIO1->DATA = LPC_GPIO1->DATA | 0x10;;
}

void servo_init( void ){
   LPC_GPIO1->DIR = LPC_GPIO1->DIR | 0x10; 
   servo_low();
}

void servo_pulse( unsigned int length ){
   servo_high();
   await( now() + length );   
   servo_low();
}

int main( void ){	
   unsigned int n;
   servo_init();
   timer_init();
   for(;;){
      for( n = 500; n < 2500; n = n + 10 ){
         servo_pulse( n );
         await( now() + 25 * 1000 );
      }          
   }
}