include(../../datepicker.pri)

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
VERSION = 0.1.0
TARGET = $$DATEPICKER_LIBRARY_NAME

CODECFORSRC = UTF-8

DEFINES += DATEPICKER_LIBRARY

INCLUDEPATH += \
    source

HEADERS += \
    source/datepicker/datepicker_common.h \
    source/datepicker/datepicker.h \
    source/datepicker/datepickerpopupfooter.h \
    source/datepicker/datepickerpopup.h \
    source/datepicker/datepickercalendar.h \
    source/datepicker/datepickercalendarnavigator.h \
    source/datepicker/datepickercalendarmonthview.h \
    source/datepicker/datepickercalendaryearview.h \
    source/datepicker/datepickercalendardecadeview.h \
    source/datepicker/datepickerabstractformater.h \
    source/datepicker/datepickerstandardformater.h \
    source/datepicker/datepickerhumanreadableformater.h \
    source/datepicker/datepickertimeedit.h

SOURCES += \
    source/datepicker_common.cpp \
    source/datepicker.cpp \
    source/datepickerpopupfooter.cpp \
    source/datepickerpopup.cpp \
    source/datepickercalendar.cpp \
    source/datepickercalendarnavigator.cpp \
    source/datepickercalendarmonthview.cpp \
    source/datepickercalendaryearview.cpp \
    source/datepickercalendardecadeview.cpp \
    source/datepickerabstractformater.cpp \
    source/datepickerstandardformater.cpp \
    source/datepickerhumanreadableformater.cpp \
    source/datepickertimeedit.cpp

RESOURCES = \
    resource/datepicker_resources.qrc

TRANSLATIONS = \
    resource/locale/datepicker_en.ts \
    resource/locale/datepicker_ru.ts

target.path = $$INSTALL_PREFIX/lib
headers.path = $$INSTALL_PREFIX/include/$$DATEPICKER_LIBRARY_NAME
headers.files = \
    source/datepicker/datepicker_common.h \
    source/datepicker/datepicker.h \
    source/datepicker/datepickerabstractformater.h \
    source/datepicker/datepickerstandardformater.h \
    source/datepicker/datepickerhumanreadableformater.h

INSTALLS = target headers
