#include "rushhour_unlimitedinputschedule.h"
#include <stdexcept>

namespace rushhour {

UnlimitedInputSchedule::UnlimitedInputSchedule(std::size_t count) : count_(count) {}

std::size_t UnlimitedInputSchedule::size() const {
  return count_;
}

std::chrono::nanoseconds UnlimitedInputSchedule::operator[](std::size_t index) const {
  if (count_ == 0 || index >= count_) {
    throw std::out_of_range("index out of range");
  }
  return std::chrono::nanoseconds(0);
}

}  // namespace rushhour
