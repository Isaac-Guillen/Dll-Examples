cmake_minimum_required(VERSION 3.5.1)
message(STATUS "CMake version: ${CMAKE_VERSION}")
project(test LANGUAGES CXX CUDA)

#option(USE_CUDA "Use CUDA" ON)
find_package (OpenMP REQUIRED)

IF (OPENMP_FOUND) 
    SET(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -Xcompiler=${OpenMP_CXX_FLAGS}") 
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${OpenMP_CXX_FLAGS}")
    message(STATUS "Openmp added to cuda linker") 
ENDIF()  

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB gpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cu")

#enable_language("CUDA")
add_library(test SHARED ${cpu_source_files} ${gpu_source_files})

target_include_directories(test
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(test PUBLIC OpenMP::OpenMP_CXX)