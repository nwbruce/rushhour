#ifndef RUSHHOUR_RUSHHOUR_TRIAL_TRACKINGCONTEXT_H_
#define RUSHHOUR_RUSHHOUR_TRIAL_TRACKINGCONTEXT_H_

#include "rushhour_trial_completionreport.h"
#include <cstdint>
#include <chrono>
#include <future>

namespace rushhour {
namespace trial {

class TrackingContext {
public:
  explicit TrackingContext(std::uint32_t index);

  CompletionReport* completion_report();

  void start();

  void wait();

  std::uint32_t index() const;
  bool succeeded() const;
  std::chrono::nanoseconds elapsed() const;

private:
  std::uint32_t index_;
  std::promise<CompletionReport::Result> promise_;
  std::future<CompletionReport::Result> future_;
  CompletionReport completion_report_;
  std::chrono::steady_clock::time_point started_;
  CompletionReport::Result completion_result_;
};

} /* namespace trial */
} /* namespace rushhour */

#endif /* RUSHHOUR_RUSHHOUR_TRIAL_TRACKINGCONTEXT_H_ */
