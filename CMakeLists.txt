cmake_minimum_required(VERSION 3.15)
project(Pool)

# Include Conan toolchain (auto-generated)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Create executable
add_executable(pool src/main.cpp)

# Find GTest
find_package(GTest REQUIRED)

# Link GTest to your executable (corrected name)
target_link_libraries(pool GTest::gtest GTest::gtest_main)

