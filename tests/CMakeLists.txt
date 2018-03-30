#########################################
# rushhour unit tests
#########################################

set(sources
  rushhour_main.t.cpp
  rushhour_schedule_schedule.t.cpp
  rushhour_schedule_unlimited.t.cpp
  rushhour_schedule_sweep.t.cpp
  rushhour_schedule_fixed.t.cpp
  rushhour_trial_completionreport.t.cpp
  rushhour_trial_trackingcontext.t.cpp
  rushhour_trial_trial.t.cpp
  rushhour_results_result.t.cpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

if (Boost_FOUND)

add_executable(rushhour_test
  ${sources})

target_include_directories(rushhour_test
  PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(rushhour_test
  rushhour ${Boost_LIBRARIES})

add_test(NAME unit_tests COMMAND rushhour_test)

endif()
