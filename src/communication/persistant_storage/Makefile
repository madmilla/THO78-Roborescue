# all object files
ALL = databaseconnector.o point.o QRCode.o main.o

# the compiler: gcc for a C program, g++ for C++
CC = g++
#CC = gcc

# includes
INCLUDES = -I ../../../deps/incl/mysqlcppconn -I ../../../deps/incl
LDLIBS = -lmysqlcppconn
LIBPATHS = -L../../../deps/lib/mysqlcppconn/linux/x64\(64\ bit\)

# compiler flags:
CFLAGS = -g -Wall -std=c++11

# target executable
TARGET = Storage

# compile test
$(TARGET): $(ALL)
	$(CC) $(CFLAGS) $(ALL) -o $(TARGET) $(LIBPATHS) $(LDLIBS)

# main
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(INCLUDES)

# compile database connector
databaseconnector.o: databaseconnector.cpp databaseconnector.h
	$(CC) $(CFLAGS) -c databaseconnector.cpp $(INCLUDES)

# compile point
point.o: point.cpp point.hpp
	$(CC) $(CFLAGS) -c point.cpp

# compile QRCode
QRcode.o: QRCode.cpp QRCode.h
	$(CC) $(CFLAGS) -c QRCode.cpp

# clean
clean:
	rm *.o $(TARGET)
