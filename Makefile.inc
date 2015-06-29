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
BOOST_INCL_DIR 					= Deps/incl/boost_1_58_0/Windows

ifeq ($(OS),Windows_NT)
	CXXFLAGS 		+= -DWIN32
	MOC				= $(QT_BIN_DIR)/moc.exe
	UIC				= $(QT_BIN_DIR)/uic.exe
	BOOST_LIB_DIR 	= Deps/lib/boost_1_58_0/Windows
else
	MOC = moc
	UIC = uic
endif

ifeq ($(MAKECMDGOALS),mission1)
	LDLIBS 	+= -lQt5Core -lQt5Widgets -lQt5Gui -lQt5Sql -lpthread -lboost_system
	ifneq ($(OS),Windows_NT)
	else
		INCLUDES 	+= -I$(QT_INCL_DIR) -I$(BOOST_INCL_DIR)
		LDFLAGS 	+= -L$(QT_LIB_DIR) -L$(BOOST_LIB_DIR)
		LDLIBS 		+= -lws2_32
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
	@echo UI is: $(UI)
	UI_HEADERS 		+= $(UI:.ui=.h)
	@echo UI headers are: $(UI_HEADERS)
	OBJ 			+= $(SRC:.cpp=.o)
endif
	
ui_%.h : %.ui
	$(UIC) $< -o $@

%.d : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MM -MT"$@" $< -MF $@
	
%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<
	
moc_%.cpp : %.h
	$(MOC) $< -o $@

