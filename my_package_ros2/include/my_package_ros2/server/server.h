#ifndef HEADER_SERVER
#define HEADER_SERVER
#include "Eigen/Core"
#include "my_package/wrapper/wrapper.h"
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
using namespace std::chrono_literals;

namespace my_package {
class LosServer : public rclcpp::Node {
private:
  Wrapper wrapper_;
  Eigen::Vector3d robot_position_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;

public:
  LosServer();
  bool Update();
  void TimerCallback();
};

} // namespace my_package
#endif /* HEADER_SERVER */
