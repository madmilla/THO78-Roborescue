//***************************************************************************
//
// file : bmptk/bmptk.h
//
// Copyright (c) 2012 ... 2014 Wouter van Ooijen (wouter@voti.nl)
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// This is the one header file a user should include to
// use the bmptk core facilities.
//
//***************************************************************************

#ifndef _BMPTK_H
#define _BMPTK_H

// ==========================================================================
// 
// version
//
// ==========================================================================

//! helper macro for the bmtkp version
#define BMPTK_VERSION_STR( X ) #X

//! bmtkp version, determined by Makefile.inc
const char version[] = BMPTK_VERSION_STR( BMPTK_VERSION );	


// ==========================================================================
// 
// debug macro's
//
// ==========================================================================

//! file-name : line-number macro
//
//! The macro BMPTK_HERE transates to a newline, the file-name, ":",
//! and the line-number of the place where the BMPTK_HERE macro
//! appears. This is usefull for debug logging.
#define BMPTK_HERE_STR( X ) #X
#define BMPTK_HERE2( F, L ) ( "\n" F ":" BMPTK_HERE_STR( L ) " " )
#define BMPTK_HERE BMPTK_HERE2( __FILE__, __LINE__ )

            
// ==========================================================================
// 
// include the target-specific header file
//
// ==========================================================================
            
#ifdef BMPTK_TARGET_nds
   #include "targets/nds/nds.h"
#endif              
#ifdef BMPTK_TARGET_win
   #include "targets/win/win.h"
#endif              
#ifdef BMPTK_CHIP_lpc810m021
   #include "targets/cortex/lpc810m021.h"
#endif              
#ifdef BMPTK_CHIP_lpc1114fn28
   #include "LPC11xx.h"
#endif              
#ifdef BMPTK_CHIP_lpc1227fbd301
   #include "targets/cortex/lpc1227fbd301.h"
#endif              
#ifdef BMPTK_CHIP_lpc2478
   #include "targets/armv7/lpc2478.h"
#endif              
      
#endif // #ifndef _BMPTK_H
