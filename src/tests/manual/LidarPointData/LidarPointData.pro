#-------------------------------------------------
#
# Project created by QtCreator 2015-03-11T11:46:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LidarPointData
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Lidar.cpp \
    LidarThread.cpp \
    LidarController.cpp \
    PointCloud.cpp

HEADERS  += mainwindow.h \
    Lidar.h \
    LidarThread.h \
    LidarController.h \
    PointCloud.h

FORMS    += mainwindow.ui


unix|win32: LIBS += -L$$PWD/lib/ -lrplidar_driver

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

CONFIG += c++11
