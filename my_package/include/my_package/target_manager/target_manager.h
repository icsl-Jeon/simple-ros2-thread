#ifndef HEADER_TARGET_MANAGER
#define HEADER_TARGET_MANAGER
#include "my_package/obstacle_manager/obstacle_manager.h"
#include <Eigen/Core>
#include <string>

namespace my_package {

class TargetManager {
private:
  std::string name_{"TargetManager"};

public:
  std::string GetName() const;
  bool CheckCollision(const ObstacleManager &obstacle_manager) const;
};
} // namespace my_package

#endif /* HEADER_TARGET_MANAGER */
