include Makefile.inc

.PHONY: all

all: main.exe

main.exe : $(QUADCOPTER_GUI_DIR)\ui_quadcopterwindow.h moc_quadcopterwindow.o $(QUADCOPTER_GUI_DIR)\quadcopterwindow.o main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)