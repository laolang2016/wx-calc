cmake_minimum_required (VERSION 3.24)

project(wx-calc_test CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(${CMAKE_SOURCE_DIR}/third)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(. TEST_SRCS)

add_executable(${PROJECT_NAME} ${TEST_SRCS})

target_link_libraries(${PROJECT_NAME} ${lib_calc_kernel})

add_test(NAME wx-calc_test COMMAND wx-calc_test)

