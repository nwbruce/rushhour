#ifndef RUSHHOUR_RUSHHOUR_RESULTS_SERIESGENERATOR_H_
#define RUSHHOUR_RUSHHOUR_RESULTS_SERIESGENERATOR_H_

#include <rushhour_results_result.h>
#include <cstdint>
#include <vector>

namespace rushhour {
namespace results {

class SeriesGenerator {
public:
  explicit SeriesGenerator(const std::vector<Result>& results);

  void latency_vs_time(std::size_t bucket_count);

private:
  const std::vector<Result>& results_;
};

}  // namespace results
}  // namespace rushhour

#endif  // RUSHHOUR_RUSHHOUR_RESULTS_SERIESGENERATOR_H_