#include <boost/test/unit_test.hpp>
#include "rushhour_trial_trial.h"
#include "rushhour_schedule_fixed.h"
#include "rushhour_tests_steadyclockrange.h"
#include <unordered_set>

namespace rushhour {
namespace trial {

BOOST_AUTO_TEST_CASE(Trial_NoErrorsOnFixedSchedule) {
  schedule::Fixed schedule(150.0, 200);

  std::vector<bool> prepare_called(schedule.size(), false);
  auto do_prepare = [&](std::uint32_t index) {
    prepare_called[index] = true;
  };

  std::vector<bool> send_called(schedule.size(), false);
  auto do_send = [&](CompletionReport* completion) {
    send_called[completion->index()] = true;
    completion->succeeded();
  };

  tests::SteadyClockRange clock_range;
  clock_range.begin();
  auto results = Trial::run(schedule, do_prepare, do_send, std::chrono::milliseconds(5000), 3);
  clock_range.end();

  BOOST_CHECK_EQUAL(schedule.size(), results.size());

  double rate_sum = 0.0;

  auto prev = clock_range.begin_time();
  for (auto& result : results) {
    BOOST_CHECK_GT(result.elapsed().count(), 0);
    BOOST_CHECK(result.succeeded());

    BOOST_CHECK(clock_range.contains(result.started()));
    BOOST_CHECK(clock_range.contains(result.ended()));

    BOOST_CHECK(result.started() >= prev);
    std::chrono::nanoseconds delta = result.started() - prev;
    rate_sum += 1.0e9 / delta.count();
    prev = result.started();
  }

  double rate_avg = rate_sum / results.size();
  BOOST_CHECK_CLOSE(150.0, rate_avg, 5.0);

  for (auto called : prepare_called) {
    BOOST_CHECK(called);
  }

  for (auto called : send_called) {
    BOOST_CHECK(called);
  }
}

}  // namespace trial
}  // namespace rushhour
