#ifndef RUSHHOUR_RUSHHOUR_RESULTS_RANGEGROUP_H_
#define RUSHHOUR_RUSHHOUR_RESULTS_RANGEGROUP_H_

#include <cstdint>
#include <stdexcept>

namespace rushhour {
namespace results {

template <typename T>
class RangeGroup {
public:
  RangeGroup(std::size_t group_count,
             double min_value,
             double max_value)
  : min_value_(min_value)
  , max_value_(max_value)
  , groups_(group_count) {}

  T& operator[](std::size_t index) {
    return groups_[index];
  }

  T& at(double value) {
    return groups_[get_index(value)];
  }

  std::size_t size() const {
    return groups_.size();
  }

  double lower_bound(std::size_t index) const {
    return min_value_ + (max_value_ - min_value_) * index / groups_.size();
  }

private:
  double min_value_;
  double max_value_;
  std::vector<T> groups_;

  std::size_t get_index(double value) {
    double range = max_value_ - min_value_;
    double index = (value - min_value_) / range * groups_.size();
    if (index < 0) {
      throw std::out_of_range("value not above min");
    }
    return static_cast<std::size_t>(index);
  }
};

}  // namespace results
}  // namespace rushhour

#endif  // RUSHHOUR_RUSHHOUR_RESULTS_RANGEGROUP_H_