TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    areacoveringalgorithm.cpp \
    arraymap.cpp \
    dimension.cpp \
    route.cpp \
    testcopter.cpp \
    waypoint.cpp

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    areacoveringalgorithm.h \
    arraymap.h \
    dimension.h \
    route.h \
    testcopter.h \
    waypoint.h

