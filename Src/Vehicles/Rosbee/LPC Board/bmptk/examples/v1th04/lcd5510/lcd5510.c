#include "lcd5510.h"
#include "timer.h"
#include "LPC11xx.h"

void sce_set( unsigned char x ){
   if( x ){
      *(volatile int *)( 0x50000000 + 1 * 0x10000 +  ( 0x04 << 0 )) = -1;
   } else {
      *(volatile int *)( 0x50000000 + 1 * 0x10000 + ( 0x04 << 0 )) = 0;
   } 
}

void res_set( unsigned char x ){
   if( x ){
      *(volatile int *)( 0x50000000 + 1 * 0x10000 +  ( 0x04 << 1 )) = -1;
   } else {
      *(volatile int *)( 0x50000000 + 1 * 0x10000 + ( 0x04 << 1 )) = 0;
   } 
}

void dc_set( unsigned char x ){
   if( x ){
      *(volatile int *)( 0x50000000 + 1 * 0x10000 +  ( 0x04 << 2 )) = -1;
   } else {
      *(volatile int *)( 0x50000000 + 1 * 0x10000 + ( 0x04 << 2 )) = 0;
   } 
}

void sdin_set( unsigned char x ){
   if( x ){
      *(volatile int *)( 0x50000000 + 1 * 0x10000 +  ( 0x04 << 3 )) = -1;
   } else {
      *(volatile int *)( 0x50000000 + 1 * 0x10000 + ( 0x04 << 3 )) = 0;
   } 
}

void sclk_set( unsigned int x ){
   if( x ){
      *(volatile int *)( 0x50000000 + 1 * 0x10000 + ( 0x04 << 4 )) = -1;
   } else {
      *(volatile int *)( 0x50000000 + 1 * 0x10000 + ( 0x04 << 4 )) = 0;
   } 
}

void wait( unsigned long long int t ){
   await( now() + t );
}

	
void lcd5510_send_byte( unsigned char d ){
   int i;
   for( i = 0; i < 8; i++ ){
      sdin_set( d & 0x80 );
      sclk_set( 1 );
      d = d << 1;
      sclk_set( 0 );
   }
}    
   
void lcd5510_command( unsigned char d ){
   dc_set( 0 );
   sce_set( 0 );
   lcd5510_send_byte( d );
   sce_set( 1 );
} 	

void lcd5510_data( unsigned char d ){
   dc_set( 1 );
   sce_set( 0 );
   lcd5510_send_byte( d );
   sce_set( 1 );
} 	
   
void lcd5510_pixels( unsigned char x, unsigned char y, unsigned char d ){
   lcd5510_command( 0x80 | x );   
   lcd5510_command( 0x40 | y );  
   lcd5510_data( d );
}

void configure_this_pin_as_gpio( 
   volatile uint32_t *p, 
   unsigned int value 
){
   LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);     // enable IOCON
   *p = value | ( *p & ~0x07 );
   LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);    // disanable IOCON
}

#define GPIO_CONFIG( a, v ) configure_this_pin_as_gpio( a, v ); 
   
void lcd5510_init( void ){
   // configure the pins as GPUIO
   GPIO_CONFIG( &LPC_IOCON->R_PIO1_0,      0x01 );
   GPIO_CONFIG( &LPC_IOCON->R_PIO1_1,      0x01 );
   GPIO_CONFIG( &LPC_IOCON->R_PIO1_2,      0x01 );
   GPIO_CONFIG( &LPC_IOCON->SWDIO_PIO1_3,  0x01 ); 
   GPIO_CONFIG( &LPC_IOCON->PIO1_4,        0x00 );

   LPC_GPIO1->DIR = LPC_GPIO1->DIR | 0x1F;
   
   sclk_set( 0 );
   wait( 1 );
   sce_set( 1 );
   wait( 1 );
   res_set( 0 );
   wait( 1 );
   res_set( 1 ); 
   wait( 1 );
	  
	   // initialization according to
	   // https://www.sparkfun.com/products/10168 - nee, andere
   lcd5510_command( 0x21 );  // select exteded instructions
   lcd5510_command( 0xC8 );  // Vop = 110000b
   lcd5510_command( 0x06 );  // TCx = 00b
   lcd5510_command( 0x13 );  // BSx = 100b
   lcd5510_command( 0x20 );  // select basic instructions, horizontal addressing
   lcd5510_command( 0x0C );	// normal mode   
}	

unsigned char lcd5510_buf[ 504 ];

void lcd5510_write( unsigned int x, unsigned int y, unsigned char d ){
   unsigned int a = x + ( y / 8 ) * 84;
   unsigned int m = 1 << ( y % 8 );
   
   if(( x >= 84 ) || ( y >= 48 )){
      return;
   }
   
   if( d ){
      lcd5510_buf[ a ] |= m;
   } else {     
      lcd5510_buf[ a ] &= ~m;
   }
   
   lcd5510_pixels( x, y / 8, lcd5510_buf[ a ] );         
}
   
void lcd5510_clear( void ){
   int i;
   lcd5510_command( 0x80 | 0 );   
   lcd5510_command( 0x40 | 0 );  
   for( i = 0; i < 504; i++ ){
      lcd5510_buf[ i ] = 0;
      lcd5510_data( 0 );
   }         
}

void swap( unsigned int *a, unsigned int * b ){
   unsigned int t;
   t = *a; 
   *a = *b;
   *b = t;
}

int abs( int x ){
   return x >= 0 ? x : -x;
}

void lcd5510_line( 
   unsigned int x0, unsigned int y0,
   unsigned int x1, unsigned int y1,
   unsigned char d 
){
                
   // http://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
   // http://homepages.enterprise.net/murphy/thickline/index.html
     
   int Dx = x1 - x0; 
   int Dy = y1 - y0;
   
   int steep = (abs(Dy) >= abs(Dx));
   
   if( steep ){
      swap( &x0, &y0 );
      swap( &x1, &y1 );
      
      // recompute Dx, Dy after swap
      Dx = x1 - x0;
      Dy = y1 - y0;
   }
   
   int xstep = 1;
   if( Dx < 0 ){
      xstep = -1;
      Dx = -Dx;
   }
   
   int ystep = 1;
   if( Dy < 0 ){
      ystep = -1;    
      Dy = -Dy; 
   }
   int TwoDy = 2*Dy; 
   int TwoDyTwoDx = TwoDy - 2*Dx; // 2*Dy - 2*Dx
   int E = TwoDy - Dx; //2*Dy - Dx
   int y = y0;
   int xDraw, yDraw, x;  
   for( x = x0; x != x1; x += xstep ){    
      if (steep) {     
         xDraw = y;
         yDraw = x;
      } else {     
         xDraw = x;
         yDraw = y;
      }

      lcd5510_write( xDraw, yDraw, d );

      if( E > 0 ){
         E += TwoDyTwoDx; //E += 2*Dy - 2*Dx;
         y = y + ystep;
      } else {
         E += TwoDy; //E += 2*Dy;
      }
   }
}
