cmake_minimum_required(VERSION 3.0.0)
project(more_effe_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(--std=c++11)
add_compile_options(-O0)

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-O0 -Weffc++ -Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_subdirectory(src/basic)
add_subdirectory(src/operator)
add_subdirectory(src/exception)
add_subdirectory(src/efficiency)
add_subdirectory(src/technique)
add_subdirectory(src/etc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

