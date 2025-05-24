cmake_minimum_required(VERSION 3.15)
project(Pool)

# Conan toolchain (auto-generated)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Find GTest
find_package(GTest REQUIRED)

# === Main App Target ===
add_executable(pool src/main.cpp)
target_include_directories(pool PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(pool PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

# === Test Target ===
add_executable(pool_tests tests/test.cpp)
target_include_directories(pool_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(pool_tests PRIVATE GTest::gtest GTest::gtest_main)
set_target_properties(pool_tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)
