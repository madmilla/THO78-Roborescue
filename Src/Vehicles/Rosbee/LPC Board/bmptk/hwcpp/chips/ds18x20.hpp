namespace hwcpp {

template< class bus, class timing >
struct ds18x20 {

   static void init(){
      bus::init();
   }

   static void conversion_start(){
      (void)bus::reset();
      bus::write( 0xCC );
      bus::write( 0x44 );
   }   

   static int temperature(){
      unsigned char d1, d2;
      conversion_start();
      timing::wait( timing::duration::ms( 800 ) );
      (void)bus::reset();
      bus::write( 0xCC );
      bus::write( 0xBE );
      d1 = bus::read();
      d2 = bus::read();
      return (((unsigned int)d2) << 8 ) + d1;
   }   
   
   /*
   static void temperature( hardware::string<> s ){
      int temp = temperature();
      s = '';
      if( temp < 0 ){
         temp = - temp;
         s << '-';
      }
      s << std::dec << temp;
      s << ',';
      s << temp & 0x01 ? '5': '0';
   }
   */
   
}; // class ds18x20

template< class bus, class timing >
struct ds18b20 : public ds18x20< bus, timing >{

   static void init(){
      ds18x20< bus, timing >::init();
   }
   
   /*
   static int temperature(){
      unsigned char d1, d2;
      conversion_start();
      timing::wait( 800 * timing::ms );
      (void)bus::reset();
      bus::write( 0xCC );
      bus::write( 0xBE );
      d1 = bus::read();
      d2 = bus::read();
      return (((unsigned int) d2 ) << 8 ) + d1;
   } 
   */  
   
}; // class ds18b20

}; // namespace hwcpp