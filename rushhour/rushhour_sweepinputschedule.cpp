#include "rushhour_sweepinputschedule.h"
#include <stdexcept>
#include <limits>

namespace rushhour {

SweepInputSchedule::SweepInputSchedule(
    double starting_rate_per_second,
    double ending_rate_per_second,
    std::size_t count)
: start_rate_(starting_rate_per_second)
, end_rate_(ending_rate_per_second)
, count_(count) {}

std::size_t SweepInputSchedule::size() const {
  return count_;
}

std::chrono::nanoseconds SweepInputSchedule::operator[](std::size_t index) const {
  if (count_ == 0 || index >= count_) {
    throw std::out_of_range("index out of range");
  }
  double rate = 0.0;
  if (count_ == 1) {
    rate = start_rate_;
  } else {
    rate = index * (end_rate_ - start_rate_) / (count_ - 1) + start_rate_;
  }
  std::int64_t ns = 0;
  if (rate == 0.0) {
    ns = std::numeric_limits<int64_t>::max();
  } else {
    ns = static_cast<std::int64_t>(1.0e9 / rate);
  }
  return std::chrono::nanoseconds(ns);
}

}  // namespace rushhour
