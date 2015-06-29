namespace hwcpp {

template< class _pin, class timing >
struct one_wire {

   typedef pin_oc_from< _pin > pin;
   
   static void init(){
      pin::init();
      pin::set( 1 );
   }
   
   static void reset(){
      pin::set( 0 );
      timing::template us< 600, 100 >::wait();
      pin::set( 1 );
      timing::template us< 600 >::wait();
   }
   
   static bool device_present(){
      if( ! pin::get() ) return false;
      pin::set( 0 );
      timing::wait( timing::duration::us( 600 ), timing::duration::us( 1 ));
      pin::set( 1 );
      timing::wait( timing::duration::us( 72 ), timing::duration::us( 1 ));
      bool presence_pulse = pin::get();
      timing::wait( timing::duration::us( 600 ), timing::duration::us( 1 ));
      return (! presence_pulse ) && pin::get();
   }
   
   static void write( int x ){
      for( int i = 0; i < 8; i++ ){
         if( x & 0x01 ){
            pin::set( 0 );
            timing::wait( timing::duration::us( 5 ), timing::duration::us( 1 ));
            pin::set( 1 );
            timing::wait( timing::duration::us( 85 ), timing::duration::us( 1 ));
         } else {
            pin::set( 0 );
            timing::wait( timing::duration::us( 80 ), timing::duration::us( 1 ) );
            pin::set( 1 );
            timing::wait( timing::duration::us( 20 ), timing::duration::us( 1 ));
         }
         x = x >> 1;
      }         
   }   

   static unsigned char read( void ){
      unsigned char d = 0;
      for( int i = 0; i < 8; i++ ){
         d = d >> 1;
         pin::set( 0 );
         timing::wait( timing::duration::us( 5 ), timing::duration::us( 0 ));
         pin::set( 1 );
         timing::wait( timing::duration::us( 5 ), timing::duration::us( 0 ));
         if( pin::get() ){
            d = d | 0x80;
         }
         timing::wait( timing::duration::us( 100 ));
      }
      return d;
   }

   static unsigned char read_family_code( void ){
      if( ! device_present() ){
         return 0;
      }   
      write( 0x33 );
         timing::wait( timing::duration::us( 100 ));
      return read();
   }      
   
}; // class one_wire

}; //namespace hwcpp

