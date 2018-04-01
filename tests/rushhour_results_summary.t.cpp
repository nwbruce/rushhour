#include <boost/test/unit_test.hpp>
#include <rushhour_results_summary.h>
#include <iostream>

namespace rushhour {
namespace results {

namespace {
std::chrono::steady_clock::time_point make_time_point(std::int64_t ms) {
  return std::chrono::steady_clock::time_point{std::chrono::milliseconds(ms)};
}
}

BOOST_AUTO_TEST_CASE(Summary_PrintsNicely) {
  std::vector<Result> results;
  
  results.emplace_back(make_time_point(250), make_time_point(500), true);
  results.emplace_back(make_time_point(255), make_time_point(505), true);
  results.emplace_back(make_time_point(260), make_time_point(515), true);

  Summary summary(results);
  std::cout << summary;
}

}  // namespace results
}  // namespace rushhour
