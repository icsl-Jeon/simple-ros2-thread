#include "my_package_ros2/server/server.h"

using namespace my_package;
bool LosServer::Update() { return wrapper_.Plan(); }
void LosServer::TimerCallback() {
  if (Update()) {
    RCLCPP_INFO(this->get_logger(), "Update success by server");
  }
}
LosServer::LosServer() : Node("server_node") {
  timer_ =
      this->create_wall_timer(1s, std::bind(&LosServer::TimerCallback, this));
  robot_position_ = Eigen::Vector3d::Zero();
}
