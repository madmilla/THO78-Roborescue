CONFIG += c++11

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    aStar.cpp \
    ../../Common/waypoint.cpp \
    ../../Common/route.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    aStar.h \
    ../../Common/waypoint.h \
    ../../Common/route.h

