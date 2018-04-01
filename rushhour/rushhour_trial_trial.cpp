#include <rushhour_trial_trial.h>
#include <rushhour_trial_trackingcontext.h>
#include <chrono>
#include <future>
#include <thread>
#include <vector>

#include <sstream>
#include <iostream>
#define LOG_IT {\
                 std::ostringstream oss; \
                 oss << std::this_thread::get_id() << ": " << __LINE__ << std::endl; \
                 std::cerr << oss.str(); \
               }

namespace rushhour {
namespace trial {

namespace {

void empty_do_prepare(std::uint32_t) {}

void run_one(const schedule::Schedule& input_schedule,
             std::size_t total_threads,
             std::size_t thread_index,
             std::shared_future<std::chrono::steady_clock::time_point>& begin_time_future,
             Trial::PrepareFunction& do_prepare,
             Trial::SendFunction& do_send,
             std::vector<TrackingContext>& tracking_contexts) {
  std::size_t i = 0;
  auto target_time = begin_time_future.get();

  for (const auto& time_delta : input_schedule) {
    target_time += time_delta;

    if (i % total_threads == thread_index) {
      do_prepare(i);

      std::this_thread::sleep_until(target_time);

      auto completion_report = tracking_contexts[i].completion_report();
      tracking_contexts[i].start();
      do_send(completion_report);
    }

    i++;
  }
}

}  // namespace

std::vector<results::Result> Trial::run(const schedule::Schedule& input_schedule,
                                        SendFunction do_send,
                                        std::chrono::milliseconds completion_wait_timeout,
                                        std::size_t additional_threads) {
  return run(input_schedule, &empty_do_prepare, do_send, completion_wait_timeout, additional_threads);
}

std::vector<results::Result> Trial::run(const schedule::Schedule& input_schedule,
                                        PrepareFunction do_prepare,
                                        SendFunction do_send,
                                        std::chrono::milliseconds completion_wait_timeout,
                                        std::size_t additional_threads) {
  std::vector<TrackingContext> tracking_contexts;
  tracking_contexts.reserve(input_schedule.size());
  for (std::size_t i = 0; i < input_schedule.size(); ++i) {
    tracking_contexts.emplace_back(i);
  }

  std::vector<std::thread> threads;
  std::promise<std::chrono::steady_clock::time_point> begin_time_promise;
  std::shared_future<std::chrono::steady_clock::time_point> begin_time_future(begin_time_promise.get_future());

  for (std::size_t t = 1; t <= additional_threads; ++t) {
    threads.emplace_back([&](){
      run_one(input_schedule, additional_threads + 1, t, begin_time_future, do_prepare, do_send, tracking_contexts);
    });
  }

  begin_time_promise.set_value(std::chrono::steady_clock::now());
  run_one(input_schedule, additional_threads + 1, 0, begin_time_future, do_prepare, do_send, tracking_contexts);

  for (auto& thr : threads) {
    thr.join();
  }

  auto timeout_time = std::chrono::steady_clock::now() + completion_wait_timeout;

  std::vector<results::Result> results;
  results.reserve(tracking_contexts.size());
  for (auto& track_ctx : tracking_contexts) {
    auto result = track_ctx.get_result(timeout_time);
    results.emplace_back(result);
  }

  return results;
}

}  // namespace trial
}  // namespace rushhour
