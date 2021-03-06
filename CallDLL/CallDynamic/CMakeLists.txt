cmake_minimum_required(VERSION 3.5.1)
message(STATUS "CMake version: ${CMAKE_VERSION}")
project(CallDynamic LANGUAGES CXX)

set (deb_example_VERSION_MAJOR 0)
set (deb_example_VERSION_MINOR 2)
set (deb_example_VERSION_PATCH 2)
set (mylib_version "${deb_example_VERSION_MAJOR}.${deb_example_VERSION_MINOR}.${deb_example_VERSION_PATCH}")

set(CMAKE_INSTALL_RPATH $ORIGIN/lib)

if (MSVC)
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")
    find_library(DYNAMICLIB test.lib PATHS "${CMAKE_SOURCE_DIR}/../DynamicLibrary/build/Debug")
    find_library(DYNAMICLIBDLL test.dll PATHS "${CMAKE_SOURCE_DIR}/../DynamicLibrary/build/Debug")
else ()
    find_library(DYNAMICLIB test PATHS "${CMAKE_SOURCE_DIR}/../DynamicLibrary/build/")
endif ()

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(CallDynamic ${cpu_source_files})

target_include_directories(CallDynamic
	PUBLIC 
        "${CMAKE_SOURCE_DIR}/../DynamicLibrary/include/"
)

target_link_libraries(CallDynamic PUBLIC ${DYNAMICLIB})

# Binaries
install (TARGETS CallDynamic
    DESTINATION "${CMAKE_SOURCE_DIR}/DynamicExample")

# Library
if (MSVC)
    install (FILES "${DYNAMICLIBDLL}"
        DESTINATION "${CMAKE_SOURCE_DIR}/DynamicExample/")
else()
    install (FILES "${DYNAMICLIB}"
        DESTINATION "${CMAKE_SOURCE_DIR}/DynamicExample/lib")
endif ()

#includes, for APIs for example
install (DIRECTORY "${CMAKE_SOURCE_DIR}/../DynamicLibrary/include/"
    DESTINATION "${CMAKE_SOURCE_DIR}/DynamicExample/include")

############################################################
# Create DEB
############################################################

# Tell CPack to generate a .deb package
set(CPACK_GENERATOR "DEB")

# Set a Package Maintainer.
# This is required
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Isaac-Guillen")

# Set a Package Version
set(CPACK_PACKAGE_VERSION ${mylib_version})

# Include CPack
include(CPack)
