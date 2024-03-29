cmake_minimum_required(VERSION 3.10)
project(socketexample LANGUAGES CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)

# common flags(even for tests)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS
      "-Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -fprofile-arcs -ftest-coverage -ggdb")
endif()

set(CMAKE_BUILD_TYPE Debug)
# Link this 'library' to use the standard warnings
add_library(project_warnings INTERFACE)

target_compile_options(project_warnings
                       INTERFACE -Wall
                                 -Werror # treat all warnings as errors
                                 -Wextra # reasonable and standard
                                 -Wshadow # warn the user if a variable
                                          # declaration shadows one from a
                                          # parent context
                                 -Wnon-virtual-dtor # warn the user if a class
                                                    # with virtual functions has
                                                    # a non-virtual destructor.
                                                    # This helps catch hard to
                                                    # track down memory errors
                                 -Wold-style-cast # warn for c-style casts
                                 -Wcast-align # warn for potential performance
                                              # problem casts
                                 -Wunused # warn on anything being unused
                                 -Woverloaded-virtual # warn if you overload
                                                      # (not override) a virtual
                                                      # function
                                 -Wpedantic # warn if non-standard C++ is used
                                 -Wconversion # warn on type conversions that
                                              # may lose data
                                 -Wsign-conversion # warn on sign conversions
                                 -Wnull-dereference # warn if a null dereference
                                                    # is detected
                                 -Wdouble-promotion # warn if float is implicit
                                                    # promoted to double
                                 -Wformat=2 # warn on security issues around
                                            # functions that format output (ie
                                            # printf)
                                 -Wmisleading-indentation # warn if identation
                                                          # implies blocks where
                                                          # blocks do not exist
                                 -Wduplicated-cond # warn if if / else chain has
                                                   # duplicated conditions
                                 -Wduplicated-branches # warn if if / else
                                                       # branches have
                                                       # duplicated code
                                 -Wlogical-op # warn about logical operations
                                              # being used where bitwise were
                                              # probably wanted
                                 -Wuseless-cast # warn if you perform a cast to
                                                # the same type
                       )

set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -ggdb")

add_executable(${PROJECT_NAME}_client client.cpp)
add_executable(${PROJECT_NAME}_server server.cpp)

target_link_libraries(${PROJECT_NAME}_client)
target_link_libraries(${PROJECT_NAME}_server)
