TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    aStar.cpp \
    line.cpp \
    Main.cpp \
    Map.cpp \
    point.cpp \
    polygon.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    aStar.h \
    line.hpp \
    map.hpp \
    point.hpp \
    polygon.h

