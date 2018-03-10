#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace rushhour {

struct X {
  MOCK_METHOD1(f, void(int));
};

TEST(RushHour, TestLoads) {
  X x;
  EXPECT_CALL(x, f(3));
  x.f(3);
}

}
