#include "rushhour_results_stats.h"
#include <algorithm>
#include <cmath>
#include <limits>

namespace rushhour {
namespace results {

Stats::Stats()
    : sum_{0.0},
      min_{std::numeric_limits<double>::max()},
      max_{std::numeric_limits<double>::min()},
      data_unsorted_{false} {}

Stats& Stats::operator<<(double value) {
  data_.push_back(value);
  data_unsorted_ = true;
  sum_ += value;
  if (value < min_) {
    min_ = value;
  }
  if (value > max_) {
    max_ = value;
  }
  return *this;
}

std::size_t Stats::count() const { return data_.size(); }

double Stats::average() const {
  if (count() == 0) {
    return sum_;
  } else {
    return sum_ / count();
  }
}

double Stats::min() const {
  if (count() == 0) {
    return 0.0;
  } else {
    return min_;
  }
}

double Stats::max() const {
  if (count() == 0) {
    return 0.0;
  } else {
    return max_;
  }
}

double Stats::stdev() const {
  if (count() == 0) {
    return 0.0;
  } else {
    double variance = 0.0;
    double avg = average();
    for (auto& value : data_) {
      double diff = value - avg;
      variance += diff * diff;
    }
    variance /= count();
    return std::sqrt(variance);
  }
}

double Stats::percentile(double p) const {
  if (count() < 2) {
    return 0.0;
  }
  if (data_unsorted_) {
    std::sort(data_.begin(), data_.end());
    data_unsorted_ = false;
  }
  double rank = p * count();
  double rank_i = 0.0;
  double rank_f = std::modf(rank, &rank_i);
  std::size_t index = static_cast<std::size_t>(rank_i) - 1;
  if (index + 1 >= count()) {
    return data_[index];
  } else {
    return (data_[index + 1] - data_[index]) * rank_f + data_[index];
  }
}

}  // namespace results
}  // namespace rushhour
