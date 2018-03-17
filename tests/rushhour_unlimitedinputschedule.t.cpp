#include "rushhour_unlimitedinputschedule.h"
#include <gtest/gtest.h>

namespace rushhour {

TEST(UnlimitedInputSchedule, RightSizeAndValues) {
  UnlimitedInputSchedule schedule(7);
  ASSERT_EQ(7, schedule.size());
  for (std::size_t i = 0; i < 7; i++) {
    EXPECT_EQ(0, schedule[i].count());
  }
}

TEST(UnlimitedInputSchedule, SizeZero) {
  UnlimitedInputSchedule schedule(0);
  ASSERT_EQ(0, schedule.size());
  EXPECT_THROW(schedule[0], std::out_of_range);
}

TEST(UnlimitedInputSchedule, OutOfBounds) {
  UnlimitedInputSchedule schedule(5);
  ASSERT_EQ(5, schedule.size());
  EXPECT_THROW(schedule[5], std::out_of_range);
}

}  // namespace rushhour
