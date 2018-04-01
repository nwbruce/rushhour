#ifndef TESTS_RUSHHOUR_TESTS_STEADYCLOCKRANGE_H_
#define TESTS_RUSHHOUR_TESTS_STEADYCLOCKRANGE_H_

#include <chrono>

namespace rushhour {
namespace tests {

struct SteadyClockRange {
  inline void begin() {
    begin_ = std::chrono::steady_clock::now();
  }

  inline void end() {
    end_ = std::chrono::steady_clock::now();
  }

  inline bool contains(const std::chrono::steady_clock::time_point& time_point) const {
    return begin_ <= time_point && time_point <= end_;
  }

  inline std::chrono::nanoseconds duration() const {
    return end_ - begin_;
  }

  inline std::chrono::steady_clock::time_point begin_time() const {
    return begin_;
  }

  inline std::chrono::steady_clock::time_point end_time() const {
    return end_;
  }

private:
  std::chrono::steady_clock::time_point begin_;
  std::chrono::steady_clock::time_point end_;
};

}  // namespace tests
}  // namespace rushhour

#endif  // TESTS_RUSHHOUR_TESTS_STEADYCLOCKRANGE_H_
