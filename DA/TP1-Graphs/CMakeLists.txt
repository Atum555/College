cmake_minimum_required(VERSION 3.26)
project(da2425_p01_student)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_BUILD_TYPE_TMP "${CMAKE_BUILD_TYPE}" )
set( CMAKE_BUILD_TYPE "Release" )
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(TP1)

set( CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_TMP} )

add_executable(da2425_p01_student
        TP1/ex1.cpp
        TP1/ex2.cpp
        TP1/ex3.cpp
        TP1/ex4.cpp
        TP1/ex5.cpp
        TP1/tests.cpp
        data_structures/createGraphs.cpp
        data_structures/createGraphs.h)

target_link_libraries(da2425_p01_student gtest gtest_main gmock gmock_main)
