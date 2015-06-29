// use the CT32B0 timer as a 12 MHz counter
// to generate a reasonably accurate central A note (440Hz) on GPIO1_4
// 440 Hz => 27273 clock ticks per period
//
// This application is organised to be a compact demonstration
// of the use of the CT32B0 timer, it is NOT meant as an example 
// of good program structure.

#include "LPC11xx.h"

#define PERIOD 27273
		
int main( void ){	
   unsigned int i, next;
   
   // make the LPSP pin an output
   LPC_GPIO1->DIR = LPC_GPIO1->DIR | 0x20;
   
   LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);     // enable clock for CT32B0
   LPC_TMR32B0->CTCR = 0x00;                // use AHB clock
   LPC_TMR32B0->PR   = 0;                   // 12 MHz
   LPC_TMR32B0->TC   = 0;                   // start at 0
   LPC_TMR32B0->TCR  = 0x01;                // enable the timer
   
   // start at the current counter value
   next = LPC_TMR32B0->TC;
   
   // beep for approximately 2 seconds
   for( i = 0; i < 440; i++ ){
   
      next += ( PERIOD / 2  );
      while( LPC_TMR32B0->TC < next );
      LPC_GPIO1->DATA = LPC_GPIO1->DATA | 0x20;

      next += ( PERIOD / 2 );
      while( LPC_TMR32B0->TC < next );
      LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ 0x20; 
      
      i = 0;
   }
   
   return 0;
}