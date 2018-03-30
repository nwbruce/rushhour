#ifndef RUSHHOUR_RUSHHOUR_TRIAL_TRACKINGCONTEXT_H_
#define RUSHHOUR_RUSHHOUR_TRIAL_TRACKINGCONTEXT_H_

#include "rushhour_trial_completionreport.h"
#include "rushhour_results_result.h"
#include <cstdint>
#include <chrono>
#include <future>

namespace rushhour {
namespace trial {

class TrackingContext {
public:
  TrackingContext(std::uint32_t index);

  CompletionReport* completion_report();

  void start();

  results::Result get_result(const std::chrono::steady_clock::time_point& timeout_time);

private:
  std::promise<CompletionReport::Result> promise_;
  std::future<CompletionReport::Result> future_;
  CompletionReport completion_report_;
  std::chrono::steady_clock::time_point started_;
};

} /* namespace trial */
} /* namespace rushhour */

#endif /* RUSHHOUR_RUSHHOUR_TRIAL_TRACKINGCONTEXT_H_ */
