#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
int main(int argc, char** argv)
{

    ros::init(argc, argv, "letterD");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    ros::Rate loop_rate(0.5);
    int count =0;
    int flag =0;
    while(ros::ok()&&count<5)
    {
        geometry_msgs::Twist msg;
        
        if(flag == 1)
        {
            msg.angular.z=0;
            msg.linear.x=3.81;
            flag =0;
        }
        else if(count%3==0)
        {
            msg.angular.z=1.57;
            msg.linear.x=0;
            flag =1;
        }
        else{
            msg.linear.x = 3;
            msg.angular.z = 1.57;
            flag =0;
        }
        if(count==0)
        {
            msg.angular.z=0;
            msg.linear.x=0;
            flag =0;
        }
        chatter_pub.publish(msg);
        ROS_INFO_STREAM("Count :"<< count <<" ,linear="<<msg.linear.x<<" angular="<<msg.angular.z);
        ros::spinOnce();
        loop_rate.sleep();
        
        count++;
    }
    return 0;
}