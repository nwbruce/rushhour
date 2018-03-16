#include "rushhour_unlimitedinputschedule.h"

namespace rushhour {

UnlimitedInputSchedule::UnlimitedInputSchedule(std::size_t count) : count_(count) {}

std::size_t UnlimitedInputSchedule::size() const {
  return count_;
}

std::chrono::nanoseconds UnlimitedInputSchedule::operator[](std::size_t index) const {
  return std::chrono::nanoseconds(0);
}

}  // namespace rushhour
