cmake_minimum_required(VERSION 3.5.1)
message(STATUS "CMake version: ${CMAKE_VERSION}")
project(test LANGUAGES CXX CUDA)

#search for OpenMP package
find_package (OpenMP REQUIRED)

#add linked if found
IF (OPENMP_FOUND)
    add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:${OpenMP_CXX_FLAGS}>")
    message(STATUS "Openmp added to MSVC compiler")

    add_compile_options("$<$<COMPILE_LANGUAGE:CUDA>:-Xcompiler=${OpenMP_CXX_FLAGS}>")
    message(STATUS "Openmp added to CUDA compiler")

    #add_link_options("$<$<COMPILE_LANGUAGE:CXX>:${OpenMP_CXX_FLAGS}>")
    #message(STATUS "Openmp added to MSVC Linker")

    #add_link_options("$<$<COMPILE_LANGUAGE:CUDA>:-Xlinker=${OpenMP_CXX_FLAGS}>")
    #message(STATUS "Openmp added to CUDA Linker")
ENDIF()  

if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES "52;60;61;70;75")
endif()

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cpp")#
file(GLOB gpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cu")

add_library(test SHARED ${cpu_source_files} ${gpu_source_files})


target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(test PUBLIC OpenMP::OpenMP_CXX)

set_target_properties(test PROPERTIES PREFIX "")
