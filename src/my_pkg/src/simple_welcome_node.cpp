#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
public:
    // using loop with
    // MyNode() : Node("welcome_node")
    // {
    //     int counter = 0;
    //     while (rclcpp::ok())
    //     {
    //         std::stringstream ss;
    //         ss << "Hello World :: " << counter;
    //         std::string message = ss.str();
    //         RCLCPP_INFO(this->get_logger(), message.c_str());
    //         //with sleep_for
    //         rclcpp::sleep_for(std::chrono::seconds(1));

    //         counter++;
    //     }
    // }
    // using timer
    MyNode() : Node("welcome_node")
    {
        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                         std::bind(&MyNode::timerCallBack, this));
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    void timerCallBack()
    {
        RCLCPP_INFO(this->get_logger(), "Hello World");
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyNode>());
    rclcpp::shutdown();
    return 0;
}
