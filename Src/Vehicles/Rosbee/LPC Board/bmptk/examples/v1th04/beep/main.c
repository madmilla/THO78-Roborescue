#include "LPC11xx.h"

//! beep on pin PIO1_5
//
//! This function will beep on pin PIO1_5 for n periods.
//! The length of each phase (half-period) is determined by a
//! busy for loop that iterates x times.

void beep( int n, int x ){
   volatile int i;

   LPC_GPIO1->DIR = LPC_GPIO1->DIR | 0x20;
   
   while( n > 0 ){

      LPC_GPIO1->DATA = LPC_GPIO1->DATA | 0x20;

      for( i = 0; i < x; i++ );
	
      LPC_GPIO1->DATA = LPC_GPIO1->DATA & ~ 0x20;
 
      for( i = 0; i < x; i++ );
      
      n--;
   }
}

void sound( unsigned char x ){
	int i;
   if( x ){
      for( i= 0; i <100 ; i++ ){
      beep( 500, 500 );
      beep( 400, 800 );
	}
   } else {
      for( i= 0; i <100 ; i++ ){
	  beep(100,100);
	  beep(100,150);
	}
   }
}

unsigned char switch_get(){
   return ( LPC_GPIO0->DATA & ( 1 << 7 ) ) == 0;
}
			
int main( void ){	
   for(;;){
	sound(1);
   }
   return 0;
}