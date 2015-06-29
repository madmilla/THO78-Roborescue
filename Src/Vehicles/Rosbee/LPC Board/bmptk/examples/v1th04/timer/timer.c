// implementation of the timer functions
//

#include "timer.h"
#include "LPC11xx.h"

void timer_init( void ){
   LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);     // enable clock for CT32B0
   LPC_TMR32B0->CTCR = 0x00;                // use AHB clock
   LPC_TMR32B0->PR   = 11;                  // 12 MHz -> 1 count/usec
   LPC_TMR32B0->TC   = 0;                   // start at 0
   LPC_TMR32B0->TCR  = 0x01;                // enable the timer
}

unsigned int now(){
   return LPC_TMR32B0->TC;
}

void await( unsigned int t ){
   while( t > now() ){
   }
}
