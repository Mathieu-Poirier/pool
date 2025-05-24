cmake_minimum_required(VERSION 3.15)
project(Pool)

# Conan toolchain (auto-generated)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# === Dependencies ===
find_package(GTest REQUIRED)

# === Internal Header-Only Library ===
add_library(poollib INTERFACE)
target_include_directories(poollib INTERFACE ${CMAKE_SOURCE_DIR}/include)


# === Main App ===
add_executable(pool src/main.cpp)
target_link_libraries(pool PRIVATE poollib)
target_compile_definitions(pool PRIVATE PROJECT_NAME="pool")
set_target_properties(pool PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
)

# === Test App ===
add_executable(pool_tests tests/test.cpp)
target_link_libraries(pool_tests PRIVATE poollib GTest::gtest GTest::gtest_main)
target_include_directories(pool_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(pool_tests PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
)
