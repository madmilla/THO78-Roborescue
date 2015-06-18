#Vehicles
QUADCOPTER_DIR 					= src\Vehicles\Quadcopter
ATV_DIR 						= src\Vehicles\ATV
ROSBEE_DIR 						= src\Vehicles\Rosbee

#Sensors
PROPELLOR_ENCODER_DIR 			= src\sensors\Propellor-Encoder
PROPELLOR_SIRC_DIR 				= src\sensors\Propellor-SIRC
PROPELLOR_TEMPERATURESENSOR_DIR = src\sensors\Propellor-TemperatureSensor
PROPELLOR_ULTRASONICSENSOR_DIR 	= src\sensors\Propellor-UltrasonicSensor
PX4FLOW_DIR 					= src\sensors\PX4Flow
LIDAR_DIR 						= src\sensors\lidar
LOCALISATION_BASESTATION_DIR 	= src\sensors\Localisation-Module\Localisation-Basestation
LOCALISATION_SERVER_DIR			= src\sensors\Localisation-Module\Localisation-Server

#GUI's
MAIN_GUI_DIR 					= src\gui\mission-gui
QUADCOPTER_GUI_DIR 				= src\gui\mission-gui\quadcopter-gui
ATV_GUI_DIR 					= src\gui\mission-gui\ATV-gui
ROSBEE_GUI_DIR 					= src\gui\mission-gui\rosbee-gui
LIDAR_GUI_DIR 					= src\gui\mission-gui\lidar-gui
MAP_GUI_DIR 					= src\gui\mission-gui\map-gui

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