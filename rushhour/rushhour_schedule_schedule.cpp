#include "rushhour_schedule_schedule.h"

namespace rushhour {
namespace schedule {

Schedule::Iterator::Iterator(const Schedule& input_schedule, std::size_t index)
: input_schedule_(input_schedule)
, index_(index)
{}

bool Schedule::Iterator::operator!=(const Iterator& rhs) const {
  return index_ != rhs.index_;
}

bool Schedule::Iterator::operator==(const Iterator& rhs) const {
  return index_ == rhs.index_;
}

Schedule::Iterator& Schedule::Iterator::operator++() {
  index_++;
  return *this;
}

Schedule::Iterator Schedule::Iterator::operator++(int) {
  Iterator temp(*this);
  operator++();
  return temp;
}

std::chrono::nanoseconds Schedule::Iterator::operator*() const {
  return input_schedule_[index_];
}

Schedule::Iterator Schedule::begin() const {
  return Iterator(*this, 0);
}

Schedule::Iterator Schedule::end() const {
  return Iterator(*this, size());
}

}  // namespace schedule
}  // namespace rushhour
