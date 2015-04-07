QT += widgets opengl

HEADERS       = mainwindow.h \
    openglwidget.h
SOURCES       = main.cpp \
                mainwindow.cpp \
    openglwidget.cpp
#! [0]
RESOURCES     = application.qrc
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target
