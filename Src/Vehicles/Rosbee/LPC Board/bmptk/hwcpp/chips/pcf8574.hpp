namespace hwcpp {

   template < 
      typename bus,
      int base,
      int address
   >
   class pcf8574x 
      : public port_oc_archetype< 8 > 
   {
   private:
   
      HARDWARE_REQUIRE_ARCHETYPE( bus, has_i2c_bus );   
   
      static unsigned char buffer;
      
      static void flush(){
         bus::write( base + address, &buffer, 1 );
      }   
      
      static unsigned char read_byte(){
         unsigned char result;
         bus::read( base + address, &result, 1 );   
         return result;
      }
      
      template< int pin > 
      struct pin_template 
         : public pin_oc_archetype 
      {
      
         static void init(){
            bus::init();
         }
      
         static void set( bool value ){
            if( value ){
               buffer |= ( 0x01 << pin );
            } else {
               buffer &= 0xFF ^ ( 0x01 << pin );
            }
            flush();
         }   
         
         static bool get(){
            unsigned char x = read_byte();
            return x & ( 0x01 << pin );
         }
      };          
      
   public:
      
      static void init(){
         bus::init();
      }         

      static void set( unsigned int x ){
         buffer = x;
         flush(); 
      }    
      
      static unsigned int get(){
         return read_byte();
      }
      
      typedef pin_template< 0 > p0; 
      typedef pin_template< 1 > p1; 
      typedef pin_template< 2 > p2; 
      typedef pin_template< 3 > p3; 
      typedef pin_template< 4 > p4; 
      typedef pin_template< 5 > p5; 
      typedef pin_template< 6 > p6; 
      typedef pin_template< 7 > p7; 
      
   }; 
   
   template < typename bus, int base, int address >
   unsigned char pcf8574x< bus, base, address >::buffer;
   
  //! interface for a pcf8547 I2C 8 bit I/O extender
   template< typename bus, int address = 0 > 
   class pcf8574 : public pcf8574x< bus, 0x20, address > {
      HARDWARE_REQUIRE_ARCHETYPE( bus, has_i2c_bus );         
   };
 
   //! interface for a pcf8547a I2C 8 bit I/O extender
   template< typename bus, int address = 0 > 
   class pcf8574a : public pcf8574x< bus, 0x38, address >{
      HARDWARE_REQUIRE_ARCHETYPE( bus, has_i2c_bus );      
   }; 

}; // namespace hwcpp
