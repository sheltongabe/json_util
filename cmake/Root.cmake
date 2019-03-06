##
# @file		Root.cmake
# @brief	Ran during development to set root properties
# @details
# Sets a CMake project to be a root project instead of 
# a library.  This is included in the root CMakeLists
# file.
#
# @author	sheltongabe		Gabriel Shelton
# @date		2019-02-28

# Enable or Disable testing by commenting this out
enable_testing()

# Enable Debugging
set(CMAKE_CXX_FLAGS "${CXX_FLAGS} -ggdb")

# Set Build, Binary, and Library Directories
set(CMAKE_BINARY_OUTPUT ${CMAKE_SOURCE_DIR}/build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)