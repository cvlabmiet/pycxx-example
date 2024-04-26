cmake_minimum_required(VERSION 3.25)
project(pycxx-example VERSION 0.1.0 LANGUAGES CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 23)

add_library(dft SHARED dft.cpp)

add_executable(dfttest main.cpp)
target_link_libraries(dfttest dft)
target_include_directories(dfttest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_test(NAME dfttest COMMAND dfttest)
