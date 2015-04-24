#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T11:43:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = environment_test
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    editmapwindow.cpp \
    map.cpp \
    simulatemap.cpp \
    simulatemapwindow.cpp \
    test.cpp \
    checkpoint.cpp \
    PointCloud.cpp \

HEADERS  += mainwindow.h \
    editmapwindow.h \
    map.h \
    simulatemap.h \
    simulatemapwindow.h \
    test.h \
    values.h \
    checkpoint.h \
    PointCloud.h \

FORMS    += mainwindow.ui \
    editmapwindow.ui \
    simulatemapwindow.ui
