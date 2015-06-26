CXX 		+= 
CXXFLAGS	+= -pthread
INCLUDES 	+= Src/Tests/RosbeeDriveTest/includes/EncoderInterface.h LibSerial.h PositionController.h PropCom.h RosbeeDriver.h Waypoint.h
LDLIBS		+= 
LDFLAGS		+= 
MODULES		+= 

SRC 		+= Src/Tests/RosbeeDriveTest/src/Main.cpp EncoderInterface.cpp LibSerial.cpp PositionController.cpp PropCom.cpp RosbeeDriver.cpp Waypoint.cpp