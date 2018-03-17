#########################################
# download and build gtest
#########################################

# Download and unpack googletest at configure time
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
configure_file(CMakeLists.txt.in ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src ${CMAKE_BINARY_DIR}/googletest-build EXCLUDE_FROM_ALL)

target_include_directories(gmock_main SYSTEM BEFORE INTERFACE
  "${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")

#########################################
# gtest executable
#########################################

set(sources
  rushhour_inputschedule.t.cpp
  rushhour_unlimitedinputschedule.t.cpp
  rushhour_sweepinputschedule.t.cpp)

add_executable(rushhour_gtest
  ${sources})

target_link_libraries(rushhour_gtest
  gmock_main
  rushhour)

# add_test(NAME example_test COMMAND example)
