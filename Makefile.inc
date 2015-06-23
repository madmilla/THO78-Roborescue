include Makefile.local
include TargetMakefiles/Makefile.modules

CXX 							= g++
CXXFLAGS						= -std=c++11
INCLUDES 						= 
LDLIBS							= -lpthread
LDFLAGS							= 
SRC 							= 
UI 								= 
UI_HEADERS						=
MODULES 						= 

ifeq ($(MAKECMDGOALS),mission1)
	ifeq ($(OS),Windows_NT)
		@echo "Basestation is currently not compatible with linux based systems"
		exit 1
	else
		LDLIBS += -lQt5Core -lQt5Widgets -lQt5Gui
		LDFLAGS += -L$(QT_LIB_DIR)
		MOC	= $(QT_BIN_DIR)/moc.exe
		UIC	= $(QT_BIN_DIR)/uic.exe
		include TargetMakefiles/Makefile.basestation
		INCLUDES 	+= -I$(QT_INCL_DIR)
	endif
endif
ifeq ($(MAKECMDGOALS),localisationmodule)
	ifneq ($(OS),linux)
		@echo "Localisation-module cannot be compiled on Windows systems"
		exit 1
	else
		LDLIBS += -lboost_system -lpthread `pkg-config --libs opencv` -lX11
		LDFLAGS += 
		INCLUDES 	+= `pkg-config --cflags opencv`
		include TargetMakefiles/Makefile.localisationmodule
	endif
endif
ifeq ($(MAKECMDGOALS),lidar)
	ifneq ($(OS),linux)
		@echo "LIDAR cannot be compiled on Windows systems"
		exit 1
	else
		LDLIBS +=
		LDFLAGS += 
		include TargetMakefiles/Makefile.lidar
	endif
endif
ifeq ($(MAKECMDGOALS),rosbee)
	ifneq ($(OS),linux)
		@echo "Rosbee cannot be compiled on Windows systems"
		exit 1
	else
		LDLIBS +=
		LDFLAGS += 
		include TargetMakefiles/Makefile.rosbee
	endif
endif
ifeq ($(MAKECMDGOALS),clean)
	include Makefile.clean
else
	INCLUDES 	+= $(patsubst %, -I%, $(MODULES))
	include $(MODULES:=module.mk)
	UI_HEADERS 	+= $(UI:.ui=.h)
	OBJ 		+= $(SRC:.cpp=.o)
endif


%.d : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MM -MT"$@" $< -MF $@
	
%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<
	
moc_%.cpp : %.h
	$(MOC) $< -o $@
	
ui_%.h : %.ui
	$(UIC) $< -o $@
