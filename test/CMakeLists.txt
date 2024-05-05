# Using https://google.github.io/googletest/quickstart-cmake.html as reference

cmake_minimum_required(VERSION 3.14)
project(UnitTests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include(FetchContent)

set(BENCHMARK_ENABLE_TESTING OFF)# to suppress benchmark internal tests

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG main # need main for benchmark::benchmark
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(
    googletest
    googlebenchmark)

enable_testing()

include_directories (${CMAKE_SOURCE_DIR}/src) 

add_executable(
  UnitTests
  GraphTests.cpp
  ${SRC_DIR}/Graph.cpp
)

target_link_libraries(UnitTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)

add_executable(
  Benchmark
  Benchmark.cpp
  ${SRC_DIR}/Graph.cpp
)
target_link_libraries(Benchmark PRIVATE benchmark::benchmark)

