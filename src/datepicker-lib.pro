BUILD_DIR   = .build
MOC_DIR     = $$BUILD_DIR
OBJECTS_DIR = $$BUILD_DIR
RCC_DIR     = $$BUILD_DIR
UI_DIR      = $$BUILD_DIR

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
VERSION = 0.1.0
TARGET = datepicker
DESTDIR = ../lib

CODECFORSRC = UTF-8

DEFINES += DATEPICKER_LIBRARY

HEADERS += \
    datepicker/datepicker.h \
    datepicker/datepicker_common.h \
    datepicker/datepickerpopupfooter.h \
    datepicker/datepickerpopup.h \
    datepicker/datepickercalendar.h \
    datepicker/datepickercalendarnavigator.h \
    datepicker/datepickercalendarmonthview.h \
    datepicker/datepickercalendaryearview.h \
    datepicker/datepickercalendardecadeview.h \
    datepicker/datepickerabstractformater.h \
    datepicker/datepickerstandardformater.h

SOURCES += \
    datepicker_common.cpp \
    datepicker.cpp \
    datepickerpopupfooter.cpp \
    datepickerpopup.cpp \
    datepickercalendar.cpp \
    datepickercalendarnavigator.cpp \
    datepickercalendarmonthview.cpp \
    datepickercalendaryearview.cpp \
    datepickercalendardecadeview.cpp \
    datepickerabstractformater.cpp \
    datepickerstandardformater.cpp

RESOURCES = \
    datepicker_resources.qrc

TRANSLATIONS = \
    datepicker_ru.ts

