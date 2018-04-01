#ifndef RUSHHOUR_RUSHHOUR_TRIAL_TRIAL_H_
#define RUSHHOUR_RUSHHOUR_TRIAL_TRIAL_H_

#include "rushhour_trial_completionreport.h"
#include "rushhour_schedule_schedule.h"
#include "rushhour_results_result.h"
#include <chrono>
#include <functional>
#include <vector>

namespace rushhour {
namespace trial {

struct Trial {
  Trial() = delete;

  using PrepareFunction = std::function<void(std::uint32_t)>;
  using SendFunction = std::function<void(CompletionReport*)>;

  static std::vector<results::Result> run(
    const schedule::Schedule& input_schedule,
    SendFunction do_send,
    std::chrono::milliseconds completion_wait_timeout = 
        std::chrono::milliseconds(5000),
    std::size_t additional_threads = 0);

  static std::vector<results::Result> run(
    const schedule::Schedule& input_schedule,
    PrepareFunction do_prepare,
    SendFunction do_send,
    std::chrono::milliseconds completion_wait_timeout =
        std::chrono::milliseconds(5000),
    std::size_t additional_threads = 0);
};

}  // namespace trial
}  // namespace rushhour

#endif  // RUSHHOUR_RUSHHOUR_TRIAL_TRIAL_H_
