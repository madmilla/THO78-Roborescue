INCLUDES 						= 
#Vehicles
QUADCOPTER_DIR 					= src\Vehicles\Quadcopter
INCLUDES						+= -I$(QUADCOPTER_DIR)
ATV_DIR 						= src\Vehicles\ATV
INCLUDES						+= -I$(ATV_DIR)
ROSBEE_DIR 						= src\Vehicles\Rosbee
INCLUDES						+= -I$(ROSBEE_DIR)

#Sensors
PROPELLOR_ENCODER_DIR 			= src\sensors\Propellor-Encoder
INCLUDES						+= -I$(PROPELLOR_ENCODER_DIR)
PROPELLOR_SIRC_DIR 				= src\sensors\Propellor-SIRC
INCLUDES						+= -I$(PROPELLOR_SIRC_DIR)
PROPELLOR_TEMPERATURESENSOR_DIR = src\sensors\Propellor-TemperatureSensor.
INCLUDES						+= -I$(PROPELLOR_TEMPERATURESENSOR_DIR)
PROPELLOR_ULTRASONICSENSOR_DIR 	= src\sensors\Propellor-UltrasonicSensor
INCLUDES						+= -I$(PROPELLOR_ULTRASONICSENSOR_DIR)
PX4FLOW_DIR 					= src\sensors\PX4Flow
INCLUDES						+= -I$(PX4FLOW_DIR)
LIDAR_DIR 						= src\sensors\lidar
INCLUDES						+= -I$(LIDAR_DIR)
LOCALISATION_BASESTATION_DIR 	= src\sensors\Localisation-Module\Localisation-Basestation
INCLUDES						+= -I$(LOCALISATION_BASESTATION_DIR)
LOCALISATION_SERVER_DIR			= src\sensors\Localisation-Module\Localisation-Server
INCLUDES						+= -I$(LOCALISATION_SERVER_DIR)

#GUI's
MAIN_GUI_DIR 					= src\gui\mission-gui
INCLUDES						+= -I$(MAIN_GUI_DIR)
QUADCOPTER_GUI_DIR 				= src\gui\mission-gui\quadcopter-gui
INCLUDES						+= -I$(QUADCOPTER_GUI_DIR)
ATV_GUI_DIR 					= src\gui\mission-gui\ATV-gui
INCLUDES						+= -I$(ATV_GUI_DIR)
ROSBEE_GUI_DIR 					= src\gui\mission-gui\rosbee-gui
INCLUDES						+= -I$(ROSBEE_GUI_DIR)
LIDAR_GUI_DIR 					= src\gui\mission-gui\lidar-gui
INCLUDES						+= -I$(LIDAR_GUI_DIR)
MAP_GUI_DIR 					= src\gui\mission-gui\map-gui
INCLUDES						+= -I$(MAP_GUI_DIR)

#MAP
MAP_DIR 						= src\map
INCLUDES						+= -I$(MAP_DIR)

#COMMUNICATION
MAVLINK_EXCHANGER_DIR 			= src\communication\MavlinkExchanger
INCLUDES						+= -I$(MAVLINK_EXCHANGER_DIR)
PERSISTANT_STORAGE_DIR 			= src\communication\Persistant-Storage
INCLUDES						+= -I$(PERSISTANT_STORAGE_DIR)
UDP_DIR 						= src\communication\UDP
INCLUDES						+= -I$(UDP_DIR)
UPDATE_VEHICLE_POSITION_DIR 	= src\communication\Update-Vehicle-Position
INCLUDES						+= -I$(UPDATE_VEHICLE_POSITION_DIR)

#LIBRARIES
ARUCO_DIR 						= deps\incl\aruco
INCLUDES						+= -I$(ARUCO_DIR)
LIB_SERIAL_DIR					= deps\incl\libserial
INCLUDES						+= -I$(LIB_SERIAL_DIR)
MAVLINK_DIR						= deps\incl\mavlink
INCLUDES						+= -I$(MAVLINK_DIR)
MYSQLCPPCONN_DIR				= deps\incl\mysqlcppconn
INCLUDES						+= -I$(MYSQLCPPCONN_DIR)
RPLIDAR_DIR						= deps\incl\rplidar
INCLUDES						+= -I$(RPLIDAR_DIR)

include Makefile.local
INCLUDES						+= -I$(BOOST_INCL_DIR)
INCLUDES						+= -I$(OPENCV_INCL_DIR)
INCLUDES						+= -I$(QT_INCL_DIR)
LIBRARIES 						+= -l$(BOOST_DEPS_DIR)
LIBRARIES						+= -l$(OPENCV_DEPS_DIR)
LIBRARIES						+= -l$(QT_DEPS_DIR)

CXX 							= g++
CXXFLAGS						= -std=c++11

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBRARIES) -c -o $@ $<