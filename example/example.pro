BUILD_DIR   = .build
MOC_DIR     = $$BUILD_DIR
OBJECTS_DIR = $$BUILD_DIR
RCC_DIR     = $$BUILD_DIR
UI_DIR      = $$BUILD_DIR

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
