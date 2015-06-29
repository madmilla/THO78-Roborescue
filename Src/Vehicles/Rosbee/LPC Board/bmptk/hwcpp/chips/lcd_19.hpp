namespace hwcpp {

   template< 
      class _cd, class _e,
      class _cs1, class _cs2,
      class _data_bus,
      class timing
   >   
   class lcd_19 
      : public 
         archetypes::frame < archetypes::vector< 128, 64 >>, 
         archetypes::frame_readable 
   {
   
      typedef pin_out_from< _cd  > cd;
      typedef pin_out_from< _e   > e;
      typedef pin_out_from< invert< _cs1 >> cs1;
      typedef pin_out_from< invert< _cs2 >> cs2;
      typedef port_out_from< _data_bus > data_bus;
      
      static unsigned char buf[ 1024 ];
      
      static const int cmd_on          = 0x3F;
      static const int cmd_off         = 0x3E;
      static const int cmd_page        = 0xB8;
      static const int cmd_address     = 0x40;
      static const int cmd_first_line  = 0xC0;
      
      static void address_set( int x, int y ){
         //
         // for a two-chip dipslay:
         //
         //    x input bits:   6    5   4   3   2   1   0
         //                   chip  ======== x ==========
         //
         //    y input bits:   5   4    3   2   1   0 
         //                    = y byte =   = y bit =
         //
         int chip = ( x >> 6 ) & 0x01;
         int page = ( y >> 3 ) & 0x07;
         int address = x & 0x3F;
         chip_select( chip );
         command( cmd_page + page );
         command( cmd_address + address );         
      }
      
      static void command_or_data( int x, bool cmd ){
         data_bus::set( x );
         cd::set( cmd );
         
         // toggle the E pin
         e::set( 1 );
         timing::wait( 1 * timing::us );
         e::set( 0 );   
         timing::wait( 1 * timing::us );        
      }     
      
   public:
   
      static void chip_select( int x ){
         cs1::set( x == 0 ); 
         cs2::set( x != 0 );
      }
      
      static void command( int x ){
         command_or_data( x, 0 );
      }
      
      static void data( int x ){
         command_or_data( x, 1 );
      }
	 
      static void init(){
         cd::init();
         e::init();
         cs1::init();
         cs2::init();
         data_bus::init();
         e::set( 0 );
         timing::wait( 100 * timing::ms );
         cs1::set( 0 );
         cs2::set( 1 );
         for( int i = 0; i < 2; i++ ){
            chip_select( i );
            command( cmd_on );
            command( cmd_first_line + 0 );
         }   
      }
      
      static void pixel_write( vector p, color c ){
         if( frame< archetypes::vector< 128, 64 > >::is_valid( p )){
            int index = p.x_get() + (( p.y_get() / 8 ) * 128 );
            if( c == black ){
               buf[ index ] |= 1 << ( p.y_get() % 8 );
            } else {
               buf[ index ] &= ~ ( 1 << ( p.y_get() % 8 ));
            }
            address_set( p.x_get(), p.y_get() );
            data( buf[ index ] );         
         }   
      }
   
      static color pixel_read( vector p ){
         if( frame< archetypes::vector< 128, 64 > >::is_valid( p )){
            int index = p.x_get() + (( p.y_get() / 8 ) * 128 );
            if( buf[ index ] & ( 1 << ( p.y_get() % 8 )) ){
               return black;
            } else {
               return white;
            }        
         } else {
            return bg;
         }
      }
   
      static void clear( color c = white ){
         bg = c;      
         for( int x = 0; x < size::x ; x++ ){
            for( int y = 0; y < size::y; y++ ){
               pixel_write( vector( x, y ), c );
            }
         }          
      } 
      
   };
   
   // buf instance
   template <
      class _cd, class _e,
      class _cs1, class _cs2,
      class _data, class timing
   > unsigned char lcd_19< _cd, _e, _cs1, _cs2, _data, timing >::buf[ 1024 ];
   
}; // namespace hwcpp
