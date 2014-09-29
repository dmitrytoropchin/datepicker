project(datepicker-library)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_AUTOMOC ON)

if(MSVC)
	set(DATEPICKER_LIB_BUILD_LIBRARY_TYPE SHARED)
else(MSVC)
	set(DATEPICKER_LIB_BUILD_LIBRARY_TYPE STATIC CACHE STRING "datepicker library build type")
	set_property(CACHE DATEPICKER_LIB_BUILD_LIBRARY_TYPE PROPERTY STRINGS STATIC SHARED)
endif(MSVC)

file(GLOB SRC source/*.cpp)
file(GLOB HDR source/datepicker/*.h)


if(USE_QT_5)
	qt5_add_resources(RCC_FILE resource/datepicker_resources.qrc)
else()
	include(${QT_USE_FILE})
	qt4_add_resources(RCC_FILE resource/datepicker_resources.qrc)
endif(USE_QT_5)

include_directories(./source/)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-DDATEPICKER_LIBRARY)

add_library(${DATEPICKER_LIBRARY_NAME} ${DATEPICKER_LIB_BUILD_LIBRARY_TYPE} ${SRC} ${HDR} ${RCC_FILE})

if(USE_QT_5)
  	qt5_use_modules(${DATEPICKER_LIBRARY_NAME} Core Gui Widgets)
else()
  	target_link_libraries(${DATEPICKER_LIBRARY_NAME} ${QT_LIBRARIES})
endif(USE_QT_5)

set(INSTALL_HEADERS source/datepicker/datepicker_common.h
				    source/datepicker/datepicker.h
				    source/datepicker/datepickerabstractformater.h
				    source/datepicker/datepickerstandardformater.h
				    source/datepicker/datepickerhumanreadableformater.h
	)

if(UNIX)
	install(TARGETS ${DATEPICKER_LIBRARY_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
	install(FILES ${HDR} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${DATEPICKER_LIBRARY_NAME})
endif(UNIX)
