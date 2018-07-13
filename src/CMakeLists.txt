##
#	@file	CMakeLists.txt
#	@brief	src CMakeFile
#
#	Builds the json_util project from src
#
#	@author		Gabriel Shelton		sheltongabe
#	@date		  07-12-2018
#	@version	0.1
#

cmake_minimum_required(VERSION 2.8)

project(src)

# Include neccassary headers from the top-level include file
include_directories(${CMAKE_SOURCE_DIR}/include/)

# Add json test executable
add_executable(json
	main.cpp)