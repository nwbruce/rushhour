#include <boost/test/unit_test.hpp>
#include <rushhour_schedule_schedule.h>

namespace rushhour {
namespace schedule {

namespace {
struct DerivedInputSchedule : public Schedule {
  std::vector<std::int64_t> data;
  std::size_t size() const override {
    return data.size();
  }
  std::chrono::nanoseconds operator[](std::size_t index) const override {
    return std::chrono::nanoseconds(data[index]);
  }
};
}  // namespace

BOOST_AUTO_TEST_CASE(Schedule_IteratorPreIncrementWorks) {
  DerivedInputSchedule schedule;
  schedule.data.push_back(11);
  schedule.data.push_back(22);
  schedule.data.push_back(33);

  Schedule::Iterator iter = schedule.begin();
  BOOST_CHECK(schedule.end() != iter);
  BOOST_CHECK_EQUAL(11, (*iter).count());
  ++iter;

  BOOST_CHECK(schedule.end() != iter);
  BOOST_CHECK_EQUAL(22, (*iter).count());
  ++iter;

  BOOST_CHECK(schedule.end() != iter);
  BOOST_CHECK_EQUAL(33, (*iter).count());
  ++iter;

  BOOST_CHECK(schedule.end() == iter);
}

BOOST_AUTO_TEST_CASE(Schedule_IteratorPostIncrementWorks) {
  DerivedInputSchedule schedule;
  schedule.data.push_back(11);
  schedule.data.push_back(22);
  schedule.data.push_back(33);

  Schedule::Iterator iter = schedule.begin();
  BOOST_CHECK(schedule.end() != iter);
  BOOST_CHECK_EQUAL(11, (*iter).count());
  iter++;

  BOOST_CHECK(schedule.end() != iter);
  BOOST_CHECK_EQUAL(22, (*iter).count());
  iter++;

  BOOST_CHECK(schedule.end() != iter);
  BOOST_CHECK_EQUAL(33, (*iter).count());
  iter++;

  BOOST_CHECK(schedule.end() == iter);
}

BOOST_AUTO_TEST_CASE(Schedule_IteratorWorksInForLoop) {
  DerivedInputSchedule schedule;
  schedule.data.push_back(11);
  schedule.data.push_back(22);
  schedule.data.push_back(33);

  std::vector<std::int64_t> actual;
  for (auto ns : schedule) {
    actual.push_back(ns.count());
  }

  BOOST_CHECK_EQUAL_COLLECTIONS(schedule.data.begin(), schedule.data.end(),
                                actual.begin(), actual.end());
}

}  // namespace schedule
}  // namespace rushhour
