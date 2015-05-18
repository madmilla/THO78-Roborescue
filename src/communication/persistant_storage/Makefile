all: databaseconnector.o point.o

databaseconnector.o: databaseconnector.cpp
	g++ -std=c++11 -c databaseconnector.cpp -I ../../../deps/incl/mysqlcppconn
point.o: point.cpp
	g++ -c point.cpp
