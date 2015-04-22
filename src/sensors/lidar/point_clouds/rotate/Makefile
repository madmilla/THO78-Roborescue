PROGRAM=rotateTest
INCLUDES=../pointcloudobject/
SOURCE= test.cpp rotate.cpp  rotate.h
SOURCEINC= ../pointcloudobject/PointCloud.cpp ../pointcloudobject/PointCloud.h 
CC= g++
FLAGS= -std=c++11

$(PROGRAM): $(SOURCE)

	$(CC) $(FLAGS) -I$(INCLUDES) $(SOURCEINC) $(SOURCE) -o$(PROGRAM)
clean:
	rm -f $(PROGRAM)