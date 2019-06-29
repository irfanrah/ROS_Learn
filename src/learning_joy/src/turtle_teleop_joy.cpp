#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "turtlesim/Pose.h"
#include <sensor_msgs/Joy.h>
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

using namespace std;
turtlesim::Pose turtlesim_pose;

class TeleopTurtle
 {
public:
	TeleopTurtle();
	void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
private:
	ros::NodeHandle nh_;
	int linear_, angular_;
	double l_scale_, a_scale_;
	ros::Subscriber joy_sub_;
  ros::Publisher vel_pub_;


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
void poseCallback(const turtlesim::Pose::ConstPtr & pose_message);

int main(int argc, char** argv)
 {

	ros::init(argc, argv, "turtle_teleop");
	TeleopTurtle teleop_turtle;
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);
  int count = 0;
  ros::Subscriber pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback); // mensubscribe isi dari turtle pose atau koordinat
  while (ros::ok()){
    std_msgs::String msg;
    std::stringstream ss;
    double ypos = turtlesim_pose.y; // data koordinat y
    double xpos = turtlesim_pose.x;
  	//ROS_INFO("y : %f",ypos);
    ss << "posisi x " << xpos << endl << "posisi y" << ypos << endl << endl;
    msg.data = ss.str();
    //ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
	ros::spin();
 }

 void poseCallback(const turtlesim::Pose::ConstPtr & pose_message){ // callback koordinat
 	turtlesim_pose.x=pose_message->x;
 	turtlesim_pose.y=pose_message->y;
 	turtlesim_pose.theta=pose_message->theta;
 }
