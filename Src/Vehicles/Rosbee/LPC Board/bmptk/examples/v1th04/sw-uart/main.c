// simple test for the bit-banged uart functions

#include "LPC11xx.h"
#include "timer.h"
#include "sw-uart.h"
		
int main( void ){	
	timer_init();
	uart_init(); 
	   
	uart_put_string( "Hello world, the answer is " );
	uart_put_int_decimal( 42 );
	uart_put_string( ".\n" );
	   
	uart_put_string( "You are " );   
	uart_put_int_hexadecimal( 0xDEADBEEF, 8 );
	uart_put_string( ".\n" );
	   
	return 0;
}