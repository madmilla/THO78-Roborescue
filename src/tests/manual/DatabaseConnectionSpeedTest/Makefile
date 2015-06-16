output: main.o
	g++ -std=c++11 -o output main.o ../../../communication/persistant_storage/databaseconnector.o ../../../communication/persistant_storage/point.o -L ../../../../deps/lib/mysqlcppconn/linux/x64\(64\ bit\)/ -lmysqlcppconn
main.o: main.cpp
	g++ -std=c++11 -c main.cpp -I ../../../ -I ../../../../deps/incl/mysqlcppconn/	

run:
	LD_LIBRARY_PATH=../../../../deps/lib/mysqlcppconn/linux/x64\(64\ bit\) ./output ${USERNAME} ${PASSWORD}
