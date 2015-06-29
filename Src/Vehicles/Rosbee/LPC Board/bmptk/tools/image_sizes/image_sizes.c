#include <stdio.h>
#include <stdlib.h>

int read_line(FILE *file, char *buf ){
   int c;
   for(;;){
      c = getc( file );
      if( c == EOF ) return 0;
	  if( c == '\n' ) break;
      *buf++ = c;
   }
   *buf++ = '\0';
   return 1;
}

void find( const char *s, const char *p, int *n ){
   char a[ 4096 ] = "", b[4096]= "";
   //printf( "[%s]\n", s );
   //sscanf( s, " 0x[0-9A-F] %s", &f );
   sscanf( s, " 0x%s %s", &a, &b );
   //printf( "===>[%s]\n", b );   	
   if( 0 == strcmp( p, b )){
   	  sscanf( a, "%Xd", n );
      printf( " found [%s] = 0x%0X\n", p, *n );
   }
}

void check( int n, char *s ){
   if( n < 0 ){
      printf( "no %s value found\n", s )   	;
      exit( 0 );
   }
}

int used( int n, int m ){
   return (( m - 1 ) + ( 100 * n )) / m;
}

int main(int argc, char *argv[]) {
   char s[ 4096 ];
   int rom_start = -1, rom_end = -1;
   int ram_start = -1, ram_end = 1;
   int text_start = -1, text_end = -1;
   int data_start = -1, data_end = -1;
   int bss_start = -1, bss_end = -1;
   int stack_start = -1, stack_end = -1;
   int heap_start = -1, heap_end = -1;
   FILE *f;
   f = fopen( argv[1], "r" );
   while( read_line( f, s )){
   	   find( s, "__rom_start",   &rom_start );
   	   find( s, "__rom_end",     &rom_end );
   	   
   	   find( s, "__ram_start",   &ram_start );
   	   find( s, "__ram_end",     &ram_end );
   	   
   	   find( s, "__text_start",  &text_start );
   	   find( s, "__text_end",    &text_end );
   	   
   	   find( s, "__data_start",  &data_start );
   	   find( s, "__data_end",    &data_end );
   	   
   	   find( s, "__bss_start",   &bss_start );
   	   find( s, "__bss_end",     &bss_end );
   	   
   	   find( s, "__stack_start", &stack_start );
   	   find( s, "__stack_end",   &stack_end );
   	   
   	   find( s, "__heap_start",  &heap_start );
   	   find( s, "__heap_end",    &heap_end );
   }
   check( rom_start, "rom_start" );   check( rom_end, "rom_end" );
   check( rom_start, "ram_start" );   check( rom_end, "ram_end" );
   check( rom_start, "text_start" );  check( rom_end, "text_end" );
   check( rom_start, "data_start" );  check( rom_end, "data_end" );
   check( rom_start, "bss_start" );   check( rom_end, "bss_end" );
   check( rom_start, "stack_start" ); check( rom_end, "stack_end" );
   check( rom_start, "heap_start" );  check( rom_end, "heap_end" );

   int rom_size = rom_end - rom_start;
   int ram_size = ram_end - ram_start;
   int rom_used = text_end - text_start;
   int ram_used = bss_end - ram_start;
   printf( 
      "   ROM: %d/%d (%d%%)   RAM: %d/%d (%d%%)\n", 
      rom_used, rom_size, used( rom_used, rom_size ),
      ram_used, ram_size, used( ram_used, ram_size )
   );
   printf( 
      "   DATA: %d   BSS: %d   STACK: %d   HEAP: %d\n",
      data_end - data_start,
      bss_end - bss_start,
      stack_end - stack_start,
      heap_end - heap_start
   );
   
   close( f );
   return 0;
}
