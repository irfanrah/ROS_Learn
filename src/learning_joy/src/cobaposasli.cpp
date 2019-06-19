#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"										// to get desired position command
#include "turtlesim/Pose.h"												// to read current position
#include "geometry_msgs/Twist.h"										// to send velocity command

// Function declarations
void ComPoseCallback(const geometry_msgs::Pose2D::ConstPtr& msg);
void CurPoseCallback(const turtlesim::Pose::ConstPtr& msg);

// Global variables
bool STOP = true;														// to hold stop flag, wait till first command given
turtlesim::Pose CurPose;												// to hold current pose
geometry_msgs::Pose2D DesPose;											// variable to hold desired pose

int main(int argc, char **argv)
{
	ros::init(argc, argv, "TurtlesimPositionController_pubsub");		// connect to roscore
	ros::NodeHandle n;													// node object
	
	// register sub to get desired position/pose commands
	ros::Subscriber ComPose_sub = n.subscribe("/turtle1/PositionCommand", 5, ComPoseCallback);
	// register sub to get current position/pose
	ros::Subscriber CurPose_sub = n.subscribe("/turtle1/pose", 5, CurPoseCallback);
	// register pub to send twist velocity (cmd_vel)
	ros::Publisher Twist_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
	
	ros::Rate loop_rate(10);											// freq to run loops in (10 Hz)
	
	ROS_INFO("Ready to send position commands");						// let user know we are ready and good
	while (ros::ok() && n.ok() )										// while ros and the node are ok
	{
		ros::spinOnce();
		if (STOP == false)												// and no stop command
		{
			printf("Processing...\n");
		}
		else
		{
			printf("Waiting...\n");
		}
		loop_rate.sleep();												// sleep to maintain loop rate
	}
}


// call back to send new desired Pose msgs
void ComPoseCallback(const geometry_msgs::Pose2D::ConstPtr& msg)			
{
	STOP = false;														// start loop
	DesPose.x = msg->x;													// copy msg to varible to use elsewhere
	DesPose.y = msg->y;
	return;
}

// call back to send new current Pose msgs
void CurPoseCallback(const turtlesim::Pose::ConstPtr& msg)			
{
	CurPose.x = msg->x;
	CurPose.y = msg->y;
	CurPose.theta = msg->theta;											// copy msg to varible to use elsewhere
	return;
}
