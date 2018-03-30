#include "rushhour_trial_trackingcontext.h"

namespace rushhour {
namespace trial {

TrackingContext::TrackingContext(std::uint32_t index)
: index_(index)
, promise_()
, future_(promise_.get_future())
, completion_report_(std::move(promise_), index_) {}

CompletionReport* TrackingContext::completion_report() {
  return &completion_report_;
}

void TrackingContext::start() {
  started_ = std::chrono::steady_clock::now();
}

void TrackingContext::wait() {
  completion_result_ = future_.get();
}

std::uint32_t TrackingContext::index() const {
  return index_;
}

bool TrackingContext::succeeded() const {
  return completion_result_.first;
}

std::chrono::nanoseconds TrackingContext::elapsed() const {
  return completion_result_.second - started_;
}

} /* namespace trial */
} /* namespace rushhour */
