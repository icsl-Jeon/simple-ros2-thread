#include "my_package/target_manager/target_manager.h"
#include "gtest/gtest.h"
#include <Eigen/Core>

namespace my_package {

TEST(TargetTest, NameShouldCorrect) {

  ObstacleManager obstacle_manager;
  EXPECT_EQ(obstacle_manager.GetName(), "ObstacleManager");

  TargetManager target_manager;
  EXPECT_EQ(target_manager.CheckCollision(obstacle_manager), true);
}

} // namespace my_package