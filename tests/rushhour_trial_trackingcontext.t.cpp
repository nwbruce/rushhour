#include <boost/test/unit_test.hpp>
#include "rushhour_trial_trackingcontext.h"
#include "rushhour_tests_steadyclockrange.h"
#include <thread>

namespace rushhour {
namespace trial {

BOOST_AUTO_TEST_CASE(TrackingContext_Succeeded) {
  TrackingContext tracking_context(99u);

  tests::SteadyClockRange clock_range;
  clock_range.begin();
  tracking_context.start();

  std::this_thread::sleep_for(std::chrono::milliseconds(250));

  tracking_context.completion_report()->succeeded();
  clock_range.end();

  auto result = tracking_context.get_result(std::chrono::steady_clock::now());

  BOOST_CHECK(result.succeeded());
  BOOST_CHECK(result.elapsed() >= std::chrono::milliseconds(249));
  BOOST_CHECK_LE(result.elapsed().count(), clock_range.duration().count());
}

BOOST_AUTO_TEST_CASE(TrackingContext_Failed) {
  TrackingContext tracking_context(99u);

  tests::SteadyClockRange clock_range;
  clock_range.begin();
  tracking_context.start();

  std::this_thread::sleep_for(std::chrono::milliseconds(250));

  tracking_context.completion_report()->failed();
  clock_range.end();

  auto result = tracking_context.get_result(std::chrono::steady_clock::now());

  BOOST_CHECK(!result.succeeded());
  BOOST_CHECK(result.elapsed() >= std::chrono::milliseconds(249));
  BOOST_CHECK_LE(result.elapsed().count(), clock_range.duration().count());
}

BOOST_AUTO_TEST_CASE(TrackingContext_TimedOut) {
  TrackingContext tracking_context(99u);

  tests::SteadyClockRange clock_range;
  clock_range.begin();
  tracking_context.start();

  auto result = tracking_context.get_result(std::chrono::steady_clock::now() + std::chrono::milliseconds(250));
  clock_range.end();

  BOOST_CHECK(!result.succeeded());
  BOOST_CHECK(result.elapsed() >= std::chrono::milliseconds(249));
  BOOST_CHECK_LE(result.elapsed().count(), clock_range.duration().count());
}

} /* namespace trial */
} /* namespace rushhour */
