#include <boost/test/unit_test.hpp>
#include <rushhour_results_rangegroup.h>

namespace rushhour {
namespace results {

BOOST_AUTO_TEST_CASE(RangeGroup_BucketsResults) {
  RangeGroup<std::string> range_group(20, 10.0, 90.0);
  BOOST_CHECK_EQUAL(20, range_group.size());
  BOOST_CHECK_CLOSE(range_group.lower_bound(0), 10.0, 0.1);
  BOOST_CHECK_CLOSE(range_group.lower_bound(20), 90.0, 0.1);

  for (std::size_t i = 0; i < range_group.size(); i++) {
    range_group[i] = "bucket-" + std::to_string(i);
  }

  // 10, 14, 18, 22, 26, 30, 34, 38, 42, 46
  // 50, 54, 58, 62, 66, 70, 74, 78, 82, 86, 90
  BOOST_CHECK_EQUAL("bucket-0", range_group.at(11.0));
  BOOST_CHECK_EQUAL("bucket-0", range_group.at(12.5));
  BOOST_CHECK_EQUAL("bucket-3", range_group.at(22.7));
  BOOST_CHECK_EQUAL("bucket-19", range_group.at(89.9));
}

}  // namespace results
}  // namespace rushhour
