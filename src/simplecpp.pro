QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 cmdline
TEMPLATE = lib
CONFIG += staticlib

#You can make your code fail to compile if it uses deprecated APIs.
#In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../include/color.cpp \
    ../include/sim.cpp \
    ../include/xevent.cpp \
    canvas.cpp \
    circle.cpp \
    ellipse.cpp \
    main.cpp \
    rectangle.cpp \
    text.cpp \
    turtleSim.cpp \
    turtle.cpp \
    sprite.cpp \
    polygon.cpp \
    commondefs.cpp \
    composite.cpp \
    line.cpp \

HEADERS += \
    ../include/canvas.h \
    ../include/circle.h \
    ../include/color.h \
    ../include/ellipse.h \
    ../include/eventcodes.h \
    ../include/graphicsim.h \
    ../include/keycodes.h \
    ../include/rectangle.h \
    ../include/sim.h \
    ../include/simplecpp.h \
    ../include/text.h \
    ../include/turtleSim.h \
    ../include/turtle.h \
    ../include/sprite.h \
    ../include/spriteInterface.h \
    ../include/commondefs.h \
    ../include/polygon.h \
    ../include/composite.h \
    ../include/line.h \
    ../include/xevent.h

INCLUDEPATH = ../include

#LIBS += -lgcov
#QMAKE_LFLAGS += -lgcov

#QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage --coverage
#QMAKE_LFLAGS += -fprofile-arcs -ftest-coverage --coverage
#QMAKE_CXXFLAGS_DEBUG += -O0 -g




# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
