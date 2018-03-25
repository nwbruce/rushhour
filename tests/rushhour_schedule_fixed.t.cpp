#include <boost/test/unit_test.hpp>
#include <rushhour_schedule_fixed.h>

namespace rushhour {
namespace schedule {

BOOST_AUTO_TEST_CASE(Fixed_SteadyPeriod) {
  Fixed schedule(170.0, 100);
  BOOST_REQUIRE_EQUAL(100, schedule.size());

  for (auto ns : schedule) {
    BOOST_CHECK_CLOSE(1.0e9 / 170.0, static_cast<double>(ns.count()), 1.0);
  }
}

BOOST_AUTO_TEST_CASE(Fixed_SizeZero) {
  Fixed schedule(75.0, 0);
  BOOST_REQUIRE_EQUAL(0, schedule.size());
  BOOST_CHECK_THROW(schedule[0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Fixed_OutOfBounds) {
  Fixed schedule(75.0, 5);
  BOOST_REQUIRE_EQUAL(5, schedule.size());
  BOOST_CHECK_THROW(schedule[5], std::out_of_range);
}

}  // namespace schedule
}  // namespace rushhour
