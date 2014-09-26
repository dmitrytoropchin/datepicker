include(../datepicker.pri)

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
VERSION = 0.1.0
TARGET = datepicker
DESTDIR = ../lib

CODECFORSRC = UTF-8

DEFINES += DATEPICKER_LIBRARY

HEADERS += \
    datepicker/datepicker_common.h \
    datepicker/datepicker.h \
    datepicker/datepickerpopupfooter.h \
    datepicker/datepickerpopup.h \
    datepicker/datepickercalendar.h \
    datepicker/datepickercalendarnavigator.h \
    datepicker/datepickercalendarmonthview.h \
    datepicker/datepickercalendaryearview.h \
    datepicker/datepickercalendardecadeview.h \
    datepicker/datepickerabstractformater.h \
    datepicker/datepickerstandardformater.h \
    datepicker/datepickerhumanreadableformater.h

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
    datepickerstandardformater.cpp \
    datepickerhumanreadableformater.cpp

RESOURCES = \
    datepicker_resources.qrc

TRANSLATIONS = \
    datepicker_ru.ts

target.path = $$INSTALL_PREFIX/lib
headers.path = $$INSTALL_PREFIX/include/datepicker
headers.files = \
    datepicker/datepicker_common.h \
    datepicker/datepicker.h \
    datepicker/datepickerabstractformater.h \
    datepicker/datepickerstandardformater.h \
    datepicker/datepickerhumanreadableformater.h

INSTALLS = target headers
