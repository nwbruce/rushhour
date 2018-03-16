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


}  // namespace rushhour
