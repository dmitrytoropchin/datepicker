include(../../datepicker.pri)

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = $$DATEPICKER_LIBRARY_NAME-test

INCLUDEPATH += \
    $$DATEPICKER_LIBRARY_PATH/source

LIBS += \
    -L$$DATEPICKER_LIBRARY_PATH -ldatepicker

SOURCES = \
    main.cpp
