#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node"); // 3 arg is the namo of node
  ros::NodeHandle n; // subscribe or another
  ros::Publisher pub = n.advertise<std_msgs::Int32>("/topic", 1000);

  ros::Rate loop_rate(1);
  int32_t input = 0;
  loop_rate.sleep();
  while (std::cin >> input){
    //std::cin.clear();
    //std::cin.ignore(INT_MAX,'\n');

    //std::cin >> input;
    std_msgs::Int32 msg;
    msg.data = input;
    pub.publish(msg);
    loop_rate.sleep();
    ros::spinOnce();

  }

  return 0;
}
