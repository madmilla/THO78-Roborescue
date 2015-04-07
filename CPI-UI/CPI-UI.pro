#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T13:31:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = CPI-UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    quadcopterwindow.cpp \
    atv.cpp \
    quadcopter.cpp \
    rosbeewindow.cpp \
    rosbee.cpp \
    tests.cpp \
    lidar.cpp \
    lidarwindow.cpp \
    atvwindow.cpp

HEADERS  += mainwindow.h \
    quadcopterwindow.h \
    atv.h \
    quadcopter.h \
    rosbeewindow.h \
    otherstuff.h \
    rosbee.h \
    exceptions.h \
    test.h \
    tests.h \
    lidar.h \
    lidarwindow.h \
    atvwindow.h

FORMS    += mainwindow.ui \
    quadcopterwindow.ui \
    rosbeewindow.ui \
    lidarwindow.ui \
    atvwindow.ui
