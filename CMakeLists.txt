cmake_minimum_required(VERSION 3.26)
project(elevator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Enable testing for your project
enable_testing()

find_package(jsoncpp REQUIRED)

# Add the GTest submodule
# EXCLUDE_FROM_ALL prevents GTest from being built by default when building the main project,
# but it will be built when building targets that depend on it (like your tests).
add_subdirectory(extern/googletest EXCLUDE_FROM_ALL)
add_subdirectory(lib)

# Optionally, if you want to explicitly manage GTest build options, you can set them before add_subdirectory
# set(BUILD_GMOCK OFF CACHE BOOL "Build Google Mock" FORCE)
# set(BUILD_GTEST OFF CACHE BOOL "Build Google Test" FORCE)
# set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

# Include the GoogleTest CMake module for test discovery
include(GoogleTest)

# Add your test executable
add_executable(my_tests tests/FloorTest.cpp
        include/ElevatorFloor.h
        lib/ElevatorFloor.cpp
        include/Building.h
        tests/BuildingTest.cpp)

include_directories(my_tests PUBLIC ../include)

# Link your test executable against GTest libraries
# Use GTest::gtest_main for a pre-built main function, or GTest::gtest if you provide your own.
target_link_libraries(my_tests GTest::gtest_main)
target_link_libraries(my_tests ElevatorLibrary)
target_link_libraries(my_tests jsoncpp_lib)

# Discover tests using the GoogleTest module
gtest_discover_tests(my_tests)

# Mark GTest-related build options as advanced to keep the CMake cache clean
mark_as_advanced(
    BUILD_GMOCK
    BUILD_GTEST
    BUILD_SHARED_LIBS
    gmock_build_tests
    gtest_build_samples
    gtest_build_tests
    gtest_disable_pthreads
    gtest_force_shared_crt
    gtest_hide_internal_symbols
)
