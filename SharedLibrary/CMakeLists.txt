cmake_minimum_required(VERSION 3.5.1)
message(STATUS "CMake version: ${CMAKE_VERSION}")
project(test LANGUAGES CXX CUDA)

#search for OpenMP package
find_package (OpenMP REQUIRED)

#add linked if found
IF (OPENMP_FOUND) 
    SET(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -Xcompiler=${OpenMP_CXX_FLAGS}") 
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${OpenMP_CXX_FLAGS}")
    message(STATUS "Openmp added to cuda linker") 
ENDIF()  

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB gpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cu")

add_library(test SHARED ${cpu_source_files} ${gpu_source_files})

target_include_directories(test
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

#add multiple SASS code for previous releases of cuda and PTX for greater than 75
target_compile_options(test PRIVATE  
"$<$<COMPILE_LANGUAGE:CUDA>:SHELL:
-gencode arch=compute_52,code=sm_52 
-gencode arch=compute_60,code=sm_60 
-gencode arch=compute_61,code=sm_61 
-gencode arch=compute_70,code=sm_70
-gencode arch=compute_75,code=sm_75
-gencode arch=compute_75,code=compute_75>")


target_link_libraries(test PUBLIC OpenMP::OpenMP_CXX)
set_target_properties(test PROPERTIES PREFIX "")
