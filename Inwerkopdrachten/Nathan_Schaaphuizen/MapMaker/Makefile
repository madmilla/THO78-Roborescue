
OBJ = Main.o MapUi.o Map.o Widget.o Window.o

build: $(OBJ)
	echo Buil Done

%.o : %.cpp %hpp
	g++ -c $<  -o tmp/$@ -std=gnu++11 -Wall -Werror