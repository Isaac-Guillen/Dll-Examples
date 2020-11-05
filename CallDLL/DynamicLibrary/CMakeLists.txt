cmake_minimum_required(VERSION 3.5.1)
message(STATUS "CMake version: ${CMAKE_VERSION}")
project(test LANGUAGES CXX)

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(test SHARED ${cpu_source_files})

target_include_directories(test
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
