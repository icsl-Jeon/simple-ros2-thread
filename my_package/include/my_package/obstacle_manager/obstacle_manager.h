#ifndef HEADER_OBSTACLE_MANAGER
#define HEADER_OBSTACLE_MANAGER
#include <Eigen/Core>
#include <Eigen/Geometry>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace my_package {
class ObstacleManager {
private:
  pcl::PointCloud<pcl::PointXYZ> cloud_;
  Eigen::Affine3d pose_;
  std::string name_{"ObstacleManager"};

public:
  std::string GetName() const;
};
} // namespace my_package
#endif /* HEADER_OBSTACLE_MANAGER */
