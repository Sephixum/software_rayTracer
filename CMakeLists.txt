cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(
  Raytracing
  DESCRIPTION "Sample code from the book 'Ray Tracing in one weekend'"
  LANGUAGES C CXX)

add_executable(output)

target_include_directories(output PRIVATE include/ include/rt/
                                          include/rt/utils/ include/rt/globals/)

target_sources(output PRIVATE src/main.cpp src/Sphere.cpp)

target_compile_options(output PRIVATE -Wall)
