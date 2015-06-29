#include "cout.hpp"
#include "hwcpp.hpp"
#include "LPC8xx.h"

// ==========================================================================
//
// LPC810 target base stuff
//
// ==========================================================================

namespace hwcpp {

template< int ram_size, int rom_size, int clock_frequency >
class lpc810_base 
   : public target_archetype< ram_size, rom_size, clock_frequency >
{
protected:

   //! return the pointer to an IO port related register
   static constexpr volatile int *gpioreg( int port, int offset ){
      return (volatile int *)( 0xA0001000 + port * 0x10000 + offset );
   }
     
   //========================================================================
   //
   // configure a pin as GPIO
   //
   //========================================================================
   
   static void pin_gp_conf( volatile uint32_t *p, int value ){
      *p = value | ( *p & ~0x07 );
   }   
   
   template< int port, int pin >
   static void configure_as_gpio(){
      LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);      // enable GPIO
      LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);      // enable switchmatrix

      
      switch( ( port << 8 ) | pin ){
         case 0x0000: LPC_SWM->PINENABLE0 |= ( 0x01 << 0 ); break;
         case 0x0001: LPC_SWM->PINENABLE0 |= ( 0x01 << 1 ) | ( 0x01 << 7 ); break;
         case 0x0002: LPC_SWM->PINENABLE0 |= ( 0x01 << 3 ); break;
         case 0x0003: LPC_SWM->PINENABLE0 |= ( 0x01 << 2 ); break;
         case 0x0004: break;
         case 0x0005: LPC_SWM->PINENABLE0 |= ( 0x01 << 6 ); break;
      }         
   }   
   
   static void direction_set_output( int port, int pin ){
      *gpioreg( port, 0x1000 ) |= ( 0x01 << pin );
   }
   
   static void direction_set_input( int port, int pin ){
      *gpioreg( port, 0x1000 ) &= ~ ( 0x01 << pin );
   }   
       
   template< int port, int pin >  
   static void set( bool x ){
      //*gpioreg( port, 0x04 * pin ) = x ? -1 : 0;  
      if( x ){
         LPC_GPIO_PORT->PIN0 |= ( 0x01 << pin ); 
      } else {
         LPC_GPIO_PORT->PIN0 &= ~( 0x01 << pin ); 
      }
   }    

   template< int port, int pin >  
   static bool get(){
      return LPC_GPIO_PORT->PIN0 & ( 0x01 << pin );  
   }
      
   template< int port, int pin >
   class pin_in_out : public pin_in_out_archetype {
   public:
   
      // check whether the port/pin combination is valid for this chip
      static_assert( (
            (( port == 0 ) && ( pin >= 0 ) && ( pin <= 0x0B ))
         || (( port == 1 ) && ( pin >= 0 ) && ( pin <= 0x09 ))
      ), "illegal port/pin combination for an LPC1114" ); 
      
      static void init(){
         lpc810_base::configure_as_gpio< port, pin >();
      } 
    
      static void direction_set_input(){
         lpc810_base::direction_set_input( port, pin );
      }
    
      static void direction_set_output(){
         lpc810_base::direction_set_output( port, pin );
      }
      
      static void set( bool x ){
         lpc810_base::set< port, pin >( x );
      }     
      
      static bool get(){
         return lpc810_base::get< port, pin >();
      }       
   };
   
   static void initialize_clock(){
      static_assert( 
         ( clock_frequency == 1 * MHz ) || ( clock_frequency == 12 * MHz ), 
         "lpc810 : unsupported clock frequency" 
      );
      
      if( clock_frequency < 20 * MHz ){
      
         // configure 1-cycle FLASH access
         // (default i2 2-cycle)
         uint32_t x = LPC_FLASHCTRL->FLASHCFG;
         x &= ~ 0x03;
         LPC_FLASHCTRL->FLASHCFG = x;
         
      }   
      
      if( clock_frequency == 1 * MHz ){
      
         LPC_SYSCON->SYSAHBCLKDIV = 12;  
         
      } else if( clock_frequency == 12 * MHz ){
      
         // nothing required, this is the default
         
      } 
   }   
   
   struct waiting_32 
      : public waiting_support < 
           unsigned int, 
           ( clock_frequency >= 3 * MHz ) 
              ? ( clock_frequency ) / ( 3 * MHz ) 
              : 1
        >
   {
      
      typedef unsigned int base;
   
      static void init(){
         initialize_clock();      
      }
      
      static void wait( const base x ){
         asm volatile( 
            "   mov r0, %[reg]   \t\n"
            "   b   1f           \t\n"
            "   .align 4         \t\n"
            "1: sub r0, %[step]  \t\n" 
            "   bgt 1b           \t\n" 
            :: 
            [reg] "r" (x), 
            [step] "I" ( 
               ( clock_frequency >= ( 3 * MHz ))
               ? 1
               : ( 3 * MHz ) / clock_frequency
            )   
            : "r0"
         );
      }    
       
   }; 

       
};
       
}; // namespace hwcpp
