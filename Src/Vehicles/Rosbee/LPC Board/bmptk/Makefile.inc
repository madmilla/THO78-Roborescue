#############################################################################
#
# file: bmptk/Makefile.inc
#
# Makefile for bare metal C++ projects
#
# Copyright (c) 2012 ... 2014 Wouter van Ooijen (wouter@voti.nl)
# 
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at 
# http://www.boost.org/LICENSE_1_0.txt)
# 
#############################################################################


# This string must not contain spaces, that does
# (for some unclear reason) not work on Windows8
VERSION := V03.00_work_in_progress_2014_04_07


#============================================================================
#
# Invoke the Makefile.custom (if it exists) or else the Makefile.local,
# to get the locations of the external toolsets
# 
#============================================================================

ifneq ($(wildcard $(BMPTK)/Makefile.custom),)
   include $(BMPTK)/Makefile.custom
else   
   include $(BMPTK)/Makefile.local
endif

# for debugging
# $(error $(WPF) )


#============================================================================
#
# The main project source file is sure part of the project.
# It is specified with extension: here we find the a .asm, .c or .cpp file
#
# the default project name is 'main'
# 
#============================================================================

ifeq ($(MAKECMDGOALS),clean)
   NOPROJECT = 1
endif
ifeq ($(MAKECMDGOALS),doxygen)
   NOPROJECT = 1
endif

ifeq ($(PROJECT),)
   PROJECT = main
endif   

ifeq ($(wildcard $(PROJECT).cpp),)
   ifeq ($(wildcard $(PROJECT).c),)
      ifeq ($(wildcard $(PROJECT).asm),)
         ifneq ($(NOPROJECT),1)
            $(error PROJECT ($(PROJECT)) is not a .cpp, .c or .asm file)
         endif   
      else	  
         SOURCES += $(PROJECT).asm
      endif	  
   else	  
      SOURCES += $(PROJECT).c
   endif	  
else	     
   SOURCES += $(PROJECT).cpp
endif   


#============================================================================
#
# decide whether we have a C++ project or a C/Assembler project
#
# When a project uses at least one C++ file it is a C++ project, and
# the C++ tools must be used for ALL files.
# If not, the C tools are used.
# 
#============================================================================

SOURCES := $(strip $(SOURCES))
ifeq ($(patsubst %.cpp,,$(SOURCES)),$(SOURCES))
   LANGUAGE := C
else
   LANGUAGE := C++
endif
# $(error $(LANGUAGE) '$(SOURCES)' '$(patsubst %.cpp,,$(SOURCES))' )


#============================================================================
#
# find the files
# 
#============================================================================

SEARCH    += $(BMPTK)
SEARCH    += $(BMPTK)/targets

INCLUDES  += -I.
INCLUDES  += -I$(BMPTK)
INCLUDES  += -I$(BMPTK)/targets
INCLUDES  += $(foreach x, $(SEARCH), -I$(x))

bmptk.h:
	# You specified an absolute path ($(BMPTK)) for the bmptk location.
	# The 'make' tool you use has a bug in handling absolute paths that
	# prevents the bmptk makefile from finding some source files.
	# Two solutions are: 
	# 1) Use a make that does not have this bug.
	#    The gnu make available from www.gnu.org/software/make/ does
	#    not have this bug, nor does the cs-make that is part of the 
	#    CodesSourcery distribution. 
	# 2) Use a relative path to specify the bmptk location. 
	#    This almost forces you to locate your project inside the bmptk 
	#    tree, (a subdirectory of) the examples directory is a 
	#    reasonable choice.

   
#============================================================================
#
# default port, baudrate, xtal for download and debug log
# 
#============================================================================

SERIAL_PORT      := COM4
SERIAL_BAUDRATE  := 38400
XTAL             := 12000


#============================================================================
#
# tool executables
# 
#============================================================================

CC        = "$(PREFIX)gcc"
CPP       = "$(PREFIX)g++"
AS        = "$(PREFIX)gcc"
OBJCOPY   = "$(PREFIX)objcopy"
OBJDUMP   = "$(PREFIX)objdump"
SIZES     = "$(PREFIX)size"
NM        = "$(PREFIX)nm"

ifeq ($(LANGUAGE),C)
   LINKER    = "$(PREFIX)gcc"
else
   LINKER    = "$(PREFIX)g++"
endif

NDSTOOL   := "$(DEVKITPRO)/devkitARM/bin/ndstool"

ifeq ($(OS),Windows_NT)
   RM          := "$(BMPTK)/tools/cs-rm" -rf
else
   RM          := /bin/rm -f
endif


#============================================================================
#
# Intermediate and result files
# 
#============================================================================

BIN       := $(PROJECT).bin
ELF       := $(PROJECT).elf
MAP       := $(PROJECT).map
HEX       := $(PROJECT).hex
DMP       := $(PROJECT).dmp
LSS       := $(PROJECT).lss
NDS       := $(PROJECT).nds
EXE       := $(PROJECT).exe
NMDUMP    := $(PROJECT).nmdump
OBJ       += $(OBJECTS)
SOURCESX  := $(patsubst %.asm,%.o,$(patsubst %.S,%.o,$(SOURCES)))
OBJ       += $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCESX)))
OBJ       += $(patsubst %,%.o,$(LIBRARIES))
LST       += $(patsubst %.o,%.lst,$(OBJ))


#============================================================================
#
# boards
# 
#============================================================================

# the target can be either a chip, or a board
ifeq ($(TARGET),)
   TARGET = $(CHIP)
else
   ifeq ($(CHIP),)
      CHIP = $(TARGET)
   endif
endif   

ifeq ($(TARGET),db103)
   CHIP        := lpc1114fn28
endif

ifeq ($(TARGET),db104)
   CHIP        := lpc1114fn28
endif


#============================================================================
#
# target-specific parts
# 
#============================================================================

# will remain empty when no valid target is found
PREFIX     := 

define Hosted
   HOSTED         = 1
   HAS_FILESYSTEM = 1
endef

HAS_FILESYSTEM = 0

ifeq ($(TARGET),nds)
   $(eval $(Hosted))
   CHIP        := ARMv7
   PREFIX      := $(DEVKITPRO)/devkitARM/bin/arm-none-eabi-
   CORE_FLAGS  := -march=armv5te -mtune=arm946e-s -fomit-frame-pointer 
   CORE_FLAGS  += -ffast-math -mthumb -mthumb-interwork -DARM9
   INCLUDES    += -I$(DEVKITPRO)/ -I$(DEVKITPRO)/libnds/include 
   LIBS        += -L$(DEVKITPRO)/libnds/lib -lnds9
   LDFLAGS	   += -g -mthumb -mthumb-interwork -specs=ds_arm9.specs
   RESULTS     = $(ELF) $(NDS) $(NMDUMP)
   RUN         = "$(DEVKITPRO)/emulators/desmume/DeSmuME" $(NDS)
   LIBS        += nds
   SEARCH       += $(BMPTK)/stdlib $(BMPTK)/targets/nds
   INCLUDES    += -I$(BMPTK)/stdlib -I$(BMPTK)/targets/nds
   TICKS_PER_US = 67
   LINKERSCRIPT =
endif

ifeq ($(TARGET),win)
   $(eval $(Hosted))
   CHIP        := Intel
   PREFIX      := $(DEVCPP)/bin/
   CORE_FLAGS  := -mno-ms-bitfields   
   INCLUDES    += -I"$(DEVCPPLIB)/lib/gcc/mingw32/3.4.2/include"  
   INCLUDES    += -I"$(DEVCPP)/include/c++/3.4.2/backward" 
   INCLUDES    += -I"$(DEVCPP)/lib/gcc/mingw32"
   INCLUDES    += -I"$(DEVCPP)/include/c++/3.4.2"
   INCLUDES    += -I"$(DEVCPP)/include"
   LIBS   += -L"$(DEVCPP)/lib" 
   LDFLAGS     += -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
   RESULTS     = $(EXE)
   RUN         = ./$(EXE)
   LIBS        += win
   SEARCH       += $(BMPTK)/targets/win
   INCLUDES    += -I$(BMPTK)/targets/win
   LINKERSCRIPT =
endif

define Embedded 
   EMBEDDED    = 1
   CORE_FLAGS  += -nostartfiles 
   PREFIX      := $(GNU-ARM)/bin/arm-none-eabi-
   RESULTS     += $(NMDUMP) sizes 
endef

define Cortex
   $(eval $(Embedded))
   INCLUDES    += -I$(BMPTK)/targets/cortex/cmsis
   XTAL        := 12000000
   SOURCES     += cortex_startup.c
   RESULTS     += $(ELF) $(BIN) $(MAP) $(HEX) $(DMP) $(LSS) $(NMDUMP)
   FMCMD       = COM($(patsubst COM%,%,$(SERIAL_PORT)),$(SERIAL_BAUDRATE)) 
   FMCMD       += DEVICE($(FNAME), 12000000, 0)
   FMCMD       += HARDWARE(BOOTEXEC, 50, 100)
   FMCMD       += ERASE(DEVICE, PROTECTISP)
   FMCMD       += HEXFILE($(HEX), NOCHECKSUMS, NOFILL, PROTECTISP)
   RUN         = $(LPC21ISP) -control -verify -term $(HEX) $(SERIAL_PORT) $(SERIAL_BAUDRATE) 12000
   # TERMINAL    = lpc21isp -termonly x $(SERIAL_PORT) 19200 y
   # RUN         = $(FLASHMAGIC) '$(FMCMD)'
   LINKERSCRIPT = linkerscript.ld
   LDFLAGS	   += -T linkerscript.ld -nostartfiles 
   RESULTS     += linkerscript.ld
   OBJ         += cortex_startup.o
endef

define Cortex-M0
   $(eval $(Cortex))
   CORE_FLAGS  += -mcpu=cortex-m0 -mthumb -fomit-frame-pointer -march=armv6-m
   SEARCH      += $(BMPTK)/targets/cortex
   INCLUDES    += -I$(BMPTK)/targets/cortex
   LD_CONFIG   = -DROM_START=0 -DRAM_START=0x10000000
endef

define LPC81X
   $(eval $(Cortex-M0))
   INCLUDES    += -I$(BMPTK)/targets/cortex/cmsis/lpc800/inc
endef

ifeq ($(CHIP),lpc810m021fn8)
   $(eval $(LPC81X))
   FNAME       = LPC810M021FN8
   STACKSIZE   ?= 256
   LD_CONFIG   += -DROM_SIZE=8k -DRAM_SIZE=1k 
endif

ifeq ($(CHIP),lpc812m101)
   $(eval $(LPC81X))
   FNAME       = LPC810M021FN8
   STACKSIZE   ?= 1k
   LD_CONFIG   += -DROM_SIZE=16k -DRAM_SIZE=4k 
endif

define LPC1114
   $(eval $(Cortex-M0))
   INCLUDES    += -I$(BMPTK)/targets/cortex/cmsis/11xx/inc 
endef

ifeq ($(CHIP),lpc1114fn28)
   $(eval $(LPC1114))
   FNAME       = LPC1114/102
   STACKSIZE   ?= 1k
   LD_CONFIG   += -DROM_SIZE=32k -DRAM_SIZE=4k
   HWCPP       += lpc1114.hpp lpc1114fn28.hpp cout.hpp
endif

define LPC1227
   $(eval $(Cortex-M0))
   INCLUDES    += -I$(BMPTK)/targets/cortex/cmsis/12xx/inc
   SOURCES     += lpc1227.cpp   
endef

ifeq ($(CHIP),lpc1227fbd301)
   $(eval $(LPC1227))
   FNAME       = LPC1227/301
   STACK_SIZE  ?= 2k
   LD_CONFIG   += -DROM_SIZE=96k -DRAM_SIZE=8k
endif

ifneq ($(NOPROJECT),1)
   ifeq ($(PREFIX),)
      $(error invalid or no target specified: "$(TARGET)")
   endif
endif   

LD_CONFIG += -DSTACK_SIZE=$(STACKSIZE)

   
#============================================================================
#
# hwcpp
# 
#============================================================================

HWCPP      += hwcpp.hpp
HWCPP      += basics.hpp timing.hpp
HWCPP      += string.hpp graphics.hpp
HWCPP      += numeric.hpp
HWCPP      += pins.hpp channels.hpp
HWCPP      += i2c.hpp spi.hpp one_wire.hpp
HWCPP      += hc595.hpp pcf8574.hpp mcp23xxx.hpp pcf8591.hpp
HWCPP      += hd44780.hpp
HWCPP      += graphics.hpp
HWCPP      += pcd8544.hpp lcd_19.hpp
HWCPP      += ds18x20.hpp
HWCPP      += ads7843.hpp

ifeq ($(LANGUAGE),C++)
   HWCPPDIRS  = hwcpp hwcpp/core hwcpp/targets hwcpp/chips
   INCLUDES  += $(foreach x, $(HWCPPDIRS), -I$(BMPTK)/$(x))
   SEARCH    += $(foreach x, $(HWCPPDIRS), $(BMPTK)/$(x))
   HEADERS   += $(HWCPP)
endif


#============================================================================
#
# Pass information to the code 
# 
#============================================================================

DEFINES   += -DBMPTK_TARGET=$(TARGET)
DEFINES   += -DBMPTK_TARGET_$(TARGET)
DEFINES   += -DBMPTK_CHIP=$(CHIP)
DEFINES   += -DBMPTK_CHIP_$(CHIP)
DEFINES   += -DBMPTK_XTAL=$(XTAL)
DEFINES   += -DBMPTK_BAUDRATE=$(SERIAL_BAUDRATE)
DEFINES   += -DBMPTK_VERSION=$(VERSION)

ifeq ($(HOSTED),1)
   DEFINES   += -DBMPTK_HOSTED
endif   
ifeq ($(EMBEDDED),1)
   DEFINES   += -DBMPTK_EMBEDDED
endif   
ifeq ($(HAS_FILESYSTEM),1)
   DEFINES   += -DBMPTK_HAS_FILESYSTEM
endif   


#============================================================================
#
# Dependencies
# 
#============================================================================

HEADERS   += $(patsubst %,%.h,$(LIBRARIES))

# Assume all sources depend on all headers, the linkerscript, and the Makefile
DEPEND    := $(HEADERS) $(LNK) Makefile
$(OBJ): $(DEPEND)
             
             
#============================================================================
#
# tool options
# 
#============================================================================

# show all warnings, treat most as errors
CORE_FLAGS  += -Wall -Werror
CORE_FLAGS  += -Wno-unused-local-typedefs
CORE_FLAGS  += -Wno-maybe-uninitialized

# use sections to save space
CORE_FLAGS  += -fdata-sections -ffunction-sections

# optimize for space
CORE_FLAGS  += -Os

# cpp: don't use features that are too expensive
CORE_CPP_FLAGS += -fno-rtti -fno-exceptions 
CORE_CPP_FLAGS += -fno-threadsafe-statics -fno-use-cxa-get-exception-ptr

# cpp: use latest language standard
CORE_CPP_FLAGS    += -std=c++11

# assembler: enable the preprocessor
CORE_AS_FLAGS     += -x assembler-with-cpp

# linker specific
LDFLAGS     +=  -Wl,-Map,$(MAP)      
LDFLAGS     += -Wl,--gc-sections  

COMMON      := $(CORE_FLAGS) $(INCLUDES) $(DEFINES)
CPPFLAGS    += $(COMMON) $(CORE_CPP_FLAGS)
CFLAGS      += $(COMMON) $(CORE_CC_FLAGS) 
ASFLAGS     += $(COMMON) $(CORE_AS_FLAGS)
LDFLAGS     += $(COMMON) $(CORE_LD_FLAGS)


#============================================================================
#
# how to make things
# 
#============================================================================

# find non-local source files
# VPATH is not used, beacause it would also 'find' .ld and .o files,
# which should be created locally
vpath %.h    $(SEARCH)
vpath %.hpp  $(SEARCH)
vpath %.c    $(SEARCH)
vpath %.asm  $(SEARCH)
vpath %.cpp  $(SEARCH)

# use only the explcit rules below
.SUFFIXES:

# How to make object files?
%.o: %.cpp
	@echo 'Compiling C++ file: $<'
	$(CPP) $(CPPFLAGS) -c -o $@ $< 
	$(CPP) $(CPPFLAGS) -c -S -o $(patsubst %.o,%.lst,$@) $<
	@echo ' '	
	
%.o: %.c
	@echo 'Compiling C file: $<'
	$(CC) $(CFLAGS) -c -o $@ $< 
	$(CC) $(CFLAGS) -c -S -o $(patsubst %.o,%.lst,$@) $<
	@echo ' '	
	
%.o: %.S
	@echo 'Assembling file: $<'
	$(AS)  $(ASFLAGS)  -c -o $@ $<
	@echo ' '	

%.o: %.asm
	@echo 'Assembling file: $<'
	$(AS)  $(ASFLAGS)  -c -o $@ $<
	@echo ' '	

# How to make a listing from a cpp file
%.list: %.cpp
	$(CPP) $(CPPFLAGS) -c -S -o $@ $<

# make the linkerscipt   
linkerscript.ld: $(BMPTK)/targets/cortex/linkerscript.c
	@echo 'Creating the linkerscript'
	$(CC) $(LD_CONFIG) -E -P -C $(BMPTK)/targets/cortex/linkerscript.c -o $@ 
	@echo ' '
   
# make .elf by linking all objects
$(ELF): $(addprefix ./,$(OBJ)) $(LIBA) $(LNK) ./$(LINKERSCRIPT)
	@echo 'Linking target: $(ELF)'
	$(LINKER) -Wl,-fatal-warnings -o $@ $(OBJ) $(LIBA) $(LDFLAGS) $(LIBS)
	@echo ' '	
   
# make .exe by linking all objects
$(EXE): $(OBJ) $(LNK) 
	@echo 'Linking target: $(EXE)'
	$(LINKER) -o $@ $(OBJ) $(LDFLAGS) $(LIBS) 
	@echo ' '	
	
# make sizes listing from the elf file
$(NMDUMP): $(ELF)
	$(NM) -S --size-sort --radix=d $(ELF) >$(NMDUMP)

# make .bin from .elf
$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

# make .hex from .elf
$(HEX): $(ELF)
	$(OBJCOPY) --output-target ihex $< $@
	
# make .dmp from elf
$(DMP): $(ELF)
	$(OBJDUMP) -x --syms $< > $@

# make .lss from elf
$(LSS): $(ELF)
	$(OBJDUMP) -S $< > $@

# make .nds from .elf
$(NDS): $(ELF)
	$(NDSTOOL) -c $@ -9 $< -b $(DEVKITPRO)/libnds/icon.bmp "$(PROJECT)"		

# show object sizes
.PHONY: sizes
sizes: $(OBJ)
	$(SIZES) -B -t $(OBJ)
	"$(BMPTK)/tools/image_sizes/image_sizes.exe" $(MAP)


#============================================================================
#
# targets
# 
#============================================================================

.PHONY: $(PROJECT) all build new fresh run clean doxygen

.DEFAULT_GOAL := build

# Build the project
$(PROJECT): $(RESULTS)

# aliases for build the project
all: $(PROJECT)
build: $(PROJECT)

# aliases for clean+build
new: clean build
fresh: clean build

# Run (= download and start) the project
run: $(PROJECT)
	$(RUN)
	$(TERMINAL)
    
doxygen: doxyfile
	Doxygen
   
# Cleanup
CLEAN += $(RESULTS)
CLEAN += $(OBJ)
CLEAN += $(MAP)
CLEAN += $(LST)
CLEAN += doxydocs
clean:
	$(RM) $(CLEAN)

