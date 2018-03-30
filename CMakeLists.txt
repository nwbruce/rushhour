cmake_minimum_required (VERSION 3.10.3)
project(rushhour)

set (rushhour_VERSION_MAJOR 0)
set (rushhour_VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory (rushhour)
add_subdirectory (tests)
