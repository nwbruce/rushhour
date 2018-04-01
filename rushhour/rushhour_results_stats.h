#ifndef RUSHHOUR_RUSHHOUR_RESULTS_STATS_H_
#define RUSHHOUR_RUSHHOUR_RESULTS_STATS_H_

#include <cstdint>
#include <vector>

namespace rushhour {
namespace results {

class Stats {
public:
  Stats();

  Stats& operator<<(double value);
  std::size_t count() const;
  double average() const;
  double min() const;
  double max() const;
  double stdev() const;
  double percentile(double k) const;

private:
  double sum_;
  double min_;
  double max_;
  mutable std::vector<double> data_;
  mutable bool data_unsorted_;
};

}  // namespace results
}  // namespace rushhour

#endif  // RUSHHOUR_RUSHHOUR_RESULTS_STATS_H_
