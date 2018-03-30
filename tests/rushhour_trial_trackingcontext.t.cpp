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

  tracking_context.wait();

  BOOST_CHECK_EQUAL(99u, tracking_context.index());
  BOOST_CHECK(tracking_context.succeeded());
  BOOST_CHECK(tracking_context.elapsed() >= std::chrono::milliseconds(249));
  BOOST_CHECK(tracking_context.elapsed() <= clock_range.duration());
}

BOOST_AUTO_TEST_CASE(TrackingContext_Failed) {
  TrackingContext tracking_context(99u);

  tests::SteadyClockRange clock_range;
  clock_range.begin();
  tracking_context.start();

  std::this_thread::sleep_for(std::chrono::milliseconds(250));

  tracking_context.completion_report()->failed();
  clock_range.end();

  tracking_context.wait();

  BOOST_CHECK_EQUAL(99u, tracking_context.index());
  BOOST_CHECK(!tracking_context.succeeded());
  BOOST_CHECK(tracking_context.elapsed() >= std::chrono::milliseconds(249));
  BOOST_CHECK(tracking_context.elapsed() <= clock_range.duration());
}

} /* namespace trial */
} /* namespace rushhour */
