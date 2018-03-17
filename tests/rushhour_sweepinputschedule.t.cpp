#include "rushhour_sweepinputschedule.h"
#include <gtest/gtest.h>

namespace rushhour {

TEST(SweepInputSchedule, IncreasingSweep) {
  SweepInputSchedule schedule(2.0, 5.0, 100);
  ASSERT_EQ(100, schedule.size());

  EXPECT_DOUBLE_EQ(1.0e9 / 2.0, static_cast<double>(schedule[0].count()));
  auto last = std::chrono::nanoseconds::max();
  for (auto ns : schedule) {
    EXPECT_LE(ns, last);
    last = ns;
  }
  EXPECT_DOUBLE_EQ(1.0e9 / 5.0, static_cast<double>(schedule[schedule.size()-1].count()));
}

TEST(SweepInputSchedule, DecreasingSweep) {
  SweepInputSchedule schedule(5.0, 2.0, 100);
  ASSERT_EQ(100, schedule.size());

  EXPECT_DOUBLE_EQ(1.0e9 / 5.0, static_cast<double>(schedule[0].count()));
  auto last = std::chrono::nanoseconds::min();
  for (auto ns : schedule) {
    EXPECT_GE(ns, last);
    last = ns;
  }
  EXPECT_DOUBLE_EQ(1.0e9 / 2.0, static_cast<double>(schedule[schedule.size()-1].count()));
}

TEST(SweepInputSchedule, FlatSweep) {
  SweepInputSchedule schedule(75.0, 75.0, 10);
  ASSERT_EQ(10, schedule.size());
  for (auto ns : schedule) {
    EXPECT_NEAR(1.0e9 / 75.0, static_cast<double>(ns.count()), 1.0);
  }
}

TEST(SweepInputSchedule, SizeOfOne) {
  SweepInputSchedule schedule(75.0, 105.0, 1);
  ASSERT_EQ(1, schedule.size());
  EXPECT_NEAR(1.0e9 / 75.0, static_cast<double>(schedule[0].count()), 1.0);
}

TEST(SweepInputSchedule, SizeZero) {
  SweepInputSchedule schedule(75.0, 105.0, 0);
  ASSERT_EQ(0, schedule.size());
  EXPECT_THROW(schedule[0], std::out_of_range);
}

TEST(SweepInputSchedule, OutOfBounds) {
  SweepInputSchedule schedule(75.0, 105.0, 5);
  ASSERT_EQ(5, schedule.size());
  EXPECT_THROW(schedule[5], std::out_of_range);
}

}  // namespace rushhour
