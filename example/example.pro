include(../datepicker.pri)

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = datepicker

INCLUDEPATH += \
    ../src

LIBS += \
    -L../lib -ldatepicker

SOURCES = \
    main.cpp
