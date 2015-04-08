#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T19:50:25
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sprint1OpenGL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    algorithms.cpp \
    testperformance.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    line.h \
    algorithms.h \
    testperformance.h

FORMS    += mainwindow.ui
