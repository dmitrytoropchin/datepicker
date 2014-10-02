project(datepicker-test)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_AUTOMOC ON)

include_directories(./)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${DATEPICKER_LIBRARY_DIR})

add_executable(${PROJECT_NAME} main.cpp)

if(USE_QT_5)
	target_link_libraries(${PROJECT_NAME} ${DATEPICKER_LIBRARY_NAME})
  	qt5_use_modules(${PROJECT_NAME} ${DATEPICKER_LIBRARY_NAME} Core Gui Widgets)
else()
	include(${QT_USE_FILE})
  	target_link_libraries(${PROJECT_NAME} ${DATEPICKER_LIBRARY_NAME} ${QT_LIBRARIES})
endif(USE_QT_5)
