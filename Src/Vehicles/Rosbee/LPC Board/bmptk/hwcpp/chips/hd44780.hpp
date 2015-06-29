namespace hwcpp {   
   

template< 
   class _data, 
   class _rs, 
   class _e, 
   int columns,
   int lines,
   class timing >
class hd44780 {
private:

   typedef port_out_from< _data > data_pins;
   typedef pin_out_from< _e > e_pin;
   typedef pin_out_from< _rs > rs_pin;
   
   static void write4( unsigned char n ){
      timing::wait( 10 * timing::us );
      data_pins::set( n );
      timing::wait( 20 * timing::us );
      e_pin::set( 1 );
      timing::wait( 20 * timing::us );
      e_pin::set( 0 );
      timing::wait( 100 * timing::us );  // enough for most instructions
   }

   static void write8( bool is_data, unsigned char b ){
      rs_pin::set( is_data );
      write4( b >> 4 );
      write4( b );
   }   
   
   static int x, y;
   
public:  

   static void command( unsigned char cmd ){
      write8( 0, cmd );
   }

   static void data( unsigned char chr ){
      write8( 1, chr );
   }

   static void clear(){
      command( 0x01 );
      timing::wait( 5 * timing::ms );
      x = y = 0;
   }
   
   static void goto_xy( int _x, int _y ){
      x = _x;
      y = _y;
      #if mkt_clcd_jump == 1
         if( x < 8 ){
            command( 0x80 + x );
         } else {
            command( 0x80 + 0x40 + ( x - 8 ));
         }
      #else
         if( lines == 2 ){
            command( 0x80 +
               (( y > 0 ) ? 0x40 : 0x00 )
               + ( x ));
         } else {
            command( 0x80 +
                 ( y & 0x01 ? 0x40 : 0x00 )
               + ( y & 0x02 ? 0x14 : 0x00 )
               + ( x ));            
         }
      #endif
   }   
   
   static void init(){
      data_pins::init();
      e_pin::init();
      rs_pin::init();
      
      // give LCD time to wake up
      e_pin::set( 0 );
      rs_pin::set( 0 );
      timing::wait( 100 * timing::ms );

      // interface initialisation: make sure the LCD is in 4 bit mode
      // (magical sequence, taken from the HD44780 datasheet)
      write4( 0x03 );
      timing::wait(  15 * timing::ms );
      write4( 0x03 );
      timing::wait(  100 * timing::us );
      write4( 0x03 );
      write4( 0x02 );     // 4 bit mode

      // functional initialisation
      command( 0x28 );    // 4 bit mode, 2 lines, 5x8 font
      command( 0x0C );    // display on, no cursor, no blink
      clear();            // clear display, 'cursor' home
      goto_xy( 0, 0 );    // 'cursor' home      
   }
   
   static void write_raw( char chr ){
      #if mkt_clcd_jump == 1
         if( _mkt_clcd_x == 8 ){
            goto_xy( 8, _y );
         }
       #endif
      // don't write outside the boundaries
      if(
         ( x < columns )
         && ( y < lines )
       ){
          data( chr );
          x++;
       } 
   }         
   
   static void write( char c ){
      if( c == '\n' ){
         goto_xy( 0, y + 1 );
      } else if( c == '\r' ){
         goto_xy( 0, y );
      } else if( c == '\v' ){
         clear();
      } else {
         write_raw( c );
      }   
   }
   
};

   template< class _data, class _rs, class _e, int x, int y, class timing >
      int hd44780< _data, _rs, _e, x, y, timing >::x;
   template< class _data, class _rs, class _e, int x, int y, class timing >
      int hd44780< _data, _rs, _e, x, y, timing >::y;
   
} //namespace hwcpp;   