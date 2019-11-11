cmake_minimum_required(VERSION 3.10)
project(dbuscommunication LANGUAGES CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)

# common flags(even for tests)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS
      "-Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -fprofile-arcs -ftest-coverage -ggdb -ldbus-1")
endif()
set(CMAKE_BUILD_TYPE Debug)
include_directories("/usr/lib/x86_64-linux-gnu/dbus-1.0/include") 
include_directories("/usr/include/dbus-1.0/")


add_executable(${PROJECT_NAME} cdbus.cpp)

target_compile_options(${PROJECT_NAME} PUBLIC ${DBUS_CFLAGS_OTHER})