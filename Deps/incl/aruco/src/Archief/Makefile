HEADERS = $(wildcard headers/*.h)
OBJ_FILES = $(HEADERS:.h=.o)

.PHONY: all

all: LocalisationModule.cpp $(OBJ_FILES)
	g++-4.9 -std=c++11 -lboost_system -lpthread `pkg-config --cflags --libs opencv` $(OBJ_FILES) LocalisationModule.cpp -o localisationModule
	
%.o : %.cpp
	g++-4.9 -std=c++11 -lboost_system -lpthread `pkg-config --cflags --libs opencv` -c -o $@ $<