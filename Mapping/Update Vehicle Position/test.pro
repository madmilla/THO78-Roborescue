TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c++14
QMAKE_CXXFLAGS += -std=c++14


SOURCES += \
	test.cpp \
	VehicleUpdater.cpp \
	VehicleState.cpp

HEADERS += \
	VehicleUpdater.h \
	VehicleState.h