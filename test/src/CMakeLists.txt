##
#	@file	  CMakeLists.txt
#	@brief	JSON test CMakeFile
#
#	Builds the test executable, and adds the tests 
#
#	@author		Gabriel Shelton		sheltongabe
#	@date		  08-04-2018
#	@version	0.5
#

cmake_minimum_required(VERSION 2.8)

project("{$JSON_LIB_NAME}_test")

# Configure executable settings
set(EXE_NAME "${JSON_LIB_NAME}_test")
set(HEADERS_DIR ${PROJECT_SOURCE_DIR}/../include)
set(JSON_HEADERS_DIR ${PROJECT_SOURCE_DIR}/../../include)

# Configure Test settings
set(NUM_TESTS 1000)
set(TEST_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/../results)
file(REMOVE ${TEST_OUTPUT_DIR})
file(MAKE_DIRECTORY ${TEST_OUTPUT_DIR})

# Include neccassary headers from the include file, and json include
include_directories(${HEADERS_DIR} ${JSON_HEADERS_DIR})

# Add json test executable
add_executable(${EXE_NAME}
	test_object.cpp
	json_util_test.cpp
)

# Link the executable with the json library
target_link_libraries(${EXE_NAME} "${JSON_LIB_NAME}_static")

# Add tests
foreach(iteration RANGE 1 ${NUM_TESTS})
	add_test(
		NAME "${JSON_LIB_NAME}_static_test_${iteration}"
		COMMAND ${EXE_NAME} ${iteration}
		WORKING_DIRECTORY ${TEST_OUTPUT_DIR}
	)
endforeach(iteration RANGE ${NUM_TESTS})