#ifndef RUSHHOUR_RUSHHOUR_RESULTS_SUMMARY_H_
#define RUSHHOUR_RUSHHOUR_RESULTS_SUMMARY_H_

#include "rushhour_results_result.h"
#include "rushhour_results_stats.h"
#include <ostream>
#include <vector>

namespace rushhour {
namespace results {

class Summary {
public:
  explicit Summary(const std::vector<Result>& results);

  friend std::ostream& operator<<(std::ostream&, const Summary&);

private:
  Stats latency_ms_stats_;
  double input_rate_;
  double throughput_;
  std::size_t count_;

  static double get_rate(const std::chrono::steady_clock::time_point& begin,
                         const std::chrono::steady_clock::time_point& end,
                         std::size_t count);
};

std::ostream& operator<<(std::ostream&, const Summary&);

}  // namespace results
}  // namespace rushhour

#endif  // RUSHHOUR_RUSHHOUR_RESULTS_SUMMARY_H_
