QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camera.cpp \
    color.cpp \
    light.cpp \
    main.cpp \
    mainwindow.cpp \
    material.cpp \
    placment.cpp \
    scene.cpp \
    sphere.cpp \
    vector.cpp

HEADERS += \
    camera.hpp \
    color.hpp \
    constants.hpp \
    light.hpp \
    mainwindow.h \
    material.hpp \
    placment.hpp \
    scene.hpp \
    sphere.hpp \
    vector.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
