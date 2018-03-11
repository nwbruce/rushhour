#include "rushhour_inputschedule.h"
#include <gmock/gmock.h>

namespace rushhour {

namespace {
struct DerivedInputSchedule : public InputSchedule {
  MOCK_CONST_METHOD0(size, std::size_t());
  MOCK_CONST_METHOD1(at, std::chrono::nanoseconds(std::size_t));
  std::chrono::nanoseconds operator[](std::size_t index) const override {
    return at(index);
  }
};
}  // namespace

TEST(InputSchedule, IteratorWorks) {
  using namespace ::testing;
  DerivedInputSchedule schedule;

  EXPECT_CALL(schedule, at(0)).WillOnce(Return(std::chrono::nanoseconds(32)));

  auto iter = schedule.begin();
  EXPECT_EQ(std::chrono::nanoseconds(32), *iter);
}

}  // namespace rushhour
