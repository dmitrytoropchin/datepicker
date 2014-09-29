cmake_minimum_required(VERSION 2.4)

project(datepicker-lib)

set(DATEPICKER_LIB_NAME datepicker)

if(MSVC)
	set(DATEPICKER_LIB_BUILD_LIBRARY_TYPE SHARED)
else(MSVC)
	set(DATEPICKER_LIB_BUILD_LIBRARY_TYPE SHARED CACHE STRING "datepicker library build type")
	set_property(CACHE DATEPICKER_LIB_BUILD_LIBRARY_TYPE PROPERTY STRINGS SHARED STATIC)
endif(MSVC)


if(HARVER_USE_QT_5)
	find_package(Qt5Core)
	find_package(Qt5Gui)
	find_package(Qt5Widgets)
else()
	find_package(Qt4)

	set(QT_USE_QTCORE TRUE)
	set(QT_USE_QTGUI TRUE)
endif(HARVER_USE_QT_5)

file(GLOB HDR src/datepicker/*.h)
file(GLOB SRCS src/*.cpp)

set(CMAKE_AUTOMOC ON)

if (HARVER_USE_QT_5)
  qt5_add_resources(RCC_FILE src/datepicker_resources.qrc)
else()
  include(${QT_USE_FILE})
  qt4_add_resources(RCC_FILE src/datepicker_resources.qrc)
endif(HARVER_USE_QT_5)

add_definitions(-DDATEPICKER_LIBRARY)

include_directories(src/)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(${DATEPICKER_LIB_NAME} ${DATEPICKER_LIB_BUILD_LIBRARY_TYPE} ${SRCS} ${HDR} ${RCC_FILE})

target_link_libraries(${DATEPICKER_LIB_NAME})

if(HARVER_USE_QT_5)
  qt5_use_modules(${DATEPICKER_LIB_NAME} Core Gui Widgets)
else()
  target_link_libraries(${DATEPICKER_LIB_NAME} ${QT_LIBRARIES})
endif(HARVER_USE_QT_5)

set(INCLUDE_INSTALLS 	src/datepicker/datepicker_common.h
    					src/datepicker/datepicker.h
					    src/datepicker/datepickerabstractformater.h
					    src/datepicker/datepickerstandardformater.h
					    src/datepicker/datepickerhumanreadableformater.h
	)

install(TARGETS ${DATEPICKER_LIB_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${INCLUDE_INSTALLS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${DATEPICKER_LIB_NAME})
