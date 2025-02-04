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
    anthillstatus.cpp \
    dependentant.cpp \
    dirt.cpp \
    egg.cpp \
    environnement.cpp \
    feedingstate.cpp \
    food.cpp \
    goingbackhomestate.cpp \
    ground.cpp \
    idleegg.cpp \
    idlelarva.cpp \
    idlequeen.cpp \
    idlewarrior.cpp \
    idleworker.cpp \
    layinganeggstate.cpp \
    main.cpp \
    map_display.cpp \
    movingstate.cpp \
    obstacle.cpp \
    ant.cpp \
    larva.cpp \
    parameters.cpp \
    pickingupfoodstate.cpp \
    puttingdownfoodstate.cpp \
    queen.cpp \
    simulation.cpp \
    state.cpp \
    warrior.cpp \
    warrioreatingstate.cpp \
    worker.cpp \
    workereatingstate.cpp \
    AStar.cpp

HEADERS += \
    anthill.h \
    anthillstatus.h \
    dependentant.h \
    dirt.h \
    egg.h \
    environnement.h \
    feedingstate.h \
    food.h \
    goingbackhomestate.h \
    ground.h \
    idleegg.h \
    idlelarva.h \
    idlequeen.h \
    idlewarrior.h \
    idleworker.h \
    layinganeggstate.h \
    map_display.h \
    movingstate.h \
    map_display.h \
    obstacle.h \
    ant.h \
    larva.h \
    parameters.h \
    pickingupfoodstate.h \
    puttingdownfoodstate.h \
    queen.h \
    simulation.h \
    state.h \
    useful_functions.h \
    warrior.h \
    warrioreatingstate.h \
    worker.h \
    workereatingstate.h \
    AStar.hpp

FORMS += \
    anthillstatus.ui \
    parameters.ui

TRANSLATIONS += \
    Fourmis_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
