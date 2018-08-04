##
#	@file	  CMakeLists.txt
#	@brief	Build the json_library
#
#	Builds the json lib static and shared, with the name of json_util
#
#	@author		Gabriel Shelton		sheltongabe
#	@date		  08-04-2018
#	@version	0.5
#

cmake_minimum_required(VERSION 2.8)

message("${JSON_LIB_NAME}")

project("{$JSON_LIB_NAME}_src")

# Configuration variables
set(HEADERS_DIR ${PROJECT_SOURCE_DIR}/../include)

# Include headers
include_directories(${HEADERS_DIR})

# Copy headers to project root include, after building a folder for the library in 
# root include
set(DIR_NAME ${CMAKE_SOURCE_DIR}/include/${JSON_LIB_NAME})
file(MAKE_DIRECTORY ${DIR_NAME})
file(GLOB LIB_HEADERS ${HEADERS_DIR}/*.h)
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

# Add static library
add_library("${JSON_LIB_NAME}_static" STATIC
	${LIB_SOURCES}
)