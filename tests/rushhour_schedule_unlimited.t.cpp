#include <boost/test/unit_test.hpp>
#include <rushhour_schedule_unlimited.h>

namespace rushhour {
namespace schedule {

BOOST_AUTO_TEST_CASE(Unlimited_RightSizeAndValues) {
  Unlimited schedule(7);
  BOOST_REQUIRE_EQUAL(7, schedule.size());
  for (std::size_t i = 0; i < 7; i++) {
    BOOST_CHECK_EQUAL(0, schedule[i].count());
  }
}

BOOST_AUTO_TEST_CASE(Unlimited_SizeZero) {
  Unlimited schedule(0);
  BOOST_REQUIRE_EQUAL(0, schedule.size());
  BOOST_CHECK_THROW(schedule[0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Unlimited_OutOfBounds) {
  Unlimited schedule(5);
  BOOST_REQUIRE_EQUAL(5, schedule.size());
  BOOST_CHECK_THROW(schedule[5], std::out_of_range);
}

}  // namespace schedule
}  // namespace rushhour
