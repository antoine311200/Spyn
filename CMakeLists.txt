# CMakeList.txt : CMake project for Spyn, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME Spyn)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)


project (${PROJECT_NAME})

# Add source to this project's executable.
add_executable (Spyn "Spyn.cpp" "Spyn.h" "src/distributions/Normal.h" "src/distributions/Law.h" "src/distributions/Normal.cpp" "src/utils/Constants.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Spyn PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(simple_test "tests/wrapper_test.cpp" "src/distributions/Normal.h" "src/distributions/Law.h" "src/distributions/Normal.cpp" "src/utils/Constants.h")

target_link_libraries(
	simple_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(simple_test)
