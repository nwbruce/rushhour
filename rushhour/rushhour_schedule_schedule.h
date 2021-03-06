#ifndef RUSHHOUR_INPUTSCHEDULE_H_
#define RUSHHOUR_INPUTSCHEDULE_H_

#include <chrono>
#include <cstdint>

namespace rushhour {
namespace schedule {

class Schedule {
public:
  virtual ~Schedule() = default;
  virtual std::size_t size() const = 0;
  virtual std::chrono::nanoseconds operator[](std::size_t index) const = 0;

  struct Iterator {
    Iterator(const Schedule& input_schedule, std::size_t index);
    bool operator!=(const Iterator& rhs) const;
    bool operator==(const Iterator& rhs) const;
    Iterator& operator++();
    Iterator operator++(int);
    std::chrono::nanoseconds operator*() const;
  private:
    const Schedule& input_schedule_;
    std::size_t index_;
  };

  Iterator begin() const;
  Iterator end() const;
};

}  // namespace schedule
}  // namespace rushhour

#endif  // RUSHHOUR_INPUTSCHEDULE_H_
