#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T21:01:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapTestSchool
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    tile.cpp \
    grid.cpp

HEADERS  += \
    tile.h \
    grid.h \
    common.h \
    window.h

FORMS    += window.ui
