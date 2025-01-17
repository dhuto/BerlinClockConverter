# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(berlin-clock-converter)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Add your source files
add_executable(berlin-clock-converter src/main.cpp)

# Link GoogleTest to your test executable
add_executable(main_test src/main_test.cpp)
target_link_libraries(main_test gtest_main)

include(GoogleTest)
gtest_discover_tests(main_test)