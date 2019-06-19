#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <sensor_msgs/Joy.h>
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

using namespace std;

class TeleopTurtle
 {
public:
	TeleopTurtle();
	ros::Publisher vel_pub_;
private:
	void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
	ros::NodeHandle nh_;
	int linear_, angular_;
	double l_scale_, a_scale_;
	ros::Subscriber joy_sub_;
	
 
 };


TeleopTurtle::TeleopTurtle():
linear_(1),
angular_(2)
{
nh_.param("axis_linear", linear_, linear_);
nh_.param("axis_angular", angular_, angular_);
nh_.param("scale_angular", a_scale_, a_scale_);
nh_.param("scale_linear", l_scale_, l_scale_);
 
 
vel_pub_ = nh_.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);

 
joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::joyCallback, this);

  
}
 
   void TeleopTurtle::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
 {
   geometry_msgs::Twist twist;
   twist.angular.z = a_scale_*joy->axes[angular_];
   twist.linear.x = l_scale_*joy->axes[linear_];
   vel_pub_.publish(twist);
  }


int main(int argc, char** argv)
 {
	
	ros::init(argc, argv, "s_turtle");
	ros::NodeHandle NH2;
	ros::Publisher chatter_pub = NH2.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(10);
	int count = 0;
	TeleopTurtle teleop_turtle;
	ros::Publisher PosisiPub = NH2.advertise<turtlesim::Pose>("/turtle1/pose", 1000);
	ros::Rate rate(2);
	turtlesim::Pose msg2;
	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		
		ss << "posisi x" << endl << msg2.y << endl ;
		msg.data = ss.str();
		PosisiPub.publish(msg2);
		//ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
	ros::spin();
 }
