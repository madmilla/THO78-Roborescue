#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T10:02:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gui
TEMPLATE = app


SOURCES += \
    ../../../Src/GUI/mission-gui/mainwindow.cpp \
    ../../../Src/GUI/mission-gui/lidar-gui/lidarwindow.cpp \
    ../../../Src/GUI/mission-gui/ATV-gui/atvwindow.cpp \
    ../../../Src/GUI/mission-gui/quadcopter-gui/quadcopterwindow.cpp \
    ../../../Src/GUI/mission-gui/rosbee-gui/rosbeewindow.cpp \
    ../../../Src/GUI/mission-gui/map-gui/mapwindow.cpp

HEADERS  += \
    ../../../Src/GUI/mission-gui/mainwindow.h \
    ../../../Src/GUI/mission-gui/lidar-gui/lidarwindow.h \
    ../../../Src/GUI/mission-gui/ATV-gui/atvwindow.h \
    ../../../Src/GUI/mission-gui/quadcopter-gui/quadcopterwindow.h \
    ../../../Src/GUI/mission-gui/rosbee-gui/rosbeewindow.h \
    ../../../Src/GUI/mission-gui/map-gui/mapwindow.h

FORMS    += \
    ../../../Src/GUI/mission-gui/mainwindow.ui \
    ../../../Src/GUI/mission-gui/lidar-gui/lidarwindow.ui \
    ../../../Src/GUI/mission-gui/ATV-gui/atvwindow.ui \
    ../../../Src/GUI/mission-gui/quadcopter-gui/quadcopterwindow.ui \
    ../../../Src/GUI/mission-gui/rosbee-gui/rosbeewindow.ui \
    ../../../Src/GUI/mission-gui/map-gui/mapwindow.ui
