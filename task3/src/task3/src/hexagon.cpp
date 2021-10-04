#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
int main(int argc, char** argv)
{

    ros::init(argc, argv, "letterD");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    ros::Rate loop_rate(0.5);
    int count =0;
    
    while(ros::ok()&&count<12)
    {   
        geometry_msgs::Twist msg;
        if(count%2==0)
        {
        msg.linear.x = 0;
        msg.angular.z = 1.04;
        }
        else{
        msg.linear.x = 3;
        msg.angular.z = 0;
            
        }    
        chatter_pub.publish(msg);
        ROS_INFO_STREAM("Count :"<< count <<" ,linear="<<msg.linear.x<<" angular="<<msg.angular.z);
        ros::spinOnce();
        loop_rate.sleep();
        
        count++;
    }
    return 0;
}