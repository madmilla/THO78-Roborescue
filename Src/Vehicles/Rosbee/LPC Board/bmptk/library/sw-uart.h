/**
*               __
*    _________ / /_  ____  ________  ____________  _____
*   /___/ __ \/ __ \/ __ \/ ___/ _ \/ ___/ ___/ / / / _ \
*  / / / /_/ / /_/ / /_/ / /  /  __(__  ) /__/ /_/ /  __/
* /_/  \____/_.___/\____/_/   \___/____/\___/\__,_/\___/
*
*
* @file main.c
* @date Created: 17-06-2015
*
* @author Kyle Taylor Parkins, Floris Rijker
*
* @section LICENSE
* License: newBSD
*
* Copyright © 2015, HU University of Applied Sciences Utrecht.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

//! @file
//! This library implements a bit-banged output-only UART at
//! the baudrate specified by BMPTK_BAUDRATE.

//! initialize the UART 
//
//! Call this function to initialize the UART pins.
void uart_init( void );

//! write a single character
//
//! This function writes a single character using the standard UART
//! output pin of the chip (GP1_7) and the baudrate BMPTK_BAUDRATE,
//! which is passed as a command line argument during compilation.
void uart_put_char( char c );

//! write a character string
//
//! This function writes the characters of a standard 0-terminated string
//! using uart_put_char().
void uart_put_string( char *s );

//! writes an integer in decimal format without leading zero's.
//
//! This function writes an integer in decimal format, without
//! any leading zero's, using using uart_put_char().
//! A negative value will have a '-' in front of it.
//! Writing INT_MIN will not work as expected.
void uart_put_int_decimal( int x );


//! writes an unsigend integer as n hexadecimal digits
//
//! This function writes an unsigend integer as n hexadecimal (0-F) digits.
//! Digits higher than n will be ignored.
void uart_put_int_hexadecimal( unsigned int x, int n );	
