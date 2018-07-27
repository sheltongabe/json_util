##
#	@file	CMakeLists.txt
#	@brief	src CMakeFile
#
#	Builds the json_util project from src
#
#	@author		Gabriel Shelton		sheltongabe
#	@date		  07-27-2018
#	@version	0.1
#

cmake_minimum_required(VERSION 2.8)

project(src)

# Configure executable settings
set(EXE_NAME "json_test")

# Include neccassary headers from the top-level include file
include_directories(${CMAKE_SOURCE_DIR}/include/)

# Build the json library
add_subdirectory(json)

# Add json test executable
add_executable(${EXE_NAME}
	car.cpp
	main.cpp
)

# Link the executable with the json library
target_link_libraries(${EXE_NAME} "json")