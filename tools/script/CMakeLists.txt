cmake_minimum_required(VERSION 3.5.1)

# set project information
project(cgraph)
set(PROJECT "cgraph")
set(VERSION "0.0.0")

# set project configuration
set(CMAKE_C_COMPILER "cc")
set(CMAKE_C_FLAGS "-std=c89 -Wall -pedantic -fPIC")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g -DDEBUG -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O2")
set(CMAKE_BUILD_TYPE "Debug")

set(INC "${PROJECT_SOURCE_DIR}/include")
set(SRC "${PROJECT_SOURCE_DIR}/src")
set(SRC_TYPE "${SRC}/type")
set(LIB "${PROJECT_SOURCE_DIR}/lib")
set(TST "${PROJECT_SOURCE_DIR}/tests")
set(DOC "${PROJECT_SOURCE_DIR}/doc")

include_directories(${INC} ${SRC_TYPE})
file(GLOB_RECURSE SRC_LIST "${SRC}/*.c")
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
enable_testing()
add_executable(TEST_CGRAPH "${TST}/cgraph.c")
target_link_libraries(TEST_CGRAPH m LIBSTATIC)
add_test(TEST_CGRAPH)

# create document of cgraph
find_package(GtkDoc 1.25 REQUIRED)

# Create the doc-libmeep target.
# gtk_doc_add_module(
#   libmeep ${CMAKE_SOURCE_DIR}/libmeep
#     XML meep-docs.xml
#     LIBRARIES libmeep
# )

# Build doc-libmeep as part of the default target. Without this, you would
# have to explicitly run something like `make doc-libmeep` to build the docs.
# add_custom_target(documentation ALL DEPENDS doc-libmeep)

# Install the docs. (This assumes you're using the GNUInstallDirs CMake module
# to set the CMAKE_INSTALL_DOCDIR variable correctly).
# install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libmeep/html
#         DESTINATION ${CMAKE_INSTALL_DOCDIR})
