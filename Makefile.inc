include Makefile.local
include TargetMakefiles/Makefile.modules

CXX 							= g++
CXXFLAGS						= -std=c++11
INCLUDES 						= 
LDLIBS							=
LDFLAGS							= 
SRC 							= 
UI 								= 
UI_HEADERS						=
MODULES 						= 

ifeq ($(OS),Windows_NT)
	CXXFLAGS 	+= -DWIN32 -fPIC
	MOC			= $(QT_BIN_DIR)/moc.exe
	UIC			= $(QT_BIN_DIR)/uic.exe
endif

ifeq ($(MAKECMDGOALS),mission1)
	ifneq ($(OS),Windows_NT)
		LDLIBS 		+= -lQt5Core -lQt5Widgets -lQt5Gui -lQt5Sql
		INCLUDES 	+= -I /usr/include/qt5
		CXXFLAGS	+= -fPIC -pthread
		LDFLAGS+= -pthread
	else
		INCLUDES 	+= -I$(QT_INCL_DIR)
		LDFLAGS 	+= -L$(QT_LIB_DIR)
		LDLIBS 		+= -lQt5Core -lQt5Widgets -lQt5Gui -lws2_32 -lQt5Sql -pthread
	endif
	include TargetMakefiles/Makefile.basestation
endif
ifeq ($(MAKECMDGOALS),localisationmodule)
	ifeq ($(OS),Windows_NT)
		@echo "Localisation-module cannot be compiled on Windows systems"
		exit 1
	else
		LDLIBS 		+= -lboost_system -lpthread `pkg-config --libs opencv` -lX11
		INCLUDES 	+= `pkg-config --cflags opencv`
		include TargetMakefiles/Makefile.localisationmodule
	endif
endif
ifeq ($(MAKECMDGOALS),lidar)
	ifeq ($(OS),Windows_NT)
		@echo "LIDAR cannot be compiled on Windows systems"
		exit 1
	else
		CXXFLAGS 	+= 
		INCLUDES 	+= -IDeps/incl/rplidar/linux -IDeps/incl/opencv
		LDFLAGS		+= -LDeps/lib/opencv/Linux/x86 -LDeps/lib/rplidar/linux
		LDLIBS 		+= -lrplidar -lopencv_core -lopencv_highgui -lopencv_imgproc -lpthread -lrt
		include TargetMakefiles/Makefile.lidar
	endif
endif
ifeq ($(MAKECMDGOALS),rosbee)
	ifeq ($(OS),Windows_NT))
		@echo "Rosbee cannot be compiled on Windows systems"
		exit 1
	else
		include TargetMakefiles/Makefile.rosbee
	endif
endif
ifeq ($(MAKECMDGOALS),environmentsimulator)
	ifneq ($(OS),Windows_NT)
		@echo "The Environment-simulator is currently not compatible with linux bases systems"
		exit 1
	else
		include TargetMakefiles/Makefile.environmentsimulator
	endif
endif
ifeq ($(MAKECMDGOALS),map)
	ifneq ($(OS),Windows_NT)
		@echo "The Map is currently not compatible with linux bases systems"
		exit 1
	else
		LDLIBS 		+= -lQt5Sql
		include TargetMakefiles/Makefile.map
	endif
endif
ifeq ($(MAKECMDGOALS),test)
	ifneq ($(TESTNAME),)
		include Src/Tests/$(TESTNAME)/$(TESTNAME).mk
	else
	
	endif
endif
ifeq ($(MAKECMDGOALS),clean)
	include TargetMakefiles/Makefile.clean
else
	INCLUDES 		+= $(patsubst %, -I%, $(MODULES))
	include $(MODULES:=module.mk)
	UI_HEADERS 		+= $(UI:.ui=.h)
	OBJ 			+= $(SRC:.cpp=.o)
endif


%.d : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MM -MT"$@" $< -MF $@
	
%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<
	
moc_%.cpp : %.h
	$(MOC) $< -o $@
	
ui_%.h : %.ui
	$(UIC) $< -o $@
