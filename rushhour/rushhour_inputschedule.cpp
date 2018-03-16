#include "rushhour_inputschedule.h"

namespace rushhour {

InputSchedule::Iterator::Iterator(const InputSchedule& input_schedule, std::size_t index)
: input_schedule_(input_schedule)
, index_(index)
{}

bool InputSchedule::Iterator::operator!=(const Iterator& rhs) const {
  return index_ != rhs.index_;
}

bool InputSchedule::Iterator::operator==(const Iterator& rhs) const {
  return index_ == rhs.index_;
}

InputSchedule::Iterator& InputSchedule::Iterator::operator++() {
  index_++;
  return *this;
}

InputSchedule::Iterator InputSchedule::Iterator::operator++(int) {
  Iterator temp(*this);
  operator++();
  return temp;
}

std::chrono::nanoseconds InputSchedule::Iterator::operator*() const {
  return input_schedule_[index_];
}

InputSchedule::Iterator InputSchedule::begin() const {
  return Iterator(*this, 0);
}

InputSchedule::Iterator InputSchedule::end() const {
  return Iterator(*this, size());
}

}  // namespace rushhour
