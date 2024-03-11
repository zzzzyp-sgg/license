cmake_minimum_required(VERSION 3.0)
project(LICENSE)

aux_source_directory (./src/ SRC_LIST)

set(CMAKE_C_FLAGS "-std=gnu99")
set(CMAKE_BUILD_TYPE Debug)

add_executable (test test.c ${SRC_LIST})

add_library(DLicense SHARED ${SRC_LIST})


set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)