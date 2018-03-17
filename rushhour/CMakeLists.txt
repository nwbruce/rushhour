#########################################
# rushhour library
#########################################

set(headers
  rushhour_schedule_schedule.h
  rushhour_schedule_unlimited.h
  rushhour_schedule_sweep.h)

set(sources
  rushhour_schedule_schedule.cpp
  rushhour_schedule_unlimited.cpp
  rushhour_schedule_sweep.cpp)

add_library(rushhour
  ${sources})

target_include_directories(rushhour PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})
