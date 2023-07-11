cmake_minimum_required(VERSION 3.21.0)
project(cpplog)

add_library(cpplog INTERFACE)
target_include_directories(cpplog INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)