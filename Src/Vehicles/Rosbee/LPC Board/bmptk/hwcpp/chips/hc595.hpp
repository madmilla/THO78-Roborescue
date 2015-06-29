// ==========================================================================
//
// File      : hc595.hpp
// Part of   : whcpp library (www.voti.nl/hwcpp)
// Copyright : wouter@voti.nl 2014
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

namespace hwcpp {

   template< typename channel >
   class hc595 : 
      public port_out_archetype< 8 > 
   {
   private:
   
      HARDWARE_REQUIRE_ARCHETYPE( channel, has_spi_channel );
   
      static unsigned char buffer;
      
      typedef typename channel::timing::template mutex< hc595 > buffer_access;
      
      static void flush(){
         channel::transaction_out_n( &buffer, 1 ); 
      }   
      
      // implementation of the separate pins: 
      // instatiate this for each pin
      template< int pin > 
      struct pin_template 
         : public pin_out_archetype 
      {
      
         static void init(){
            channel::init();
         }
      
         static void set( bool value ){
            typename buffer_access::lock exclusive_use;
            if( value ){
               buffer |= ( 0x01 << pin );
            } else {
               buffer &= 0xFF ^ ( 0x01 << pin );
            }
            flush();
         }   
      };          
      
   public:
      
      static void init(){
         channel::init();
      }         

      static void set( unsigned int x ){
         typename buffer_access::lock exclusive_use;
         buffer = x;
         flush(); 
      }    
      
      typedef pin_template< 0 > q0; 
      typedef pin_template< 1 > q1; 
      typedef pin_template< 2 > q2; 
      typedef pin_template< 3 > q3; 
      typedef pin_template< 4 > q4; 
      typedef pin_template< 5 > q5; 
      typedef pin_template< 6 > q6; 
      typedef pin_template< 7 > q7; 
      
   }; 
   
   // the static buffer and mutex attributes
   template < typename channel >
   unsigned char hc595< channel >::buffer;

}; // namespace hwcpp
