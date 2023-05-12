#ifndef HEADER_WRAPPER
#define HEADER_WRAPPER

#include <string>

#include "my_package/obstacle_manager/obstacle_manager.h"
#include "my_package/target_manager/target_manager.h"

namespace my_package {
class Wrapper {
private:
  std::string name_{"Wrapper"};
  ObstacleManager obstacle_manager_;
  TargetManager target_manager_;

public:
  bool Plan() const;
};
} // namespace my_package

#endif /* HEADER_WRAPPER */
