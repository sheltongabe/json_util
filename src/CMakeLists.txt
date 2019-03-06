##
# @file		CMakeLists.txt [/src]
# @brief	Build the library
#
# @author	sheltongabe		Gabriel Shelton
# @date		2019-03-06

# Deal with headers
set(DIR_NAME ${CMAKE_SOURCE_DIR}/include/${LIB_NAME})
include(${CMAKE_SOURCE_DIR}/cmake/CopyHeaders.cmake)

# Set Sources
set(LIB_SOURCES
	"jsonable.cpp" 
	"json_compare.cpp"
	"json_exception.cpp"
	"json_file.cpp"
	"json_parser.cpp"
	"json_text_parser.cpp"
)

# Add shared Library
add_library("${LIB_NAME}_static" STATIC ${LIB_SOURCES})