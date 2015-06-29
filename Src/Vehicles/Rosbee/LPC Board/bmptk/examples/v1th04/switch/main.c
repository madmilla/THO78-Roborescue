// switch a LED on GPIO1_4 by a switch on GPIO0_7
//
// The LED is active high (connected to ground),
// the button is active low (also connected to ground).
// The internal pullup is used for the button.
//
// This is a very simple application.
// It aims to show direct use of the hardware rather than
// good programming practices (like abstracting from the GPIO pin
// used and using a timer for the delay).
//
// It uses the CMSIS header file to access the direction
// and value registers for the pins.
//
// Note that after a reset the pins used here are automatically
// configured as GPIO, hence there is no need to configure
// the pin. Some other pins are NOT configured to GPIO by a reset,
// hence blinking on such a pin requires the additional step of
// configuring the pin as GPIO.
//

// includes the cmsis definitions for the LPC1114
#include "LPC11xx.h"

void led_init(){
   LPC_GPIO1->DIR = LPC_GPIO1->DIR | ( 1 << 4 ); 
}

void led_set( unsigned char x ){
   if( x ){
      LPC_GPIO1->DATA = LPC_GPIO1->DATA | ( 1 << 4 );
   } else {
      LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ ( 1 << 4 );
   }
}

unsigned char switch_get(){
   return ( LPC_GPIO0->DATA & ( 1 << 7 ) ) == 0;
}
		
int main( void ){	
   led_init();
   for(;;){
      led_set( switch_get() );
   }      
}