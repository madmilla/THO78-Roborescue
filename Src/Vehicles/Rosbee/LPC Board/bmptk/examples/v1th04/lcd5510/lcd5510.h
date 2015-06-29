//! @file
//! This library implements an interface to a nokia 5510 LCD.
//! This is an 84 x 84 pixel B/W LCD.
//! The libray uses a 504-byte RAM buffer.
//! This library uses the timer library.
//!
//! The pin assignment is:
//! - GPIO1_0 : SCE 
//! - GPIO1_1 : RES
//! - GPIO1_2 : D/C
//! - GPIO1_3 : SDIN (MOSI) 
//! - GPIO1_4 : SCLK
//!
//! Other LCD pins:
//! - GND = ground (0V)
//! - VCC = power (3V3)
//! - LED = backlight LEDs, connect to 3V3
//

//! initialise the interface pin and the display
//
//! This function must be called before any of the other
//! lcd5510_* functions are called.
void lcd5510_init( void );   

//! draw a single pixel on the display at (x,y)
//
//! This function draws the single pixel of the LCD at
//! (x,y). When x >=84 or y >= 48 the call has no effect.
//! When d is false the pixel will be made light (white?), otherwise
//! it will be made dark (black).
void lcd5510_write( unsigned int x, unsigned int y, unsigned char d );
   
//! clear the display
//
//! This function will clear the display to light (white?).
//! This is much faster than calling lcd5510_write for each pixel.
void lcd5510_clear( void );

//! draw a line on the display from (x0,y0) to (x1,y1)
//
//! This function will draw a line from (x0,y0) to (x1,y1) by
//! calling lcd5510_write( .., d ) for the pixels that make
//! up the line.
void lcd5510_line( 
   unsigned int x0, unsigned int y0,
   unsigned int x1, unsigned int y1,
   unsigned char d );
   