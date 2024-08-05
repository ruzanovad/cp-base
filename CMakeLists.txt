cmake_minimum_required(VERSION 3.23)
project(cp-base)

set(CMAKE_CXX_STANDARD 14)

# Add the library
add_library(cp-base SHARED mkl.cpp)

# Find Google Test
find_package(GTest REQUIRED)

# Add executable for testing
add_executable(tests test_mkl.cpp)
target_link_libraries(tests GTest::GTest GTest::Main cp-base)

# Enable testing
enable_testing()

# Register the test
add_test(NAME MyTest COMMAND tests)