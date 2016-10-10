#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <orbus_interface/Peripheral.h>

orbus_interface::Peripheral msg_send;

/**
 * Subscriber GPIO messages
 */
void chatterCallback(const orbus_interface::Peripheral::ConstPtr& msg)
{
  if(msg.get()->gpio.at(0) == 1)
  {
      ROS_INFO_STREAM("High!");
  }
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  // Init Node handle
  ros::NodeHandle n;

  ros::Subscriber sub_gpio = n.subscribe("unav/peripheral", 1000, chatterCallback);
  ros::Publisher pub_gpio = n.advertise<orbus_interface::Peripheral>("unav/cmd_peripheral", 1000);

  ros::spin();

  return 0;
}
