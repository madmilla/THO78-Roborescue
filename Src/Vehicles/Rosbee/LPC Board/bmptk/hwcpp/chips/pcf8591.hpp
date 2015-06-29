namespace hwcpp {

   template < 
      typename bus,
      int address = 0,
      int mode = 0x40
   >
   class pcf8591 {
   
      static const int base = 0x48;
      
      static int ad_get_base( int n ){
         const unsigned char request = mode + n;
         bus::write( base + address, &request, 1 );
         unsigned char response[ 2 ];
         bus::read( base + address, response, 2 );
         return response[ 1 ];      
      }
   
      template< int n >
      struct ad_pin 
         : public pin_ad_archetype< 8 > 
      {
      
         static void ad_init(){
            bus::init();
         }
         
         static int ad_get(){
            return ad_get_base( n );
         }
         
      };
      
      struct da_pin {
      
         static void da_init(){
            bus::init();
         }      
         
         static void da_set( int x ){
            unsigned char request[ 2 ] = { mode, (unsigned char) x };
            bus::write( base + address, request, 2 );
         };
                 
      };
      
   public:
            
      typedef ad_pin< 0 > ain0;
      typedef ad_pin< 1 > ain1;
      typedef ad_pin< 2 > ain2;
      typedef ad_pin< 3 > ain3;
      
      typedef da_pin aout;
      
   };
   
}; // namespace hwcpp