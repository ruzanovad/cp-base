cmake_minimum_required(VERSION 3.23)
project(cp-base)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_TESTS_DIR ${PROJECT_SOURCE_DIR}/test)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)
file(GLOB_RECURSE TESTS ${PROJECT_TESTS_DIR}/*.cpp)

find_package(GTest REQUIRED)

enable_testing()

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${TESTS})

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

add_test(test ${PROJECT_NAME})

include_directories(${PROJECT_HEADERS_DIR})
