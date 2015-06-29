#############################################################################
# 
# Makefile for bmptk v1th04 examples 
#
# (c) Wouter van Ooijen (www.voti.nl) 2012 .. 2104
# 
#############################################################################

SUBDIRS += blink switch beep
SUBDIRS += 440hz timer servo sw-uart ds1990
SUBDIRS += lpc810
SUBDIRS += lcd5510

DOXYGEN += i2c lcd5510 sw-uart

CLEANUP += $(SUBDIRS) i2c
BUILDDIRS = $(SUBDIRS:%=build-%)
CLEANDIRS = $(CLEANUP:%=clean-%)
DOXYDIRS  = $(DOXYGEN:%=doxy-%)

.phony: all clean build doxygen $(BUILDDIRS) $(CLEANDIRS) $(DOXYDIRS)

build: $(BUILDDIRS)
$(BUILDDIRS):
		make -C $(@:build-%=%) build
      
doxygen: $(DOXYDIRS)      
$(DOXYDIRS):
		make -C $(@:doxy-%=%) doxygen
      
clean: $(CLEANDIRS)
$(CLEANDIRS):
		make -C $(@:clean-%=%) clean
      
all: build doxygen      

