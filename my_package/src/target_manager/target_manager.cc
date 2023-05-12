#include "my_package/target_manager/target_manager.h"

bool my_package::TargetManager::CheckCollision(
    const ObstacleManager &obstacle_manager) const {
  return obstacle_manager.GetName() == "ObstacleManager";
}
std::string my_package::TargetManager::GetName() const { return name_; }