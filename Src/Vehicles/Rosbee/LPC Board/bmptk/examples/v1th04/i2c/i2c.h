//! @file
//! This library implements bit-banged low-level I2C routines
//! using the standard SCL and SDA pins

#include "LPC11xx.h"

//! initialize the I2C bus
void i2c_init( void );

//! output an I2C start 
void i2c_start( void );

//! output an I2C stop
void i2c_stop();

//! get and return the ack condition
unsigned char i2c_ack_get( void );

//! output an I2C ack
void i2c_put_ack( void );

//! output an I2C nack
void i2c_put_nack( void );

//! output a byte on the i2c bus
void i2c_put_byte( unsigned char x );

//! get a byte from the i2c bus and return it
unsigned char i2c_get_byte( void );

