// read a DS1990 identity button skeleton code
// use pin GP0_4 ('SCL')
//

#include "LPC11xx.h"
#include "timer.h"
#include "sw-uart.h"

// remove this line, your wait() declaration should be in your timer.h
void delay( unsigned int t ){}

void ds_pin_set( unsigned char x ){
   if( x ){
      // . . .
   } else {
      // . . .
   }      
}

unsigned char ds_pin_get(){
    // replace with your code
    return 0;
}

void ds_pin_pulse( unsigned long long int t ){
   ds_pin_set( 0 );
   delay( t );
   ds_pin_set( 1 );
}

unsigned char ds_present(){

   // give the device time to get back to the 'rest' state
   ds_pin_set( 1 );
   delay( 2000 );
   
   // test for stuck-at-0
   if( ! ds_pin_get() ){ return 0; }
   
   // request a presence pulse
   ds_pin_pulse( 1000 );   
   
   // test for the presence pulse 
   delay( 30 );
   if( ds_pin_get() ){ return 0; }
   
   // test whether the presence pulse ends
   delay( 1000 );
   if( ! ds_pin_get() ){ return 0; }
   
   // all tests succeeded
   return 1;   
}

void ds_send_bit( unsigned char b ){
   // . . .
   delay( 1000 );
}

void ds_send_byte( unsigned char b ){
   // . . .
}

unsigned char ds_receive_bit( void ){
   unsigned char x;
   // . . . 
   x = ds_pin_get();
   delay( 100 );
   return x;
}

unsigned char ds_receive_byte(){
   int i;
   unsigned char d = 0;
   for( i = 0; i < 8; i++ ){
      d = d >> 1;
      if( ds_receive_bit() ){
         d = d | 0x80;   
      } else {
         d = d & ~ 0x80;
      }
   }
   return d;
}

void ds1990_id_print(){
   int i, d;
   ds_send_byte( 0x33 );
   for( i = 0; i < 8; i++ ){
      d = ds_receive_byte();
      uart_put_int_hexadecimal( d, 2 );
      uart_put_string( " " );
   }
   uart_put_string( "\n" );
}
		
int main( void ){	
   timer_init();
   uart_init(); 
   uart_put_string( "DS1990 reader\n" );
   for(;;){
      delay( 500 * 1000 );
      if( ds_present() ){
         uart_put_string( "***\n" );
         ds1990_id_print(); 
      } else {
         uart_put_string( "-\n" );
      }   
   }  
   return 0;
}