##
#	@file	CMakeLists.txt
#	@brief	Parent CMakeFile
#
#	Builds the json_util project in its test modes
#
#	@author		Gabriel Shelton		sheltongabe
#	@date		  08_04-2018
#	@version	0.5
#

cmake_minimum_required(VERSION 2.8)

# Configure library name
set(JSON_LIB_NAME "json_util")

# Parent Project
project("${JSON_LIB_NAME}")


# Testing settings (comment out to disable testing for json_util)
enable_testing()
include(CTest)

# Set the compiler to use c++17 and gdb for debugging
set(CMAKE_CXX_FLAGS "${CXX_FLAGS} -ggdb -std=c++17")

# Set Build, Binary, and Library output directories; along with test working dir
set(CMAKE_BINARY_OUTPUT ${PROJECT_SOURCE_DIR}/build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)

# Build the library
add_subdirectory(src)

# If testing is enabled build the test program and tests
if(BUILD_TESTING)
	add_subdirectory(test/src)
endif()