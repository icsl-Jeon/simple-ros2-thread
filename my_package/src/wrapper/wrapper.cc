#include "my_package/wrapper/wrapper.h"

bool my_package::Wrapper::Plan() const {
  return target_manager_.GetName() == "TargetManager" &&
         obstacle_manager_.GetName() == "ObstacleManager";
}
