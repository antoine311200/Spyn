# CMakeList.txt : CMake project for Spyn, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME Spyn)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)


project (${PROJECT_NAME})

# Add source to this project's executable.
add_executable (Spyn "Spyn.cpp" "Spyn.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Spyn PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
include(CTest)
enable_testing()