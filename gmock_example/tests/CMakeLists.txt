enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# gmock
add_executable(${PROJECT_NAME}_mocktest FCFileInfoMock.cpp)                                      
target_link_libraries(${PROJECT_NAME}_mocktest
                      PRIVATE ${PROJECT_NAME}_lib gtest gtest_main gmock_main)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(${PROJECT_NAME}_mocktest PRIVATE -Werror -Wall -Wextra)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  target_compile_options(${PROJECT_NAME}_mocktest
                         PRIVATE -Wall
                                 -Wextra
                                 -Weverything
                                 -Wno-c++98-compat
                                 -Wno-c++98-compat-pedantic)
endif()
add_test(${PROJECT_NAME}_mocktest ${PROJECT_NAME}_mocktest)


# gtest
add_executable(${PROJECT_NAME}_unittest FCFIleInfoTest.cpp)

target_link_libraries(${PROJECT_NAME}_unittest
                      PRIVATE ${PROJECT_NAME}_lib gtest gtest_main)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(${PROJECT_NAME}_unittest PRIVATE -Werror -Wall -Wextra)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  target_compile_options(${PROJECT_NAME}_unittest
                         PRIVATE -Wall
                                 -Wextra
                                 -Weverything
                                 -Wno-c++98-compat
                                 -Wno-c++98-compat-pedantic)
endif()

add_test(${PROJECT_NAME}_unittest ${PROJECT_NAME}_unittest)

# copy files for unit tests to build directory: set(BASE_TEST_RESOURCES
# test_resource) file(GLOB TEST_RESOURCES "${BASE_TEST_RESOURCES}/*") file(COPY
# ${TEST_RESOURCES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test_resource/)
