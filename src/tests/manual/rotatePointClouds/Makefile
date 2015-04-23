PROGRAM=rotateTest
INCLUDES=../../../sensors/lidar/point_clouds/pointcloudobject/
INCLUDES2=../../../sensors/lidar/point_clouds/rotate/ 
SOURCE= test.cpp ../../../sensors/lidar/point_clouds/rotate/rotate.cpp  ../../../sensors/lidar/point_clouds/rotate/rotate.h
SOURCEINC= ../../../sensors/lidar/point_clouds/pointcloudobject/PointCloud.cpp ../../../sensors/lidar/point_clouds/pointcloudobject/PointCloud.h 
CC= g++
FLAGS= -std=c++11

$(PROGRAM): $(SOURCE)

	$(CC) $(FLAGS) -I$(INCLUDES) -I$(INCLUDES2) $(SOURCEINC) $(SOURCE) -o$(PROGRAM)
clean:
	rm -f $(PROGRAM)