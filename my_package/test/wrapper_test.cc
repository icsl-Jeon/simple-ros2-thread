#include "my_package/wrapper/wrapper.h"
#include "gtest/gtest.h"
#include <Eigen/Core>

namespace my_package {

TEST(WrapperTest, NameShouldCorrect) {
  printf("testing wrapper..\n");
  Wrapper wrapper;
  EXPECT_TRUE(wrapper.Plan());
}

} // namespace my_package