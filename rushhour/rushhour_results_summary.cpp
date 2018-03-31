#include "rushhour_results_summary.h"

namespace rushhour {
namespace results {

Summary::Summary(const std::vector<Result>& results) {
  auto first_send_time = std::chrono::steady_clock::time_point::max();
  auto last_send_time = std::chrono::steady_clock::time_point::min();
  auto last_receive_time = std::chrono::steady_clock::time_point::min();
  count_ = 0;
  for (auto& result : results) {
    if (!result.succeeded()) {
      continue;
    }
    latency_ms_stats_ << (result.elapsed().count() / 1.0e6);

    if (result.started() < first_send_time) {
      first_send_time = result.started();
    }
    if (result.started() > last_send_time) {
      last_send_time = result.started();
    }
    if (result.ended() > last_receive_time) {
      last_receive_time = result.ended();
    }
    count_++;
  }
  input_rate_ = get_rate(first_send_time, last_send_time, count_);
  throughput_ = get_rate(first_send_time, last_receive_time, count_);
}

double Summary::get_rate(const std::chrono::steady_clock::time_point& begin,
                         const std::chrono::steady_clock::time_point& end,
                         std::size_t count) {
  double rate = 0.0;
  std::chrono::nanoseconds ns = end - begin;
  if (ns.count() > 0) {
    rate = 1.0e9 * count / ns.count();
  }
  return rate;
}

std::ostream& operator<<(std::ostream& os, const Summary& summary) {
  os << "Count: " << summary.count_ << std::endl;
  os << "Input rate: " << summary.input_rate_ << " /s" << std::endl;
  os << "Throughput: " << summary.throughput_ << " /s" << std::endl;
  os << "95% latency: " << summary.latency_ms_stats_.percentile(0.95) << " ms" << std::endl;
  return os;
}

} /* namespace results */
} /* namespace rushhour */
