#include "targets/lpc810m021fn8.hpp"

extern "C" {
   #include "lpc810lib.h"
}

typedef hwcpp::lpc810m021fn8<> target;
typedef target::waiting timing;

void pin_configure_as_input( int pin ){
   switch( pin ){
      case 0 :
         hwcpp::pin_in_from< target::gpio_0_0 >::init();
         break;
      case 1 :
         hwcpp::pin_in_from< target::gpio_0_1 >::init();
         break;
      case 2 :
         hwcpp::pin_in_from< target::gpio_0_2 >::init();
         break;
      case 3 :
         hwcpp::pin_in_from< target::gpio_0_3 >::init();
         break;
      case 4 :
         hwcpp::pin_in_from< target::gpio_0_4 >::init();
         break;
      case 5 :
         hwcpp::pin_in_from< target::gpio_0_5 >::init();
         break;
   }      
}

void pin_configure_as_output( int pin ){
   switch( pin ){
      case 0 :
         hwcpp::pin_out_from< target::gpio_0_0 >::init();
         break;
      case 1 :
         hwcpp::pin_out_from< target::gpio_0_1 >::init();
         break;
      case 2 :
         hwcpp::pin_out_from< target::gpio_0_2 >::init();
         break;
      case 3 :
         hwcpp::pin_out_from< target::gpio_0_3 >::init();
         break;
      case 4 :
         hwcpp::pin_out_from< target::gpio_0_4 >::init();
         break;
      case 5 :
         hwcpp::pin_out_from< target::gpio_0_5 >::init();
         break;
   }   
}

void pin_set( int pin, unsigned char x ){
   switch( pin ){
      case 0 :
         target::gpio_0_0::set( x );
         break;
      case 1 :
         target::gpio_0_1::set( x );
         break;
      case 2 :
         target::gpio_0_2::set( x );
         break;
      case 3 :
         target::gpio_0_3::set( x );
         break;
      case 4 :
         target::gpio_0_4::set( x );
         break;
      case 5 :
         target::gpio_0_5::set( x );
         break;
   } 
}

unsigned char pin_get( int pin ){
   switch( pin ){
      case 0 :
         return target::gpio_0_0::get();
         break;
      case 1 :
         return target::gpio_0_1::get();
         break;
      case 2 :
         return target::gpio_0_2::get();
         break;
      case 3 :
         return target::gpio_0_3::get();
         break;
      case 4 :
         return target::gpio_0_4::get();
         break;
      case 5 :
         return target::gpio_0_5::get();
         break;
   } 
   return 0;
}

void wait_us( int n ){
   static unsigned char init_done = 0;
   if( ! init_done ){
      init_done = 1;
      timing::init();      
   }
   timing::wait( timing::duration::us( n ) );
}
