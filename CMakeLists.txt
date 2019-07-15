cmake_minimum_required(VERSION 3.10)
project(BA)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

include_directories(source)
add_executable(WorkingTitle source/main.c source/display.cpp source/exception.cpp)
target_link_libraries(WorkingTitle SDL2)
