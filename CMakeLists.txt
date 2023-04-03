cmake_minimum_required(VERSION 2.8)

project(WebServer CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Compiler flags.
set(CXX_FLAGS
    -g
    -Wall
    -std=c++11
    -D_PTHREADS
    -Wno-unused-parameter
)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O0")

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_BINARY_DIR} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})
message(STATUS "PROJECT_SOURCE_DIR = " ${PROJECT_SOURCE_DIR} " " )

# Output directory.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Includes.

include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(BEFORE src) # This is needed for gtest.

function(disable_target_warnings NAME)
    target_compile_options(${NAME} PRIVATE "-w")
endfunction()

######################################################################################################################
# Other CMake modules
# MUST BE ADDED AFTER CONFIGURING COMPILER PARAMETERS
######################################################################################################################
add_subdirectory(src)