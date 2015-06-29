// ==========================================================================
//
// File      : ic2.hpp
// Part of   : hwcpp library (www.voti.nl/hwcpp)
// Copyright : wouter@voti.nl 2014
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

namespace hwcpp {
	
   // =======================================================================
   //
   // I2C bus master archetype 
   //
   // =======================================================================
   
   struct i2c_bus_master_archetype {
   
      typedef void has_i2c_bus;
      
      static void init(); 
      
      // write n bytes from data[] to the slave at address a
      static void write( 
         int a, 
         unsigned const char data[], 
         int n 
      );          
      
      // read n bytes from the slave at addess a to data[]
      static void read( 
         int a, 
         unsigned char data[], 
         int n 
      );
   }; 

   
   // =======================================================================
   //
   // I2C bit-banged bus master implementation
   //
   // =======================================================================
   
	template< 
      class arg_scl, 
      class arg_sda,
      class frequency
   >
   class i2c_bus_master_bb_scl_sda : public i2c_bus_master_archetype { 
   
      HARDWARE_REQUIRE_ARCHETYPE( frequency, has_frequency );   
      
      // add 50ns to satisfy the minimum SCL T-high at 400kHz
      typedef typename frequency::service::template ns< 
         frequency::half_period::duration + 50 > half_period;
   
      // use the pins in an appropriate way
      // (and assert that they can be used as such)   
      typedef pin_oc_from< arg_scl > scl;
      typedef pin_oc_from< arg_sda > sda; 
     
      static void write_bit( bool x ){
         scl::set( 0 );
         half_period::wait();
         sda::set( x );
         scl::set( 1 );
         half_period::wait();
      }
   
      static bool read_bit(){
         scl::set( 0 );
         half_period::wait();  
         sda::set( 1 );
         scl::set( 1 );
         half_period::wait();
         bool result = sda::get();
         half_period::wait();    
         return result;
      }       
     
      static void write_start(){
         sda::set( 0 );
         half_period::wait();
         scl::set( 0 );
         half_period::wait(); 
      }

      static void write_stop(){
         scl::set( 0 );
         half_period::wait();   
         sda::set( 0 );
         half_period::wait();   
         scl::set( 1 );
         half_period::wait();   
         sda::set( 1 );
         half_period::wait();    
      }
       
      static bool read_ack(){
         bool ack = ! read_bit(); 
         return ack;
      } 
   
      static void write_ack(){
         write_bit( 0 );
      }

      static void write_nack(){
         write_bit( 1 );
      }
   
      static void write_byte( unsigned char x ){
         for( int i = 0; i < 8; i++ ){
            write_bit( ( x & 0x80 ) != 0 );
            x = x << 1;
         }         
       }

      static unsigned char read_byte(){
         unsigned char result = 0;
         for( int i = 0; i < 8; i++ ){
            result = result << 1;
            if( read_bit() ){
               result |= 0x01;
            } 
         }   
         return result;     
      }        
   
   public:     
     
      static void init(){
         frequency::init();
         scl::init();
         scl::set( 1 );   		
         sda::init();
         sda::set( 1 );
      }
   
      // This method writes n bytes from *data over the i2c bus 
      // to the the 7-bit i2c address 'address'.
      static void write( unsigned char address, unsigned const char *data, int n ){
         write_start();
         write_byte( address << 1 );
         for( int i = 0; i < n; i++ ){
            read_ack();
            write_byte( data[ i ] );
         }               
         read_ack();
         write_stop();
      }           
   
      // This method reads n bytes over the i2c bus from the 7-bit i2c
      // address 'address' to *data.
      static void read( unsigned char address, unsigned char *data, int n ){
         write_start();
         write_byte( ( address << 1 ) | 0x01 );    
         read_ack();
         for( int i = 0; i < n; i++ ){
            if( i > 0 ){
               write_ack();
            }   
            data[ i ] = read_byte();
         }               
         write_stop();
      }      

   }; // class i2c_bus_master_bb_scl_sda

}; // namespace hwcpp      