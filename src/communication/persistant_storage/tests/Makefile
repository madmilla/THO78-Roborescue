all: speedtest connectionCloseTest

speedtest : speedTest.cpp
	g++ -std=c++11 speedTest.cpp -lmysqlcppconn -o speedtest

connectionCloseTest : connectionCloseTest.cpp
	g++ -std=c++11 connectionCloseTest.cpp -lmysqlcppconn -o connectionCloseTest

