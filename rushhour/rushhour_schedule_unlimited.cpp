#include <stdexcept>
#include "rushhour_schedule_unlimited.h"

namespace rushhour {
namespace schedule {

Unlimited::Unlimited(std::size_t count) : count_(count) {}

std::size_t Unlimited::size() const {
  return count_;
}

std::chrono::nanoseconds Unlimited::operator[](std::size_t index) const {
  if (count_ == 0 || index >= count_) {
    throw std::out_of_range("index out of range");
  }
  return std::chrono::nanoseconds(0);
}

}  // namespace schedule
}  // namespace rushhour
