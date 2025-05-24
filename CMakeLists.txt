cmake_minimum_required(VERSION 3.15)
project(TimeKeeper)

# Include Conan toolchain (auto-generated)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Create executable
add_executable(time_keeper src/main.cpp)

# Find GTest
find_package(GTest REQUIRED)

# Link GTest to your executable
target_link_libraries(time_keeper GTest::gtest GTest::gtest_main)

