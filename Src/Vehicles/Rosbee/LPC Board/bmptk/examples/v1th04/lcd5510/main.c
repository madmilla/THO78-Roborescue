// lines:

#include "lcd5510.h"
#include "timer.h"

int rand(){
   static int n = 0;
   n = n * 214013L + 2531011L;
   return ( n >> 16) & 0x7fff;
}

unsigned int random_in_range( unsigned int min, unsigned int max ){
   unsigned int x = rand();
   x = x % ( max - min + 1 ); 
   return min + x;
}
		
int main( void ){	
   unsigned int x, y, n, x1, y1;
   timer_init();
   lcd5510_init();
   for(;;){
      lcd5510_clear();
      for( x = 0; x < 84; x++ ){
         lcd5510_write( x, 0, 1 );
         lcd5510_write( x, 47, 1 );
      }   
      for( y = 0; y < 48; y++ ){
         lcd5510_write( 0, y, 1 );
         lcd5510_write( 83, y, 1 );
      }   
      for( n = 0; n < 30; n++ ){
         x  = random_in_range( 0, 84 );
         x1 = random_in_range( 0, 84 );
         y  = random_in_range( 0, 48 );
         y1 = random_in_range( 0, 48 );
         lcd5510_line( x, y, x1, y1, 1 );
         await( now() + 500 * 1000 );
      }
   }      
}