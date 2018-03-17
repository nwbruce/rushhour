#include <gtest/gtest.h>
#include <rushhour_schedule_unlimited.h>

namespace rushhour {
namespace schedule {

TEST(Unlimited, RightSizeAndValues) {
  Unlimited schedule(7);
  ASSERT_EQ(7, schedule.size());
  for (std::size_t i = 0; i < 7; i++) {
    EXPECT_EQ(0, schedule[i].count());
  }
}

TEST(Unlimited, SizeZero) {
  Unlimited schedule(0);
  ASSERT_EQ(0, schedule.size());
  EXPECT_THROW(schedule[0], std::out_of_range);
}

TEST(Unlimited, OutOfBounds) {
  Unlimited schedule(5);
  ASSERT_EQ(5, schedule.size());
  EXPECT_THROW(schedule[5], std::out_of_range);
}

}  // namespace schedule
}  // namespace rushhour
