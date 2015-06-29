CXX 		+= 
CXXFLAGS	+= 
INCLUDES 	+= -IDeps/incl/boost_1_58_0/Windows 
LDLIBS		+= -lboost_system -lws2_32
LDFLAGS		+= -LDeps/lib/boost_1_58_0/Windows
MODULES		+= $(MAVLINK_LIB)
MODULES		+= $(MAVLINK_EXCHANGER_MODULE)
MODULES		+= $(SERIAL_PORT_MODULE)

SRC 		+= Src/Tests/BoostConnectionTests/Main.cpp