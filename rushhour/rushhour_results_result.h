#ifndef RUSHHOUR_RUSHHOUR_RESULTS_RESULT_H_
#define RUSHHOUR_RUSHHOUR_RESULTS_RESULT_H_

#include <chrono>

namespace rushhour {
namespace results {

class Result {
public:
  Result(const std::chrono::steady_clock::time_point& start,
         const std::chrono::steady_clock::time_point& end,
         bool succeeded);

  std::chrono::nanoseconds elapsed() const;
  bool succeeded() const;

private:
  std::chrono::steady_clock::time_point start_;
  std::chrono::steady_clock::time_point end_;
  bool succeeded_;
};

} /* namespace results */
} /* namespace rushhour */

#endif /* RUSHHOUR_RUSHHOUR_RESULTS_RESULT_H_ */
