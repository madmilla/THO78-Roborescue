#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T13:59:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = firstProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gui.cpp \
    map.cpp \
    test.cpp

HEADERS  += mainwindow.h \
    gui.h \
    gui.h \
    map.h \
    test.h

FORMS    += mainwindow.ui \
    gui.ui

RESOURCES += \
    textures.qrc
