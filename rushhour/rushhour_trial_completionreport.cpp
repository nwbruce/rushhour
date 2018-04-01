#include <rushhour_trial_completionreport.h>

namespace rushhour {
namespace trial {

CompletionReport::CompletionReport(std::promise<Result>&& promise, std::uint32_t index)
: promise_(std::move(promise))
, index_(index) {}

void CompletionReport::succeeded() {
  auto now = std::chrono::steady_clock::now();
  promise_.set_value(Result(true, now));
}

void CompletionReport::failed() {
  auto now = std::chrono::steady_clock::now();
  promise_.set_value(Result(false, now));
}

std::uint32_t CompletionReport::index() const {
  return index_;
}

}  // namespace trial
}  // namespace rushhour
