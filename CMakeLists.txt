##
#	@file	CMakeLists.txt
#	@brief	Parent CMakeFile
#
#	Builds the json_util project in its test modes
#
#	@author		Gabriel Shelton		sheltongabe
#	@date		  07-29-2018
#	@version	0.1
#

cmake_minimum_required(VERSION 2.8)

# Parent Project
project(json_util)

# Configure tests
enable_testing()
set(NUM_TESTS 1000)

# Set the compiler to use c++17 and gdb for debugging
set(CMAKE_CXX_FLAGS "${CXX_FLAGS} -ggdb -std=c++17")

# Set Build, Binary, and Library output directories; along with test working dir
set(CMAKE_BINARY_OUTPUT ${PROJECT_SOURCE_DIR}/build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)
file(REMOVE ${PROJECT_SOURCE_DIR}/test})
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/test)

# Compute the src
add_subdirectory(src/)

# Tests
foreach(iteration RANGE 1 ${NUM_TESTS})
	add_test(
		NAME json_util_${iteration}
		COMMAND json_test ${iteration}
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/test/
	)
endforeach(iteration RANGE ${NUM_TESTS})
