#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T13:31:07
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=gnu++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPI-UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    quadcopterwindow.cpp \
    quadcopter.cpp \
    SerialPort.cpp \
    SerialPortWindows.cpp \
    ExtendedMAVLinkMessage.cpp \
    MAVLinkExchanger.cpp \
    atvwindow.cpp \
    lidar.cpp \
    lidarwindow.cpp \
    rosbee.cpp \
    rosbeewindow.cpp \
    MAVLinkCommunicator.cpp \
    PriorityMessage.cpp \
    atv.cpp

HEADERS  += mainwindow.h \
    quadcopterwindow.h \
    quadcopter.h \
    Serial.h \
    SerialPort.h \
    SerialPortWindows.h \
    ExtendedMAVLinkMessage.h \
    MAVLinkExchanger.h \
    atvwindow.h \
    lidar.h \
    lidarwindow.h \
    Listener.h \
    otherstuff.h \
    rosbee.h \
    rosbeewindow.h \
    Subject.h \
    exceptions.h \
    MAVLinkCommunicator.h \
    PriorityMessage.h \
    StatusText.h \
    atv.h

FORMS    += mainwindow.ui \
    quadcopterwindow.ui \
    atvwindow.ui \
    lidarwindow.ui \
    rosbeewindow.ui

DISTFILES +=
