#Vehicles
QUADCOPTER_DIR 					= Src\Vehicles\Quadcopter
ATV_DIR 						= Src\Vehicles\ATV
ROSBEE_DIR 						= Src\Vehicles\Rosbee

#Sensors
PROPELLOR_ENCODER_DIR 			= 
PROPELLOR_SIRC_DIR 				= 
PROPELLOR_TEMPERATURESENSOR_DIR =
PROPELLOR_ULTRASONICSENSOR_DIR 	=
PX4FLOW_DIR 					=
LIDAR_DIR 						= 
LOCALISATION_BASESTATION_DIR 	=
LOCALISATION_SERVER_DIR			= 

#GUI's
MAIN_GUI_DIR 					=
QUADCOPTER_GUI_DIR 				= 
ATV_GUI_DIR 					= 
ROSBEE_GUI_DIR 					= 
LIDAR_GUI_DIR 					= 
MAP_GUI_DIR 					= 

#MAP
MAP_DIR 						= src\map

#COMMUNICATION
MAVLINK_EXCHANGER_DIR 			= src\communication\MavlinkExchanger
PERSISTANT_STORAGE_DIR 			= src\communication\Persistant-Storage
UDP_DIR 						= src\communication\UDP
UPDATE_VEHICLE_POSITION_DIR 	= src\communication\Update-Vehicle-Position

#DEPENDENCIES
ARUCO_DIR 						= deps\incl\aruco
LIB_SERIAL_DIR					= deps\incl\libserial
MAVLINK_DIR						= deps\incl\mavlink
MYSQLCPPCONN_DIR				= deps\incl\mysqlcppconn
RPLIDAR_DIR						= deps\incl\rplidar

include Makefile.local