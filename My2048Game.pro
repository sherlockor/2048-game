#-------------------------------------------------
#
# Project created by QtCreator 2017-09-23T22:47:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = My2048Game
TEMPLATE = app


SOURCES += main.cpp\
    cellwidget.cpp \
    headwidget.cpp \
    mainwidget.cpp \
    My2048Game.cpp \
    extrafunction.cpp \
    tailwidget.cpp \
    qcustomlabel.cpp

HEADERS  += \
    cellwidget.h \
    headwidget.h \
    mainwidget.h \
    My2048Game.h \
    extrafunction.h \
    tailwidget.h \
    qcustomlabel.h

FORMS    += widget.ui

RESOURCES += \
    qss.qrc
