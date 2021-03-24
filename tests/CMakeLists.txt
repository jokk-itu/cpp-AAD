cmake_minimum_required(VERSION 3.16)

set(This datastructures_tests)
project(${This})
set(CMAKE_CXX_STANDARD 20)

set(Source
        Spatial/QuadTreeTest.cpp
        Helpers/BoundingBoxTest.cpp
        Helpers/Point2DTest.cpp)

enable_testing()

add_executable(${This} ${Source})
target_link_libraries(${This} datastructures_lib gtest gmock pthread gtest_main)
add_test(${This} ${This})

