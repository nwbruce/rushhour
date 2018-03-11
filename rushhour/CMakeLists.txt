#########################################
# rushhour library
#########################################

set(headers
  rushhour_inputschedule.h)

set(sources
  rushhour_inputschedule.cpp)

add_library(rushhour
  ${sources})

target_include_directories(rushhour PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})
