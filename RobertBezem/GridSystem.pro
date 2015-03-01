TEMPLATE = app
TARGET = GridSystem

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    drawWindow.cpp \
    mainwindow.cpp

HEADERS += \
    drawWindow.h \
    mainwindow.h

RESOURCES += \
    icons.qrc
