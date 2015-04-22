#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T13:31:07
#
#-------------------------------------------------

QT       += core gui opengl
QMAKE_CXXFLAGS += -std=gnu++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPI-UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    quadcopterwindow.cpp \
    atvwindow.cpp \
    lidarwindow.cpp \
    rosbeewindow.cpp \\
    mapwindow.cpp

HEADERS  += mainwindow.h \
    quadcopterwindow.h \
    atvwindow.h \
    lidarwindow.h \
    rosbeewindow.h \
    mapwindow.h

FORMS    += mainwindow.ui \
    quadcopterwindow.ui \
    atvwindow.ui \
    lidarwindow.ui \
    rosbeewindow.ui \
    mapwindow.ui

DISTFILES +=
