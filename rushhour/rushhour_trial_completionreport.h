#ifndef RUSHHOUR_RUSHHOUR_TRIAL_COMPLETIONREPORT_H_
#define RUSHHOUR_RUSHHOUR_TRIAL_COMPLETIONREPORT_H_

#include <chrono>
#include <cstdint>
#include <future>
#include <utility>

namespace rushhour {
namespace trial {

class CompletionReport {
public:
  void succeeded();
  void failed();

  std::uint32_t index() const;

  using Result = std::pair<bool, std::chrono::steady_clock::time_point>;
  explicit CompletionReport(std::promise<Result>&& promise, std::uint32_t index);

private:
  std::promise<Result> promise_;
  std::uint32_t index_;
};

}  // namespace trial
}  // namespace rushhour

#endif  // RUSHHOUR_RUSHHOUR_TRIAL_COMPLETIONREPORT_H_
