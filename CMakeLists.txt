cmake_minimum_required(VERSION 3.10)
project(BerlinClockConverter)

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

# Add your source files for the main application
add_executable(BerlinClockConverter
  src/main.cpp
  src/BerlinClock.cpp
  src/TimeValidator.cpp
  src/ITimeValidator.h
)

add_executable(BerlinClockTest src/BerlinClockTest.cpp src/BerlinClock.cpp)
add_executable(TimeValidatorTest src/TimeValidatorTest.cpp src/ITimeValidator.h src/TimeValidator.cpp src/TimeValidator.h)

# Link GoogleTest to your test executables
target_link_libraries(BerlinClockTest gtest_main)
target_link_libraries(TimeValidatorTest gtest_main)

include(GoogleTest)
gtest_discover_tests(BerlinClockTest)
gtest_discover_tests(TimeValidatorTest)
