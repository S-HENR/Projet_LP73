QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anthill.cpp \
    dirt.cpp \
    environnement.cpp \
    food.cpp \
    ground.cpp \
    idle.cpp \
    main.cpp \
    mainwindow.cpp \
    obstacle.cpp \
    ant.cpp \
    fullgrownant.cpp \
    larva.cpp \
    queen.cpp \
    state.cpp \
    warrior.cpp \
    worker.cpp

HEADERS += \
    anthill.h \
    dirt.h \
    environnement.h \
    food.h \
    ground.h \
    idle.h \
    mainwindow.h \
    obstacle.h \
    ant.h \
    fullgrownant.h \
    larva.h \
    queen.h \
    state.h \
    warrior.h \
    worker.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Fourmis_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
