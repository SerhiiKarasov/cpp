set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_library(${PROJECT_NAME}_lib
            FCFileInfo.cpp )

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(${PROJECT_NAME}_lib PRIVATE -Werror -Wall -Wextra)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  target_compile_options(${PROJECT_NAME}_lib
                         PRIVATE -Wall
                                 -Wextra
                                 -Weverything
                                 -Wno-c++98-compat
                                 -Wno-c++98-compat-pedantic)
endif()
target_compile_features(${PROJECT_NAME}_lib PUBLIC cxx_std_17)
add_executable(${PROJECT_NAME} gmock_example.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)
