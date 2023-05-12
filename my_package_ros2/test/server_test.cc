#include "my_package/obstacle_manager/obstacle_manager.h"
#include "my_package_ros2/server/server.h"
#include "gtest/gtest.h"
#include <Eigen/Core>

namespace my_package {

TEST(LosServerTest, IsObstacleManagerIncludedAutomatically) {

  ObstacleManager obstacle_manager;
  EXPECT_EQ(obstacle_manager.GetName(), "ObstacleManager");
}

} // namespace my_package