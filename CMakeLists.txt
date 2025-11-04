cmake_minimum_required(VERSION 4.0)
project(wa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_wa test_wa.cpp)
target_link_libraries(test_wa PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_wa)
