cmake_minimum_required(VERSION 3.10)
project(BA)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-pthread -g")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} -Wall")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -Wall")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

include_directories(source)
add_executable(WorkingTitle source/main.c source/display.cpp source/exception.cpp source/ops.c)
target_link_libraries(WorkingTitle SDL2)
