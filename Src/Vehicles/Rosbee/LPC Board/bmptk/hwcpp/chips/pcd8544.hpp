namespace hwcpp {

//! create a frame controlled by a pcd8544 LCD controller 
template<
   typename _sce,
   typename _res,
   typename _dc,
   typename _sdin,
   typename _sclk,
   class tsize,
   class timing
> class pcd8544 
   : public 
      archetypes::frame< tsize >, 
      archetypes::frame_readable 
{
private:

   typedef pin_out_from< _sce  > sce;
   typedef pin_out_from< _res  > res;
   typedef pin_out_from< _dc   > dc;
   typedef pin_out_from< _sdin > sdin;
   typedef pin_out_from< _sclk > sclk;
	
   static unsigned char buf[ (( tsize::x * tsize::y ) + 7 ) / 8 ];
	
   static void send_byte( unsigned char d ){
      for( int i = 0; i < 8; i++ ){
         sdin::set( d & 0x80 );         
   	   timing::wait( 1 * timing::us );
         sclk::set( 1 );
         d = d << 1;
   	   timing::wait( 1 * timing::us );
         sclk::set( 0 );
      }
   }    
   
   static void data( unsigned char d ){
      dc::set( 1 );
      sce::set( 0 );
      send_byte( d );
      sce::set( 1 );
   } 	
   
   static void pixels( unsigned char x, unsigned char y, unsigned char d ){
      command( 0x80 | x );   
      command( 0x40 | y );  
      data( d );
   }
   
protected:   
   
   //! send  command to the controller chip
   static void command( unsigned char d ){
      dc::set( 0 );
      sce::set( 0 );
      send_byte( d );
      sce::set( 1 );
   } 	

public:	

   //! construct the controller
   //
   //! The argument is the size of the frame
   //! The initialization of the controller is 
   //! LCD-specific and must be done by the derived type.
   static void init(){ 
      sce::init();
      res::init();
	   dc::init();
	   sdin::init();
	   sclk::init();

  	  sclk::set( 0 );
     timing::wait( 1 * timing::us );
     sce::set( 1 );
     timing::wait( 1 * timing::us );
	  res::set( 0 );
     timing::wait( 1 * timing::us );
	  res::set( 1 ); 
 	  timing::wait( 1 * timing::us );
	   
      // initialization is not done here
   }	
   
   //! \copydoc bmptk::graphics::frame::checked_write
   static void pixel_write( vector p, color c ){
      if( archetypes::frame< tsize >::is_valid( p )){
         unsigned int a = p.x_get() + ( p.y_get() / 8 ) * 84;
         unsigned int m = 1 << ( p.y_get() % 8 );
         if( c == black ){
            buf[ a ] |= m;
         } else {     
            buf[ a ] &= ~m;
         }
         pixels( p.x_get(), p.y_get() / 8, buf[ a ] );         
      }   
   }
   
   static color pixel_read( vector p ){
      if( archetypes::frame< tsize >::is_valid( p )){
         unsigned int a = p.x_get() + ( p.y_get() / 8 ) * 84;
         unsigned int m = 1 << ( p.y_get() % 8 );
         if( buf[ a ] & m ){
            return black;
         } else {     
            return white;
         }       
      } else {
         return archetypes::frame< tsize >::bg;
      }
   }
   
   //! \copydoc bmptk::graphics::frame::clear
   static void clear( color c = white ){
      unsigned char fill = ( c == white ? 0 : 0xFF );
      command( 0x80 | 0 );   
      command( 0x40 | 0 );  
      for( int i = 0; i < 504; i++ ){
         buf[ i ] = fill;
         data( fill );
      }         
   }

};

// buf instance
template <
   typename sce,
   typename res,
   typename dc,
   typename sdin,
   typename sclk,
   class tsize,
   class timing
> unsigned char pcd8544 < 
   sce, res, dc, sdin, sclk, tsize, timing
>::buf[ (( tsize::x * tsize::y ) + 7 ) / 8 ];

//! create a frame for an generic 5510 LCD
template<
   typename sce,
   typename res,
   typename dc,
   typename sdin,
   typename sclk,
   class timing
> class lcd5510 : public pcd8544 < 
   sce, res, dc, sdin, sclk, archetypes::vector< 84, 48 >, timing > {

   static void command( unsigned char d ){ 
      pcd8544< sce, res, dc, sdin, sclk, archetypes::vector< 84, 48 >, timing >
         ::command( d ); 
   }

public:

   static void init(){
      pcd8544< sce, res, dc, sdin, sclk, archetypes::vector< 84, 48 >, timing >
         ::init(); 
      command( 0x21 );  // select exteded instructions
      command( 0xC8 );  // Vop = 110000b
      command( 0x06 );  // TCx = 00b
      command( 0x13 );  // BSx = 100b
      command( 0x20 );  // select basic instructions, horizontal addressing
      command( 0x0C );  // normal mode  
   }	  
};

} // namespace hwcpp