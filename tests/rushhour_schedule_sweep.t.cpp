#include <boost/test/unit_test.hpp>
#include <rushhour_schedule_sweep.h>

namespace rushhour {
namespace schedule {

BOOST_AUTO_TEST_CASE(Sweep_IncreasingSweep) {
  Sweep schedule(2.0, 5.0, 100);
  BOOST_REQUIRE_EQUAL(100, schedule.size());

  BOOST_CHECK_CLOSE(1.0e9 / 2.0, static_cast<double>(schedule[0].count()), 1.0);
  auto last = std::chrono::nanoseconds::max();
  for (auto ns : schedule) {
    BOOST_CHECK_LE(ns.count(), last.count());
    last = ns;
  }
  BOOST_CHECK_CLOSE(1.0e9 / 5.0, static_cast<double>(schedule[schedule.size()-1].count()), 1.0);
}

BOOST_AUTO_TEST_CASE(Sweep_DecreasingSweep) {
  Sweep schedule(5.0, 2.0, 100);
  BOOST_REQUIRE_EQUAL(100, schedule.size());

  BOOST_CHECK_CLOSE(1.0e9 / 5.0, static_cast<double>(schedule[0].count()), 1.0);
  auto last = std::chrono::nanoseconds::min();
  for (auto ns : schedule) {
    BOOST_CHECK_GE(ns.count(), last.count());
    last = ns;
  }
  BOOST_CHECK_CLOSE(1.0e9 / 2.0, static_cast<double>(schedule[schedule.size()-1].count()), 1.0);
}

BOOST_AUTO_TEST_CASE(Sweep_FlatSweep) {
  Sweep schedule(75.0, 75.0, 10);
  BOOST_REQUIRE_EQUAL(10, schedule.size());
  for (auto ns : schedule) {
    BOOST_CHECK_CLOSE(1.0e9 / 75.0, static_cast<double>(ns.count()), 1.0);
  }
}

BOOST_AUTO_TEST_CASE(Sweep_SizeOfOne) {
  Sweep schedule(75.0, 105.0, 1);
  BOOST_REQUIRE_EQUAL(1, schedule.size());
  BOOST_CHECK_CLOSE(1.0e9 / 75.0, static_cast<double>(schedule[0].count()), 1.0);
}

BOOST_AUTO_TEST_CASE(Sweep_SizeZero) {
  Sweep schedule(75.0, 105.0, 0);
  BOOST_REQUIRE_EQUAL(0, schedule.size());
  BOOST_CHECK_THROW(schedule[0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Sweep_OutOfBounds) {
  Sweep schedule(75.0, 105.0, 5);
  BOOST_REQUIRE_EQUAL(5, schedule.size());
  BOOST_CHECK_THROW(schedule[5], std::out_of_range);
}

}  // namespace schedule
}  // namespace rushhour
