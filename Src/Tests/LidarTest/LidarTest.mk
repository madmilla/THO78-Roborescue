CXX 		+= 
CXXFLAGS	+= 
INCLUDES 	+= -IDeps/incl/rplidar/linux -IDeps/incl/opencv -I$(BOOST_INCL_DIR)
LDFLAGS		+= -LDeps/lib/opencv/Linux/x86 -LDeps/lib/rplidar/linux -LDeps/lib/boost_1_58_0/RaspberryPi
LDLIBS 		+= -lrplidar -lopencv_core -lopencv_highgui -lopencv_imgproc -lpthread -lrt -lboost_system
MODULES		+= $(LIDAR_RASPI_MODULE)
MODULES 	+= $(RPLIDAR_LIB)
MODULES 	+= $(OPENCV_LIB)
MODULES 	+= $(DATASTRUCTURES_MODULE)
MODULES 	+= $(MAVLINK_EXCHANGER_MODULE)
MODULES		+= $(SERIAL_PORT_MODULE)
MODULES		+= $(MAVLINK_LIB)
MODULES		+= $(LIDAR_CONTROLLER_MODULE)

SRC += Src/Tests/LidarTest/Main.cpp