HEADERS = $(wildcard headers/*.h)
OBJ_FILES = $(HEADERS:.h=.o)
FLAGS = -I mavlink/common
TARGET = linux

.PHONY: all

all: LocalisationModule.cpp $(OBJ_FILES)
	g++-4.9 -std=c++11 -lX11 -lboost_system -lpthread `pkg-config --cflags --libs opencv` $(FLAGS) $(OBJ_FILES) LocalisationModule.cpp -o localisationModule
	
%.o : %.cpp
	g++-4.9 -std=c++11 -lX11 -lboost_system -lpthread `pkg-config --cflags --libs opencv` $(FLAGS) -c -o $@ $<
