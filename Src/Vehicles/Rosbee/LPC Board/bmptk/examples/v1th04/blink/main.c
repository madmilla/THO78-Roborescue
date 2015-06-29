// blink a LED on pin PIO1_4
//
// This is a very simple blink-a-LED application.
// It aims to show direct use of the hardware rather than
// good programming practices (like abstracting from the GPIO pin
// used and using a timer for the delay).
//
// It uses the CMSIS header file to access the direction
// and value registers for pin GPIO1_4.
// It uses a busy-wait for the delay, which can be affected
// by the compiler and optimization settings used.
//
// Note that after a reset the GPIO1_4 pin is automatically
// configured as GPIO, hence there is no need to configure
// the pin. Some other pins are NOT configured to GPIO by a reset,
// hence blinking on such a pin requires the additional step of
// configuring the pin as GPIO.
//

// includes the cmsis definitions for the LPC1114
#include "LPC11xx.h"
			
int main( void ){	

   // must be volatile to prevent optimization of the wait loops
   volatile int i;
    
   // make PIO1_4 an output
   LPC_GPIO1->DIR = LPC_GPIO1->DIR | 0x10; 
   
   // loop forever
   while( 1 ){
   
      // make PIO1_4 high
      LPC_GPIO1->DATA = LPC_GPIO1->DATA | 0x10;

      // wait 
      for( i = 0; i < 300000; i++ ){ 
      }
	
      // make PIO1_4 low
      LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ 0x10;

      // wait 
      for( i = 0; i < 300000; i++ ){
      }
	
	}     
}