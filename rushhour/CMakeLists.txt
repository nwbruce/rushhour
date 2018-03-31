#########################################
# rushhour library
#########################################

set(sources
  rushhour_schedule_schedule.cpp
  rushhour_schedule_unlimited.cpp
  rushhour_schedule_sweep.cpp
  rushhour_schedule_fixed.cpp
  rushhour_trial_completionreport.cpp
  rushhour_trial_trackingcontext.cpp
  rushhour_trial_trial.cpp
  rushhour_results_result.cpp
  rushhour_results_stats.cpp
  rushhour_results_summary.cpp)

add_library(rushhour
  ${sources})

target_include_directories(rushhour PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})
