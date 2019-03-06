##
# @file		CMakeLists.txt [/]
# @brief	Setup The library if it is being used and executable
#
# @author	sheltongabe		Gabriel Shelton
# @date 	2019-03-06

cmake_minimum_required(VERSION 2.8)

###################################################
# Parameters for the project
# Should this project compile a library
set(COMPILE_LIB "y")

# Should this project compile an executable
set(COMPILE_EXECUTABLE "y")
###################################################



# This will set the project to be a executable
# Sets if it will try and compile the test section
if(COMPILE_EXECUTABLE)
	include(cmake/Root.cmake)
endif(COMPILE_EXECUTABLE)

# Set required compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -std=c++17")

# Handle Library
if(COMPILE_LIB)
	# Set library name
	# Set both the name and value of the library name.
	set(LIB_NAME "json_util")

	# Start the project for the library
	project("${LIB_NAME}")

	# Add the library
	add_subdirectory(src)
endif(COMPILE_LIB)

# Insert Dependency Includes here

# Handle Executable
if(COMPILE_EXECUTABLE)
	# Allow for tests
	include(CTest)

	# If it is an executable project compile the executable section
	if(BUILD_TESTING)
		add_subdirectory(test/src)
	endif()
endif(COMPILE_EXECUTABLE)