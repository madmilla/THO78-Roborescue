QT += widgets

HEADERS       = mainwindow.h \
    map.h \
    mapcanvas.h
SOURCES       = mainwindow.cpp \
                main.cpp \
    map.cpp \
    mapcanvas.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/menus
INSTALLS += target
