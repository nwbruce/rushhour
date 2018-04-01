#include <rushhour_trial_trackingcontext.h>

namespace rushhour {
namespace trial {

TrackingContext::TrackingContext(std::uint32_t index)
: promise_()
, future_(promise_.get_future())
, completion_report_(std::move(promise_), index) {}

CompletionReport* TrackingContext::completion_report() {
  return &completion_report_;
}

void TrackingContext::start() {
  started_ = std::chrono::steady_clock::now();
}

results::Result TrackingContext::get_result(const std::chrono::steady_clock::time_point& timeout_time) {
  auto status = future_.wait_until(timeout_time);
  if (status == std::future_status::ready) {
    CompletionReport::Result completion_result = future_.get();
    return results::Result(started_, completion_result.second, completion_result.first);
  } else {
    return results::Result(started_, std::chrono::steady_clock::now(), false);
  }
}

}  // namespace trial
}  // namespace rushhour
