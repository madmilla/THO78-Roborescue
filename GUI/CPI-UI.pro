#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T13:31:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPI-UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    quadcopterwindow.cpp \
    quadcopter.cpp \
    atvwindow.cpp

HEADERS  += mainwindow.h \
    quadcopterwindow.h \
    quadcopter.h \
    atvwindow.h

FORMS    += mainwindow.ui \
    quadcopterwindow.ui \
    atvwindow.ui
