include Makefile.local
include TargetMakefiles/Makefile.modules

CXX 							= g++
CXXFLAGS						= -std=c++11 -DWIN32
INCLUDES 						= 
LDLIBS							= -lpthread -lws2_32
LDFLAGS							= 
SRC 							= 
UI 								= 
UI_HEADERS						=
MODULES 						= 

ifeq ($(MAKECMDGOALS),mission1)
	ifneq ($(OS),Windows_NT)
		@echo "Basestation is currently not compatible with linux based systems"
		exit 1
	else
		LDLIBS += -lQt5Core -lQt5Widgets -lQt5Gui
		LDFLAGS += -L$(QT_LIB_DIR)
		MOC	= $(QT_BIN_DIR)/moc.exe
		UIC	= $(QT_BIN_DIR)/uic.exe
		INCLUDES 	+= -I$(QT_INCL_DIR)
		include TargetMakefiles/Makefile.basestation
	endif
endif
ifeq ($(MAKECMDGOALS),localisationmodule)
	ifeq ($(OS),Windows_NT)
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
	ifeq ($(OS),Windows_NT)
		@echo "LIDAR cannot be compiled on Windows systems"
		exit 1
	else
		LDLIBS +=
		LDFLAGS += 
		include TargetMakefiles/Makefile.lidar
	endif
endif
ifeq ($(MAKECMDGOALS),rosbee)
	ifeq ($(OS),Windows_NT))
		@echo "Rosbee cannot be compiled on Windows systems"
		exit 1
	else
		LDLIBS +=
		LDFLAGS += 
		include TargetMakefiles/Makefile.rosbee
	endif
endif
ifeq ($(MAKECMDGOALS),environmentsimulator)
	ifneq ($(OS),Windows_NT)
		@echo "The Environment-simulator is currently not compatible with linux bases systems"
		exit 1
	else
		LDLIBS += -lQt5Core -lQt5Widgets -lQt5Gui
		LDFLAGS += -L$(QT_LIB_DIR)
		MOC	= $(QT_BIN_DIR)/moc.exe
		UIC	= $(QT_BIN_DIR)/uic.exe
		INCLUDES 	+= -I$(QT_INCL_DIR)
		include TargetMakefiles/Makefile.environmentsimulator
	endif
endif
ifeq ($(MAKECMDGOALS),clean)
	include TargetMakefiles/Makefile.clean
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
