#include <rushhour_results_seriesgenerator.h>
#include <rushhour_results_rangegroup.h>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <stdexcept>

namespace rushhour {
namespace results {

SeriesGenerator::SeriesGenerator(const std::vector<Result>& results)
: results_(results) {}

void SeriesGenerator::latency_vs_time(std::size_t bucket_count) {
  if (bucket_count == 0) {
    throw std::out_of_range("invalid number of buckets");
  }

  using accumulator_t = boost::accumulators::accumulator_set<double, 
    boost::accumulators::stats<boost::accumulators::tag::mean>>;

  // find min/max times
  double min = std::numeric_limits<double>::max();
  double max = std::numeric_limits<double>::min();
  for (auto& r : results_) {
    double value = r.started().time_since_epoch().count();
    if (value < min) {
      min = value;
    }
    if (value > max) { 
      max = value;
    }
  }

  RangeGroup<accumulator_t> buckets(bucket_count, min, max);

  for (auto& r : results_) {
    double index = r.started().time_since_epoch().count();
    buckets.at(index)(r.elapsed().count());
  }

  
}

}  // namespace results
}  // namespace rushhour