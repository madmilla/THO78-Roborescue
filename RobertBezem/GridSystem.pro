TEMPLATE = app
TARGET = GridSystem

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    drawWindow.cpp \
    mainWindow.cpp

HEADERS += \
    drawWindow.h \
    mainWindow.h

RESOURCES += \
    icons.qrc
