#include "LPC810lib.h"

#define LED 2
		
int main( void ){	
   pin_configure_as_output( LED );
   while( 1 ){
      pin_set( LED, 1 );   
      wait_us( 50 * 1000 );
      pin_set( LED, 0 );   
      wait_us( 1 * 1000 * 1000 );
	}     
}