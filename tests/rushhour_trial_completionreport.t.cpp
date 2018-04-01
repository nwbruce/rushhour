#include <boost/test/unit_test.hpp>
#include <rushhour_trial_completionreport.h>
#include "rushhour_tests_steadyclockrange.h"

namespace rushhour {
namespace trial {

BOOST_AUTO_TEST_CASE(CompletionReport_OnSucceeded) {
  std::promise<CompletionReport::Result> promise;
  auto future = promise.get_future();

  CompletionReport completion_report(std::move(promise), 35u);

  BOOST_CHECK_EQUAL(35u, completion_report.index());

  tests::SteadyClockRange clock_range;
  clock_range.begin();
  completion_report.succeeded();
  clock_range.end();

  auto result = future.get();
  BOOST_CHECK_EQUAL(true, result.first);
  BOOST_CHECK(clock_range.contains(result.second));
}

BOOST_AUTO_TEST_CASE(CompletionReport_OnFailed) {
  std::promise<CompletionReport::Result> promise;
  auto future = promise.get_future();

  CompletionReport completion_report(std::move(promise), 35u);

  BOOST_CHECK_EQUAL(35u, completion_report.index());

  tests::SteadyClockRange clock_range;
  clock_range.begin();
  completion_report.failed();
  clock_range.end();

  auto result = future.get();
  BOOST_CHECK_EQUAL(false, result.first);
  BOOST_CHECK(clock_range.contains(result.second));
}

}  // namespace trial
}  // namespace rushhour
