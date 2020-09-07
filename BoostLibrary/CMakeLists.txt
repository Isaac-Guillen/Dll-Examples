cmake_minimum_required(VERSION 3.5.1)
message(STATUS "CMake version: ${CMAKE_VERSION}")
project(test LANGUAGES CXX CUDA)

find_package(OpenMP REQUIRED)
find_package(Boost REQUIRED COMPONENTS python)
find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)

IF (OPENMP_FOUND) 
    SET(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -Xcompiler=${OpenMP_CXX_FLAGS}") 
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${OpenMP_CXX_FLAGS}")
    message(STATUS "Openmp added to cuda linker")
ENDIF()  

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB gpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cu")

add_library(pylib SHARED ${cpu_source_files} ${gpu_source_files})

target_include_directories(pylib
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIR}
        ${PYTHON_INCLUDE_DIRS}
)

target_link_libraries(pylib
    PUBLIC
        OpenMP::OpenMP_CXX
        ${Boost_LIBRARIES}
        ${PYTHON_LIBRARIES})

set_target_properties(pylib PROPERTIES SUFFIX .so)
set_target_properties(pylib PROPERTIES PREFIX "")
