// using a timer library to generate a 440Hz tone on GPIO1_5

#include "LPC11xx.h"
#include "timer.h"

#define PERIOD ( 1000 * 1000 / 440 )
		
int main( void ){	
   unsigned int i, next;
   
   // make the LPSP pin an output
   LPC_GPIO1->DIR = LPC_GPIO1->DIR | 0x20;
   
   // initialize the timer library
   timer_init();
   
   // start at the current time
   next = now();
   
   // beep for 2 seconds
   for( i = 0; i < 440; i++ ){
   
      next += ( PERIOD / 2  );
      while( now() < next );
      LPC_GPIO1->DATA = LPC_GPIO1->DATA | 0x20;

      next += ( PERIOD / 2 );
      while( now() < next );
      LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ 0x20; 
   }
   
   return 0;
}