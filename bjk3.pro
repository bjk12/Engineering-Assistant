#-------------------------------------------------
#
# Project created by QtCreator 2019-10-12T19:50:24
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bjk3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        page2.cpp\
        avilib.cpp \
    head.cpp \
    mywin.cpp \
    descrypt.cpp

HEADERS += \
        mainwindow.h \
        page2.h\
        avilib.h \
    head.h \
    mywin.h \
    descrypt.h

FORMS += \
        mainwindow.ui \
        page2.ui
CONFIG += precompile_header
PRECOMPILED_HEADER = stable.h
RC_ICONS = 7m.ico

DISTFILES += \
        user32.lib
