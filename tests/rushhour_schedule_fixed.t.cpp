#include <gtest/gtest.h>
#include <rushhour_schedule_fixed.h>

namespace rushhour {
namespace schedule {

TEST(Fixed, SteadyPeriod) {
  Fixed schedule(170.0, 100);
  ASSERT_EQ(100, schedule.size());

  for (auto ns : schedule) {
    EXPECT_NEAR(1.0e9 / 170.0, static_cast<double>(ns.count()), 1.0);
  }
}

TEST(Fixed, SizeZero) {
  Fixed schedule(75.0, 0);
  ASSERT_EQ(0, schedule.size());
  EXPECT_THROW(schedule[0], std::out_of_range);
}

TEST(Fixed, OutOfBounds) {
  Fixed schedule(75.0, 5);
  ASSERT_EQ(5, schedule.size());
  EXPECT_THROW(schedule[5], std::out_of_range);
}

}  // namespace schedule
}  // namespace rushhour
