#include <boost/test/unit_test.hpp>
#include <rushhour_results_result.h>

namespace rushhour {
namespace results {

namespace {
std::chrono::steady_clock::time_point make_time_point(std::int64_t ms) {
  return std::chrono::steady_clock::time_point{std::chrono::milliseconds(ms)};
}
}

BOOST_AUTO_TEST_CASE(Summary_PrintsNicely) {
  std::vector<Result> results;
  results.emplace_back(make_time_point(12), make_time_point(114), true);
  results.emplace_back(make_time_point(18), make_time_point(122), true);
  results.emplace_back(make_time_point(30), make_time_point(131), true);
  results.emplace_back(make_time_point(38), make_time_point(122), true);
  results.emplace_back(make_time_point(53), make_time_point(152), true);
  results.emplace_back(make_time_point(58), make_time_point(177), true);
  results.emplace_back(make_time_point(73), make_time_point(192), true);
  results.emplace_back(make_time_point(81), make_time_point(195), true);
  results.emplace_back(make_time_point(87), make_time_point(192), true);
  results.emplace_back(make_time_point(97), make_time_point(217), true);
  results.emplace_back(make_time_point(111), make_time_point(188), true);
  results.emplace_back(make_time_point(118), make_time_point(220), true);
  results.emplace_back(make_time_point(128), make_time_point(250), true);
  results.emplace_back(make_time_point(138), make_time_point(248), true);
  results.emplace_back(make_time_point(153), make_time_point(273), true);
  results.emplace_back(make_time_point(157), make_time_point(252), true);
  results.emplace_back(make_time_point(167), make_time_point(250), true);
  results.emplace_back(make_time_point(183), make_time_point(302), true);
  results.emplace_back(make_time_point(191), make_time_point(270), true);
  results.emplace_back(make_time_point(203), make_time_point(314), true);
  results.emplace_back(make_time_point(211), make_time_point(323), true);
  results.emplace_back(make_time_point(218), make_time_point(316), true);
  results.emplace_back(make_time_point(231), make_time_point(340), true);
  results.emplace_back(make_time_point(237), make_time_point(323), true);
  results.emplace_back(make_time_point(249), make_time_point(345), true);
  results.emplace_back(make_time_point(261), make_time_point(381), true);
  results.emplace_back(make_time_point(272), make_time_point(374), true);
  results.emplace_back(make_time_point(281), make_time_point(400), true);
  results.emplace_back(make_time_point(289), make_time_point(391), true);
  results.emplace_back(make_time_point(297), make_time_point(394), true);
  results.emplace_back(make_time_point(312), make_time_point(409), true);
  results.emplace_back(make_time_point(321), make_time_point(427), true);
  results.emplace_back(make_time_point(331), make_time_point(440), true);
  results.emplace_back(make_time_point(342), make_time_point(419), true);
  results.emplace_back(make_time_point(351), make_time_point(473), true);
  results.emplace_back(make_time_point(362), make_time_point(472), true);
  results.emplace_back(make_time_point(370), make_time_point(492), true);
  results.emplace_back(make_time_point(381), make_time_point(483), true);
  results.emplace_back(make_time_point(392), make_time_point(496), true);
  results.emplace_back(make_time_point(401), make_time_point(490), true);
  results.emplace_back(make_time_point(412), make_time_point(490), true);
  results.emplace_back(make_time_point(420), make_time_point(512), true);
  results.emplace_back(make_time_point(430), make_time_point(528), true);
  results.emplace_back(make_time_point(440), make_time_point(540), true);
  results.emplace_back(make_time_point(453), make_time_point(548), true);
  results.emplace_back(make_time_point(459), make_time_point(537), true);
  results.emplace_back(make_time_point(473), make_time_point(552), true);
  results.emplace_back(make_time_point(482), make_time_point(562), true);
  results.emplace_back(make_time_point(487), make_time_point(588), true);
  results.emplace_back(make_time_point(500), make_time_point(581), true);
  results.emplace_back(make_time_point(513), make_time_point(624), true);
  results.emplace_back(make_time_point(522), make_time_point(620), true);
  results.emplace_back(make_time_point(527), make_time_point(637), true);
  results.emplace_back(make_time_point(537), make_time_point(623), true);
  results.emplace_back(make_time_point(547), make_time_point(632), true);
  results.emplace_back(make_time_point(561), make_time_point(669), true);
  results.emplace_back(make_time_point(571), make_time_point(675), true);
  results.emplace_back(make_time_point(577), make_time_point(652), true);
  results.emplace_back(make_time_point(588), make_time_point(670), true);
  results.emplace_back(make_time_point(603), make_time_point(678), true);
  results.emplace_back(make_time_point(608), make_time_point(715), true);
  results.emplace_back(make_time_point(622), make_time_point(712), true);
  results.emplace_back(make_time_point(628), make_time_point(716), true);
  results.emplace_back(make_time_point(641), make_time_point(745), true);
  results.emplace_back(make_time_point(648), make_time_point(725), true);
  results.emplace_back(make_time_point(657), make_time_point(740), true);
  results.emplace_back(make_time_point(669), make_time_point(762), true);
  results.emplace_back(make_time_point(679), make_time_point(773), true);
  results.emplace_back(make_time_point(693), make_time_point(808), true);
  results.emplace_back(make_time_point(701), make_time_point(790), true);
  results.emplace_back(make_time_point(711), make_time_point(803), true);
  results.emplace_back(make_time_point(718), make_time_point(832), true);
  results.emplace_back(make_time_point(728), make_time_point(806), true);
  results.emplace_back(make_time_point(740), make_time_point(855), true);
  results.emplace_back(make_time_point(750), make_time_point(846), true);
  results.emplace_back(make_time_point(759), make_time_point(882), true);
  results.emplace_back(make_time_point(769), make_time_point(851), true);
  results.emplace_back(make_time_point(777), make_time_point(863), true);
  results.emplace_back(make_time_point(791), make_time_point(887), true);
  results.emplace_back(make_time_point(797), make_time_point(906), true);
  results.emplace_back(make_time_point(813), make_time_point(911), true);
  results.emplace_back(make_time_point(820), make_time_point(923), true);
  results.emplace_back(make_time_point(829), make_time_point(917), true);
  results.emplace_back(make_time_point(841), make_time_point(919), true);
  results.emplace_back(make_time_point(852), make_time_point(950), true);
  results.emplace_back(make_time_point(863), make_time_point(938), true);
  results.emplace_back(make_time_point(872), make_time_point(949), true);
  results.emplace_back(make_time_point(877), make_time_point(997), true);
  results.emplace_back(make_time_point(892), make_time_point(977), true);
  results.emplace_back(make_time_point(898), make_time_point(1022), true);
  results.emplace_back(make_time_point(911), make_time_point(1010), true);
  results.emplace_back(make_time_point(920), make_time_point(995), true);
  results.emplace_back(make_time_point(931), make_time_point(1011), true);
  results.emplace_back(make_time_point(937), make_time_point(1017), true);
  results.emplace_back(make_time_point(947), make_time_point(1027), true);
  results.emplace_back(make_time_point(959), make_time_point(1080), true);
  results.emplace_back(make_time_point(973), make_time_point(1063), true);
  results.emplace_back(make_time_point(979), make_time_point(1062), true);
  results.emplace_back(make_time_point(987), make_time_point(1065), true);
  results.emplace_back(make_time_point(1002), make_time_point(1085), true);
}

}  // namespace results
}  // namespace rushhour
