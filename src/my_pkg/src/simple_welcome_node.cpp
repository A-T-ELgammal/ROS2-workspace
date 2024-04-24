#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node("welcome_node")
    {
        int counter = 0;
        while (rclcpp::ok())
        {
            std::stringstream ss;
            ss << "Hello World :: " << counter;
            // std::string result = ss.str();
            std::string stream = ss.str();
            // const char *message = stream.c_str();
            RCLCPP_INFO(this->get_logger(), stream.c_str());
            rclcpp::sleep_for(std::chrono::nanoseconds(1000000000));
            counter++;
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyNode>());
    rclcpp::shutdown();
    return 0;
}