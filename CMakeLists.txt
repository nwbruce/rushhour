cmake_minimum_required (VERSION 2.8.11)
project(rushhour)

set (rushhour_VERSION_MAJOR 0)
set (rushhour_VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory (rushhour)
add_subdirectory (tests)
