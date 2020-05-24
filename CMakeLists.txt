cmake_minimum_required(VERSION 3.5.1)

# set project information
project(cgraph)
set(PROJECT "cgraph")
set(VERSION "0.0.0")

# set project configuration
set(CXX_FLAGS -ansi –pedantic -pedantic-errors -Wall -fPIC)
set(CXX_FLAGS_DEBUG "${CXX_FLAGS} -g -DDEBUG")
set(CXX_FLAGS_RELEASE "${CXX_FLAGS} -static -O2")
SET(CMAKE_BUILD_TYPE "Release")

set(INC "${PROJECT_SOURCE_DIR}/include")
set(SRC "${PROJECT_SOURCE_DIR}/src")
set(LIB "${PROJECT_SOURCE_DIR}/lib")
set(TST "${PROJECT_SOURCE_DIR}/test")

include_directories(${INC})
file(GLOB SRC_LIST "${SRC}/*.c")
set(LIBRARY_OUTPUT_PATH ${LIB})
set(EXECUTABLE_OUTPUT_PATH ${TST})

# create shared library of cgraph
add_library(LIBSHARED SHARED ${SRC_LIST})
set_target_properties(LIBSHARED PROPERTIES OUTPUT_NAME ${PROJECT})
set_target_properties(LIBSHARED PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(LIBSHARED PROPERTIES VERSION ${VERSION} SOVERSION 1)

# create static library of cgraph
add_library(LIBSTATIC STATIC ${SRC_LIST})
set_target_properties(LIBSTATIC PROPERTIES OUTPUT_NAME ${PROJECT})
set_target_properties(LIBSTATIC PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# create binary file of cgraph to test
add_executable(${PROJECT} ${TST}/cgraph.c)
target_link_libraries(${PROJECT} LIBSTATIC)
target_link_libraries(${PROJECT} m)