#include "rushhour_inputschedule.h"
#include <gtest/gtest.h>

namespace rushhour {

namespace {
struct DerivedInputSchedule : public InputSchedule {
  std::vector<std::int64_t> data;
  std::size_t size() const override {
    return data.size();
  }
  std::chrono::nanoseconds operator[](std::size_t index) const override {
    return std::chrono::nanoseconds(data[index]);
  }
};
}  // namespace

TEST(InputSchedule, IteratorPreIncrementWorks) {
  using namespace ::testing;
  DerivedInputSchedule schedule;
  schedule.data.push_back(11);
  schedule.data.push_back(22);
  schedule.data.push_back(33);

  InputSchedule::Iterator iter = schedule.begin();
  EXPECT_NE(schedule.end(), iter);
  EXPECT_EQ(std::chrono::nanoseconds(11), *iter);
  ++iter;

  EXPECT_NE(schedule.end(), iter);
  EXPECT_EQ(std::chrono::nanoseconds(22), *iter);
  ++iter;

  EXPECT_NE(schedule.end(), iter);
  EXPECT_EQ(std::chrono::nanoseconds(33), *iter);
  ++iter;

  EXPECT_EQ(schedule.end(), iter);
}

TEST(InputSchedule, IteratorPostIncrementWorks) {
  using namespace ::testing;
  DerivedInputSchedule schedule;
  schedule.data.push_back(11);
  schedule.data.push_back(22);
  schedule.data.push_back(33);

  InputSchedule::Iterator iter = schedule.begin();
  EXPECT_NE(schedule.end(), iter);
  EXPECT_EQ(std::chrono::nanoseconds(11), *iter);
  iter++;

  EXPECT_NE(schedule.end(), iter);
  EXPECT_EQ(std::chrono::nanoseconds(22), *iter);
  iter++;

  EXPECT_NE(schedule.end(), iter);
  EXPECT_EQ(std::chrono::nanoseconds(33), *iter);
  iter++;

  EXPECT_EQ(schedule.end(), iter);
}

TEST(InputSchedule, IteratorWorksInForLoop) {
  using namespace ::testing;
  DerivedInputSchedule schedule;
  schedule.data.push_back(11);
  schedule.data.push_back(22);
  schedule.data.push_back(33);

  std::vector<std::int64_t> actual;
  for (auto ns : schedule) {
    actual.push_back(ns.count());
  }

  EXPECT_EQ(schedule.data, actual);
}


}  // namespace rushhour
