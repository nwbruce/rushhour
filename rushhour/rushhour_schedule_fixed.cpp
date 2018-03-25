#include "rushhour_schedule_fixed.h"
#include <stdexcept>

namespace rushhour {
namespace schedule {

Fixed::Fixed(
    double rate_per_second,
    std::size_t count)
: period_(static_cast<int64_t>(1.0e9 / rate_per_second))
, count_(count) {}

std::size_t Fixed::size() const {
  return count_;
}

std::chrono::nanoseconds Fixed::operator[](std::size_t index) const {
  if (count_ == 0 || index >= count_) {
    throw std::out_of_range("index out of range");
  }
  return std::chrono::nanoseconds(period_);
}

}  // namespace schedule
}  // namespace rushhour
