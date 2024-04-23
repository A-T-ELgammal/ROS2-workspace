#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::Node::SharedPtr node = std::make_shared<rclcpp::Node>("welcome_node");
    int counter = 1;

    while (rclcpp::ok())
    {
        RCLCPP_INFO(node->get_logger(), "Hello world");
        rclcpp::sleep_for(std::chrono::nanoseconds(1000000000));
        counter++;
    }
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
