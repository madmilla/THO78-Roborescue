//! @file
//! This library implements bit-banged low-level I2C routines
//! using the standard SCL and SDA pins

#include "LPC11xx.h"
#include "i2c.h"

void i2c_init( void ){
   // no special initialization needed
}

void i2c_pause( void ){
   await( now() + 5 );
}

void i2c_scl_set( unsigned char x ){
   if( x ){
      LPC_GPIO0->DATA |= 0x10;   
   } else {
      LPC_GPIO0->DIR |= 0x10; 
      LPC_GPIO0->DATA &= ~ 0x10;   
   }    
}

void i2c_sda_set( unsigned char x ){
   if( x ){
      LPC_GPIO0->DIR &= ~ 0x20; 
   } else {
      LPC_GPIO0->DIR |= 0x20; 
      LPC_GPIO0->DATA &= ~ 0x20;
   }    
}

unsigned char i2c_sda_get( void ){
   return ( LPC_GPIO0->DATA & 0x20 ) != 0;
}

void i2c_start( void ){
   i2c_sda_set( 0 );
   i2c_pause();
   i2c_scl_set( 0 );
   i2c_pause();
}

void i2c_stop(){
   i2c_scl_set( 0 );
   i2c_pause();
   i2c_sda_set( 0 );
   i2c_pause();
   i2c_scl_set( 1 );
   i2c_pause();
   i2c_sda_set( 1 );
   i2c_pause();
}

void i2c_put_bit( unsigned char x ){
   i2c_scl_set( 0 );
   i2c_pause();
   i2c_sda_set( x );
   i2c_scl_set( 1 );
   i2c_pause();
}

unsigned char i2c_get_bit( void ){
   unsigned char x;
   i2c_scl_set( 0 );
   i2c_pause();
   i2c_sda_set( 1 );
   i2c_scl_set( 1 );
   i2c_pause();
   x = i2c_sda_get();
   i2c_pause();
   return x;
}

unsigned char i2c_ack_get( void ){
   unsigned char x;
   x = ! i2c_get_bit();
   return x;
}

void i2c_put_ack( void ){
   i2c_bit_put( 0 );
}

void i2c_put_nack( void ){
   i2c_bit_put( 1 );
}

void i2c_put_byte( unsigned char x ){
   int i;
   for( i = 0; i < 8; i++ ){
      i2c_put_bit( ( x & 0x80 ) != 0 );
      x = x << 1;
   }
}

unsigned char i2c_get_byte( void ){
   int i;
   unsigned char result = 0;
   for( i = 0; i < 8; i++ ){
      result = result << 1;
      if( i2c_get_bit() ){
         result |= 0x01;
      }
      
   }
   return result;
}

