#include "my_package/obstacle_manager/obstacle_manager.h"
#include "gtest/gtest.h"

namespace my_package {

TEST(ObstacleTest, NameShouldCorrect) {

  ObstacleManager obstacle_manager;
  EXPECT_EQ(obstacle_manager.GetName(), "ObstacleManager");
}

} // namespace my_package