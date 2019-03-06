##
# @file 	CMakeLists.txt [/test/src]
# @brief	Build the exe
#
# @author	sheltongabe		Gabriel Shelton
# @date		2019-03-06

set(EXE_NAME "${LIB_NAME}_exe")

project(${EXE_NAME})

# Include the exe include directory and library includes
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/../include")

# Build the Executable
add_executable(${EXE_NAME}
	test_object.cpp
	json_util_test.cpp
)

# Link it
target_link_libraries(${EXE_NAME} "${LIB_NAME}_static")

# Additional commands required for your project

# Configure Test settings
set(NUM_TESTS 1000)
set(TEST_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/../results)
file(REMOVE ${TEST_OUTPUT_DIR})
file(MAKE_DIRECTORY ${TEST_OUTPUT_DIR})

# Add tests
foreach(iteration RANGE 1 ${NUM_TESTS})
	add_test(
		NAME "${LIB_NAME}_test_${iteration}"
		COMMAND ${EXE_NAME} ${iteration}
		WORKING_DIRECTORY ${TEST_OUTPUT_DIR}
	)
endforeach(iteration RANGE ${NUM_TESTS})