#include "my_package_ros2/server/server.h"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<my_package::LosServer>());

  rclcpp::shutdown();
  return 0;
}