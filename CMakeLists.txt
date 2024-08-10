cmake_minimum_required(VERSION 3.23)

project(cp-base)

# target_compile_definitions(${PROJECT_NAME} PUBLIC _GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_LIBSTD)
# set(CMAKE_GLIB)

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_TESTS_DIR ${PROJECT_SOURCE_DIR}/test)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)
file(GLOB_RECURSE TESTS ${PROJECT_TESTS_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${TESTS})
find_package(GTest REQUIRED)

# if(GTest_FOUND)
target_link_libraries(${PROJECT_NAME} GTest::gtest)

include_directories(${PROJECT_HEADERS_DIR})
enable_testing()
add_test(NAME test COMMAND ${PROJECT_NAME})


# else()
#     message(FATAL_ERROR "Zlib not found")
# endif()
