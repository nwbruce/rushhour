#########################################
# rushhour library
#########################################

set(sources
  rushhour.cpp)

add_library(rushhour
  ${sources})

target_include_directories(rushhour PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})
