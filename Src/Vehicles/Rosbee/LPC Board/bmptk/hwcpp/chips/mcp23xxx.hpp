namespace hwcpp {

   // =======================================================================
   //
   // adapters on top of i2c and spi
   //
   // =======================================================================

   template<
      typename bus,
      int chip_address
   > 
   struct mcp23_i2c {
   
      HARDWARE_REQUIRE_ARCHETYPE( bus, has_i2c_bus );         
   
      static void init(){
         bus::init();
      }   
      
      static void register_read( unsigned char reg, unsigned char &value ){
         bus::write( chip_address, &reg, 1 );
         bus::read( chip_address, &value, 1 );
      }
      
      static void register_write( unsigned char reg, unsigned char value ){
         unsigned char msg[ 2 ] = { reg, value };
         bus::write( chip_address, msg, 2 );
      }               
   };      
      
   template<
      typename channel,
      int chip_address
   > 
   struct mcp23_spi {
   
      HARDWARE_REQUIRE_ARCHETYPE( channel, has_spi_channel );         
      
      static void init(){
         channel::init();
      }   
      
      static void register_read( unsigned char reg, unsigned char &value ){
         unsigned char req[ 3 ] = { 
            (( chip_address + 0x20 ) << 1) + 1, 
            reg,
            0 
         };
         unsigned char resp[ 3 ];
         channel::byte_in_out( req, resp, 3 );
         value = resp[ 2 ];
      }
      
      static void register_write( unsigned char reg, unsigned char value ){
         unsigned char req[ 3 ] = { 
            ( chip_address + 0x20 ) << 1, 
            reg, 
            value
         };
         channel::byte_out( req, 3 );
      }               
   };      
   
   // =======================================================================
   //
   // pin and port logic
   //
   // =======================================================================

   template < 
      typename chip,
      int register_base
   > 
   class mcp_gpio :
      public port_in_out_archetype< 8 >
   {
         
      static unsigned char port, direction, pullups;
      
      static void direction_flush(){
         chip::register_write( register_base + 0x00, direction );
      }
      
      static void port_flush(){
         chip::register_write( register_base + 0x0A, port );
      }
      
      static void pullups_flush(){
         chip::register_write( register_base + 0x06, pullups );
      }
      
      template< int n >
      struct pin 
         : public 
            pin_in_out_archetype, 
            pin_configurable_pullup_archetype 
      {
         
         static void init () {
            chip::init();
         }
         
         static void direction_set_input(){
            direction |= ( 0x01 << n );
            direction_flush();
         }
         
         static void direction_set_output(){
            direction &= ~( 0x01 << n );
            direction_flush();            
         }
         
         static void pullup_enable(){
            pullups |= ( 0x01 << n );
            pullups_flush();            
         }
         
         static void pullup_disable(){
            pullups &= ~( 0x01 << n );
            pullups_flush();            
         }
         
         static void set( bool value ){
            if( value ){
               port |= ( 0x01 << n );
            } else {
               port &= 0xFF ^ ( 0x01 << n );
            } 
            port_flush();
         }
         
         static bool get(){
            unsigned char x;
            chip::register_read( register_base + 0x09, x );
            return x & ( 0x01 << n );         
         }
         
      };
      
   public:
      typedef typename port_in_out_archetype< 16 >::value_type value_type;

      static void init(){
         chip::init();
      } 
      
      static void direction_set_input(){
         direction = 0xFF;
         direction_flush();
      }
      
      static void direction_set_output(){
         direction = 0x00;
         direction_flush();
      }
      
      static void pullup_enable(){
         pullups = 0xFF;
         pullups_flush();
      }
      
      static void pullup_disable(){
         pullups = 0x00;
         pullups_flush();
      }
      
      static value_type get(){
         unsigned char x;
         chip::register_read( register_base + 0x09, x );
         return x;
      }
      
      static void set( value_type x ){
         port = x;
         port_flush();
      }
      
      typedef pin< 0 > gp0;
      typedef pin< 1 > gp1;
      typedef pin< 2 > gp2;
      typedef pin< 3 > gp3;
      typedef pin< 4 > gp4;
      typedef pin< 5 > gp5;
      typedef pin< 6 > gp6;
      typedef pin< 7 > gp7;
      
   }; // mcp_gpio
   
   template < 
      typename chip,
      int register_base
   > 
   unsigned char mcp_gpio< chip, register_base>::port;
   
   template < 
      typename chip,
      int register_base
   > 
   unsigned char mcp_gpio< chip, register_base>::direction;
   
   template < 
      typename chip,
      int register_base
   > 
   unsigned char mcp_gpio< chip, register_base>::pullups;
   
   
   // =======================================================================
   //
   // the dual-port chip
   //
   // =======================================================================
   
   template < 
      typename i2c,
      int address
   >
   struct mcp_gpio_2 :
      public port_in_out_archetype< 16 >
   {
      
      HARDWARE_REQUIRE_ARCHETYPE( i2c, has_i2c_bus );     

      typedef typename port_in_out_archetype< 16 >::value_type value_type;

      typedef mcp_gpio< 
         mcp23_i2c< i2c, 0x20 + address >, 
         0x00 
      > porta;
      
      typedef mcp_gpio< 
         mcp23_i2c< i2c, 0x20 + address >, 
         0x10 
      > portb;
      
      static void init(){
         porta::init();
         portb::init();
      }
      
      static void direction_set_input(){
         porta::direction_set_input();
         portb::direction_set_input();
      }
      
      static void direction_set_output(){
         porta::direction_set_output();
         portb::direction_set_output();
      }
      
      static void set( value_type x ){
         porta::set( (typename porta::value_type) x );
         portb::set( (typename portb::value_type) x >> 8 );
      }
      
      static value_type get() {
         return porta::get() | (((value_type) portb::get()) << 8 );
      }
           
      typedef typename porta::gp0 gpa0;
      typedef typename porta::gp1 gpa1;
      typedef typename porta::gp2 gpa2;
      typedef typename porta::gp3 gpa3;
      typedef typename porta::gp4 gpa4;
      typedef typename porta::gp5 gpa5;
      typedef typename porta::gp6 gpa6;
      typedef typename porta::gp7 gpa7;
 
      typedef typename portb::gp0 gpb0;
      typedef typename portb::gp1 gpb1;
      typedef typename portb::gp2 gpb2;
      typedef typename portb::gp3 gpb3;
      typedef typename portb::gp4 gpb4;
      typedef typename portb::gp5 gpb5;
      typedef typename portb::gp6 gpb6;
      typedef typename portb::gp7 gpb7;
 
   };
   
   // =======================================================================
   //
   // the chips
   //
   // =======================================================================
   
   template<
      class i2c,
      int address
   >
   struct mcp23008 : public mcp_gpio< 
      mcp23_i2c< i2c, 0x20 + address >, 
      0x00
   >{
      HARDWARE_REQUIRE_ARCHETYPE( i2c, has_i2c_bus );         
   };

   template< 
      class i2c, 
      int address 
   > 
   struct mcp23017 : public mcp_gpio_2< 
      i2c,
      address
   >{
      HARDWARE_REQUIRE_ARCHETYPE( i2c, has_i2c_bus );            
   };
   
}; // namespace hardware   