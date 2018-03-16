#########################################
# rushhour library
#########################################

set(headers
  rushhour_inputschedule.h
  rushhour_unlimitedinputschedule.h)

set(sources
  rushhour_inputschedule.cpp
  rushhour_unlimitedinputschedule.cpp)

add_library(rushhour
  ${sources})

target_include_directories(rushhour PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})
