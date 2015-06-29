namespace hwcpp {

   // seems to work for XPT2046 too

   template< typename channel >
   struct ads7843 {
   
      static void init(){
         channel::init();
      }
      
      static int read_by_command( int cmd ){
         unsigned char command[ 3 ], result[ 3 ];
         command[ 0 ] = cmd;
         channel::transaction_out_in_n( command, result, 3 );      
         return ( result[ 1 ] << 8 ) + result[ 2 ];          
      }
      
      static void read( int &x, int &y ){      
         x = read_by_command( 0x90 );
         y = read_by_command( 0xD0 );
      }
      
      class x : public archetypes::pin_ad< 12 >{
         static void ad_init(){}
         static int ad_get(){ return read_by_command( 0x90 ); }
      };      
      
      class y : public archetypes::pin_ad< 12 >{
         static void ad_init(){}
         static int ad_get(){ return read_by_command( 0xD0 ); }
      };      
      
   };

}; // namespace hwcpp

