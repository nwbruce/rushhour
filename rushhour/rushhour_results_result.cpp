#include "rushhour_results_result.h"

namespace rushhour {
namespace results {

Result::Result(const std::chrono::steady_clock::time_point& start,
               const std::chrono::steady_clock::time_point& end,
               bool succeeded)
: start_(start)
, end_(end)
, succeeded_(succeeded)
{}

std::chrono::nanoseconds Result::elapsed() const {
  return end_ - start_;
}

bool Result::succeeded() const {
  return succeeded_;
}

} /* namespace results */
} /* namespace rushhour */
