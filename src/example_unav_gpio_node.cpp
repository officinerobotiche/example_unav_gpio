#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <orbus_interface/Peripheral.h>

ros::Publisher pub_gpio;

/**
 * Subscriber GPIO messages
 */
void chatterCallback(const orbus_interface::Peripheral::ConstPtr& msg)
{
//    orbus_interface::Peripheral msg_send;

//    if(msg.get()->gpio.at(0) == 1)
//    {
//        ROS_INFO_STREAM("High!");
//    }
    int size = msg.get()->gpio.size();
    ROS_INFO_STREAM("Size: " << size);
//    for(unsigned i=0; i < msg.get()->gpio.size(); ++i)
//    {
//        ROS_INFO_STREAM("Data[" << i <<"]" << (int) msg.get()->gpio.at(i));
//    }
//    msg_send.gpio.resize(size);
//    msg_send.gpio.assign(size, 0);
//    msg_send.gpio.at(4) = msg.get()->gpio.at(0);

//    msg_send.header.stamp = ros::Time::now();
//    pub_gpio.publish(msg_send);
    pub_gpio.publish(msg);

    //ros::spinOnce();
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "example_gpio");
    // Init Node handle
    ros::NodeHandle n;

    ros::Subscriber sub_gpio = n.subscribe("/unav/peripheral", 1000, chatterCallback);
    pub_gpio = n.advertise<orbus_interface::Peripheral>("/unav/cmd_peripheral", 1000);

    ROS_INFO("------------ ROS GPIO CONTROLLER -----------");

    ros::spin();

    return 0;
}
