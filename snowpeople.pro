#-------------------------------------------------
#
# Project created by QtCreator 2023-05-21T15:36:05
#
#-------------------------------------------------

QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snowpeople
TEMPLATE = app


SOURCES += main.cpp \
    background.cpp \
    gameoversign.cpp \
    menu.cpp \
    picture.cpp \
    mygame.cpp \
    people.cpp \
    snowball.cpp \
    warning.cpp \
    obstacle.cpp \
    car.cpp \
    story.cpp

HEADERS  += \
    background.h \
    gameoversign.h \
    menu.h \
    picture.h \
    mygame.h \
    people.h \
    snowball.h \
    warning.h \
    obstacle.h \
    car.h \
    story.h

FORMS    += \
    gameoversign.ui \
    menu.ui \
    mygame.ui \
    story.ui

RESOURCES += \
    resourse.qrc
