#include <boost/test/unit_test.hpp>
#include "rushhour_results_stats.h"

namespace rushhour {
namespace results {

BOOST_AUTO_TEST_CASE(Stats_ComputedCorrectly) {
  Stats stats;
  stats << 4.5 << 92.9 << 50.0 << 55.5 << 7.7 << 83.9
        << 0.4 << 74.0 << 77.4 << 50.3 << 76.4 << 16.9
        << 15.0 << 34.8 << 97.4 << 67.6 << 4.1 << 59.9
        << 58.1 << 47.6 << 46.4 << 69.3 << 89.2 << 33.1
        << 36.8 << 66.4 << 19.9 << 11.4 << 11.3 << 4.0
        << 75.3 << 86.0 << 12.8 << 64.4 << 61.1 << 21.8
        << 27.4 << 3.5 << 3.1 << 71.5;

  BOOST_CHECK_CLOSE(44.7, stats.average(), 0.5);
  BOOST_CHECK_CLOSE(30.0, stats.stdev(), 0.5);
  BOOST_CHECK_EQUAL(40, stats.count());
  BOOST_CHECK_EQUAL(97.4, stats.max());
  BOOST_CHECK_EQUAL(0.4, stats.min());
  BOOST_CHECK_CLOSE(95.6, stats.percentile(0.99), 0.2);
  BOOST_CHECK_CLOSE(89.3, stats.percentile(0.95), 0.2);
}

}  // namespace results
}  // namespace rushhour
