// ==========================================================================
//
// File      : spi.hpp
// Part of   : hwcpp library (www.voti.nl/hwcpp)
// Copyright : wouter@voti.nl 2014
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

namespace hwcpp {

   enum class spi_mode {
   
      // In this mode the clock is low when idle, 
      // and data is present before first clock edge,
      // to be sampled at that edge.
      mode_0 = 0, 
      
      // In this mode the clock is low when idle, 
      // and data is presented at the first clock edge,
      // to be sampled at the second clock edge.
      mode_1 = 1, 
   
      //! In this mode the clock is high when idle, 
      //! and data is present before first clock edge,
      //! to be sampled at that edge.
      mode_2 = 2, 
   
      //! In this mode the clock is high when idle, 
      //! and data is presented at the first clock edge,
      //! to be sampled at the second clock edge.
      mode_3 = 3
   };
   
   
   // =======================================================================
   //
   // SPI bus archetype (can shared by a number of channels)
   //
   // =======================================================================
   
   struct spi_bus_archetype {
      typedef void has_spi_bus;
      typedef void timing;
      static void init();
      
      // SPI read-and-write operation on 0..8 bits
      template< int n_bits = 8 >
      static void byte_out_in(
         unsigned char out,
         unsigned char &in
      );

   };   
   
   
   // =======================================================================
   //
   // SPI channel archetype (to one chip, builds on a spi bus)
   //
   // =======================================================================
   
   struct spi_channel_archetype {
      typedef void has_spi_channel;
      typedef void timing;
      static void init();
      
      // read-and-write transaction
      static void transaction_out_in_n( 
         unsigned const char output[], 
         unsigned char input[], 
         int n_bytes 
      );
      
      // read-only transaction
      static void transaction_in_n( 
         unsigned char input[], 
         int n_bytes 
      );

      // write-only transaction    
      static void transaction_out_n( 
         unsigned const char output[], 
         int n_bytes 
      );      

   };
   
   
   // =======================================================================
   //
   // a simple bit-banged SPI bus implementation
   //
   // =======================================================================
   
   template< 
      class arg_sclk,
      class arg_mosi, 
      class arg_miso,
      class frequency,
      spi_mode mode = spi_mode::mode_0
   > 
   class spi_bus_sclk_mosi_miso_bb : public spi_bus_archetype {
   private:
    
      HARDWARE_REQUIRE_ARCHETYPE( frequency, has_frequency );
     
      // convert the pins to the appropriate kind
      // (and assert that this is possible)
      typedef pin_out_from< arg_sclk > sclk;
      typedef pin_out_from< arg_mosi > mosi;
      typedef pin_in_from< arg_miso > miso;
       
      static constexpr bool spi_mode_data_first( const spi_mode m ){
         return ( m == spi_mode::mode_0 ) || ( m == spi_mode::mode_2 );
      }
   
      static constexpr bool spi_mode_active_clock( const spi_mode m ){
         return ( m == spi_mode::mode_0 ) || ( m == spi_mode::mode_1 );
      }   
   
   public:   
   
      typedef typename frequency::service timing;
   
      static void init(){
         frequency::init();
         sclk::init();
         sclk::set( ! spi_mode_active_clock( mode ));
         mosi::init();
         miso::init();
      }      
      
      // send and receive up to 8 bits in each direction
      template< int n_bits = 8 >
      static void byte_out_in(
         unsigned char out,
         unsigned char &in
      ){
         static_assert( 
            ( 0 <= n_bits ) && ( n_bits <= 8 ),
            "n_bits must be 0..8"
         );   
      
         in = 0;
         sclk::set( ! spi_mode_active_clock( mode ));
         frequency::half_period::wait();
         
         out = out << ( 8 - n_bits );
         
         for( int i = 0; i < n_bits; i++ ){
         	
            in = in << 1;
            
            if( spi_mode_data_first( mode )){
        
               mosi::set( out & 0x80 );
               frequency::half_period::wait();
         
               sclk::set( spi_mode_active_clock( mode ));
               if( miso::get() ){
                  in |= 0x01;
               }
               
               frequency::half_period::wait();
               sclk::set( ! spi_mode_active_clock( mode ));
         
            } else {
   
               sclk::set( ! spi_mode_active_clock( mode ));
               frequency::half_period::wait();
          
               mosi::set( out & 0x80 );
               sclk::set( spi_mode_active_clock( mode ));
               frequency::half_period::wait();
         
               if( miso::get() ){
                  in |= 0x01;
               }      
            }
            out = out << 1;
         }   
      } 
               
   };     
   
   
   // =======================================================================
   //
   // a SPI channel implementation
   //
   // =======================================================================
   
   template< 
      typename bus,
      typename arg_ss
   > class spi_channel_bb : public spi_channel_archetype {
   private:
      
      HARDWARE_REQUIRE_ARCHETYPE( bus, has_spi_bus );

      // convert the ss pin to output
      // (and assert that this possible!)
      typedef pin_out_from< arg_ss > ss;   
      
      typedef typename bus::timing::template mutex< spi_channel_bb > bus_access;
      
   public:
   
      typedef typename bus::timing timing;

      static void init(){
         bus::init();
         ss::init();  
         ss::set( 0 ); 
      }
      
      // simulateous read-and-write transaction
      static void transaction_out_in_n( 
         unsigned const char output[], 
         unsigned char input[], 
         int n_bytes 
      ){
         typename bus_access::lock exclusive_bus_access;
      
         ss::set( 1 );
         	
         while( n_bytes-- ){
            unsigned char in, out = 0;
            if( output ){
               out = *output++;
            }   
            bus::byte_out_in( out, in );   
            if( input ){
              *input++ = in;
            }
         }      
         
         ss::set( 0 );
      }
      
      // read-only transaction
      static void transaction_in_n( 
         unsigned char input[], 
         int n_bytes 
      ){
         transaction_out_in_n( nullptr, input, n_bytes );
      }
      
      // write-only transaction
      static void transaction_out_n( 
         unsigned const char output[], 
         int n_bytes 
      ){
         transaction_out_in_n( output, nullptr, n_bytes );
      }     
      
   };   

}; // namespace hwcpp