cmake_minimum_required (VERSION 3.5.1)
project(rushhour)

set (rushhour_VERSION_MAJOR 0)
set (rushhour_VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()


set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

find_package(Threads REQUIRED)

add_subdirectory (rushhour)
add_subdirectory (tests)
