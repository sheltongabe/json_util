##
#	@file	CMakeLists.txt
#	@brief	lib CMakeFile
#
#	Builds the json lib
#
#	@author		Gabriel Shelton		sheltongabe
#	@date		  08-02-2018
#	@version	0.4
#

cmake_minimum_required(VERSION 2.8)

project(json_lib)

# Configuration variables
set(LIB_NAME "json")

include_directories(${PROJECT_SOURCE_DIR}/include/)

# Copy headers to project root include
set(DIR_NAME ${CMAKE_SOURCE_DIR}/include/${LIB_NAME})
file(MAKE_DIRECTORY ${DIR_NAME})
file(GLOB LIB_HEADERS ${PROJECT_SOURCE_DIR}/include/*.h)
file(COPY ${LIB_HEADERS} DESTINATION ${DIR_NAME})

# Source filenames
set(LIB_SOURCES 
	"jsonable.cpp" 
	"json_compare.cpp"
	"json_exception.cpp"
	"json_file.cpp"
	"json_parser.cpp"
	"json_text_parser.cpp"
)

# Add json test executable
add_library(${LIB_NAME} STATIC
	${LIB_SOURCES}
)