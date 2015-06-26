INCLUDES 	+= -I$(BOOST_INCL_DIR)
LDLIBS		+= -lboost_system-mgw49-mt-d-1_58 -lws2_32
LDFLAGS		+= -L$(BOOST_LIB_DIR)
MODULES		+= $(SERIAL_PORT_MODULE)

SRC 		+= Src/Tests/BoostSerialPortTest/Main.cpp