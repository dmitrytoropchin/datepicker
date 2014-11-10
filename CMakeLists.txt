project(datepicker)

cmake_minimum_required(VERSION 2.8)

#SET (CMAKE_BUILD_TYPE "Debug")

option(USE_QT_5 "Use Qt 5" NO)
option(DATEPICKER_BUILD_UNIT_TEST "Build datepicker library unit test" YES)

set(DATEPICKER_LIBRARY_NAME datepicker)
set(DATEPICKER_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source/library/source)

if(USE_QT_5)
	find_package(Qt5Core)
	find_package(Qt5Gui)
	find_package(Qt5Widgets)
else()
	find_package(Qt4)

	set(QT_USE_QTCORE TRUE)
	set(QT_USE_QTGUI TRUE)
endif(USE_QT_5)

add_subdirectory(source/library)

if (DATEPICKER_BUILD_UNIT_TEST)
    add_subdirectory(source/unit-test)
endif(DATEPICKER_BUILD_UNIT_TEST)

